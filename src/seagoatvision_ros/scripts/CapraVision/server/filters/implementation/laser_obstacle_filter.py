import rospy
from sensor_msgs.msg import LaserScan
import numpy as np
from math import sin, cos, isnan, pi
from CapraVision.server.filters.parameter import  Parameter
import cv2
from sensor_msgs.msg import PointCloud2
import sensor_msgs.point_cloud2 as pc2




class LaserObstacleFilter:
    def __init__(self):
        self.bottomy = Parameter("Bottom Y", 0,734,73)
        self.realy = Parameter("Real bottom y", 0, 654, 33)
        self.resolution = Parameter("Resolution", 0, 500, 20)
        self.scan = None
        self.size = (0, 0)
        self.res = (0, 0)
        self.trans = [0, 0]

        rospy.Subscriber('/scan_5m', LaserScan, self.handle_cloud)

    def execute(self, image):
        height, width = image.shape[:2]
        self.trans[0] = width / 2
        self.trans[1] = int(self.bottomy.get_current_value())
        self.res = width / 5.0, height / 5.0

        if self.scan is None:
            return image

        angles = np.arange(self.scan.angle_min, self.scan.angle_max, self.scan.angle_increment)

        current = []
        obstacles = []
        trans_real = np.array([self.trans[0], self.realy.get_current_value()])

        for i in range(len(angles)):
            angle = angles[i]
            r = self.scan.ranges[i]

            if isnan(r):
                if len(current) > 0:
                    obstacles.append(current)
                    current = []
            else:
                current.append(i)

        if len(current) > 0:
            obstacles.append(current)
            
        for obstacle in obstacles:
            a, b = obstacle[0], obstacle[-1]

            # filter out obstacles that are ~5 degrees wide
            
            if isnan(self.scan.ranges[a]) or isnan(self.scan.ranges[b]): continue
            if abs(angles[a] - angles[b]) < 0.0872664626: continue


            laser_height = 0.44
            obstacle_height = 1
            ang = 0.17
            
            dn_d = 0.08
            dn_1 = sin(angles[a] + 2 * pi) * dn_d
            dn_2 = sin(angles[a] + 2 * pi) * dn_d

            p1 = np.array([cos(angles[a] - ang + dn_1) * self.scan.ranges[a], sin(angles[a] - ang + dn_1) * self.scan.ranges[a]])
            p2 = np.array([cos(angles[b] + ang + dn_2) * self.scan.ranges[b], sin(angles[b] + ang + dn_2) * self.scan.ranges[b]])
            
            if np.any(np.isnan(p1)): continue
            if np.any(np.isnan(p2)): continue

            p1_m = self.meters_to_pixels(*p1)
            p2_m = self.meters_to_pixels(*p2)


            cv2.rectangle(image, (self.trans[0], self.trans[1]), (self.trans[0] + 10, self.trans[1] + 10), (0, 0, 255))
            cv2.rectangle(image, (int(trans_real[0]), int(trans_real[1])), (int(trans_real[0] + 10), int(trans_real[1] + 10)), (0, 255, 255))


            d1 = p1_m - trans_real
            d2 = p2_m - trans_real

            k = 5
            m1 = d1 * k + p1_m
            m2 = d2 * k + p2_m

            cv2.fillPoly(image, [np.array([
                p1_m.astype(int),
                m1.astype(int),
                m2.astype(int),
                p2_m.astype(int)
            ])], (0, 0, 0))

            for obs in obstacle:
                angle, r = angles[obs], self.scan.ranges[obs]

                if isnan(r): continue

                x, y = cos(angle) * r, sin(angle) * r
                px, py = self.meters_to_pixels(x, y)

                cv2.rectangle(image, (px, py), (px + 5, py + 5), (0, 255, 0))
                
                
            # cv2.line(image, tuple(self.meters_to_pixels(*p1)), tuple(self.meters_to_pixels(*p2)), (0, 0, 255))

            # cv2.line(image, tuple(p1_m.astype(int)), tuple(m1.astype(int)), (0, 255, 0))
            # cv2.line(image, tuple(p2_m.astype(int)), tuple(m2.astype(int)), (0, 255, 0))

            # cv2.line(image, tuple(trans_real.astype(int)), tuple(self.meters_to_pixels(*p1)), (0, 255, 0))
            # cv2.line(image, tuple(trans_real.astype(int)), tuple(self.meters_to_pixels(*p2)), (0, 255, 0))
            
            # cv2.line(image, tuple(map(int, self.trans)), tuple(self.meters_to_pixels(*p1).astype(int)), (0, 255, 0))

            # cv2.rectangle(image, p1_pix, (p2_pix[0], p2_pix[1] + 5), (255, 0, 0), -1)


#             points = [
#                 self.meters_to_pixels(p1[0], p1[1] - laser_height),
#                 self.meters_to_pixels(p2[0], p2[1] - laser_height),
#                 self.meters_to_pixels(p2[0], p2[1] + obstacle_height),
#                 self.meters_to_pixels(p1[0], p1[1] + obstacle_height),
#             ]


   
        return image
        
    def handle_cloud(self, msg):
        self.scan = msg

    def meters_to_pixels(self, x, y):
        # 1.255 distance du robot du tf /image
        return np.array([int(self.trans[0] - y * self.res[0]), int(self.trans[1] - x * self.res[1] + 1.255 * self.res[1])])

        



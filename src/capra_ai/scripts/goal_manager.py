#!/usr/bin/env python

import rospy
from geometry_msgs.msg import PoseStamped, PointStamped, Quaternion
from actionlib_msgs.msg import GoalStatusArray, GoalStatus
from move_base_msgs.msg import MoveBaseActionGoal


class GoalManager():

    def __init__(self):
        self.goals = []
        self.counter = 0
        rospy.Subscriber("~waypoint", PoseStamped, self.pose_received)  # receive goals from other nodes
        rospy.Subscriber("/clicked_point", PointStamped, self.point_received)  # rviz goals
        rospy.Subscriber("/move_base/status", GoalStatusArray, self.status_updated)  # track status of goals
        self.goal_pub = rospy.Publisher("/move_base/goal", MoveBaseActionGoal, queue_size=10)
        self.loop()

    def loop(self):
        rate = rospy.Rate(10)
        # wait for the first goal, because the publisher waits for a success to publish the next one
        self.waitforgoal()
        self.nextgoal()
        self.nextgoal()
        while not rospy.is_shutdown():
            rate.sleep()

    def waitforgoal(self):
        rate = rospy.Rate(10)
        while len(self.goals) == 0:
            rate.sleep()
    def nextgoal(self, idx = 0):
        if len(self.goals) > idx:
            self.goal_pub.publish(self.goals[idx])
    def addwaypoint(self, pose):  # PoseStamped
        now = rospy.get_rostime()
        self.counter = self.counter + 1
        msg = MoveBaseActionGoal()
        msg.goal.target_pose = pose
        msg.goal_id.stamp = now
        # id format is "[node_name]_[goal_count]_[time]"
        msg.goal_id.id = "%s_%i_%i_%i" % (rospy.get_name(), self.counter, now.secs, now.nsecs)
        self.goals.append(msg)

    def index(self, goal_id):
        for idx, obj in enumerate(self.goals):
            if obj.goal_id.id == goal_id:
                return idx
        return -1

    def status_updated(self, msg):  # GoalStatusArray
        intermediate_statuses = [GoalStatus.PENDING, GoalStatus.ACTIVE, GoalStatus.RECALLING, GoalStatus.PREEMPTING]
        for goal in msg.status_list:
            goal_idx = self.index(goal.goal_id.id)
            # self.printlist()
            if goal.status == GoalStatus.SUCCEEDED:  # do a little dance to celebrate
                self.waitforgoal()
                self.nextgoal(goal_idx + 1)
            elif goal.status in intermediate_statuses:  # transitional state, so just wait
                pass
            else:  # the robot's dead
                rospy.logerr("Goal invalidated. Goal status number: %i" % goal.status)
    def pose_received(self, msg):  # PoseStamped
        self.addwaypoint(msg)
    def point_received(self, msg):  # PointStamped
        pose_msg = PoseStamped()
        pose_msg.header = msg.header
        pose_msg.pose.position = msg.point
        pose_msg.pose.orientation = Quaternion(w = 1)  # could be changed to the robot's current orientation
        self.addwaypoint(pose_msg)
    def point_received(self, msg):  # msg is PointStamped
        pose = PoseStamped()
        pose.header = msg.header
        pose.pose.position = msg.point
        pose.pose.orientation = Quaternion(w = 1)
        self.addwaypoint(pose)

    def status_updated(self, msg):
        rospy.logwarn("%i statuses in list vs %i goals in list" % (len(msg.status_list), len(self.goals)))
        for goalstatus in msg.status_list:
            status = goalstatus.status
            if status == GoalStatus.SUCCEEDED:
                rospy.logwarn("Goal succeeded, passing to next goal")
                self.nextgoal()
            elif status == GoalStatus.ACTIVE or status == GoalStatus.PENDING:
                pass  # don't care, keep going
            #elif status == GoalStatus.PREEMPTED or status == GoalStatus.PREEMPTING:
            #    rospy.logwarn("Je fais ce que je veux!")
            else:
                rospy.logerr("Goal invalidated. Goal status code: %i" % status)


if __name__ == '__main__':
    rospy.init_node('goal_manager')
    try:
        GoalManager()
    except rospy.ROSInterruptException: pass

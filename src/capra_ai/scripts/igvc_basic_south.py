#! /usr/bin/env python

from state_ai import StateAi
import rospy
from math import pi
from std_msgs.msg import Bool

class IGVCBasicSouth(StateAi):

    def __init__(self):
         super(IGVCBasicSouth, self).__init__("igvc_basic_south")

    def on_start(self):
        self.generate_circle(7.0, pi/4, 2 * pi - pi/4, pi/270.0, -1)
        self.send_goal_ahead(10)

    def on_goal_changed(self, goal_msg):
        rospy.loginfo("Targeting goal with priority: {}".format(goal_msg.priority))

        rospy.sleep(2)
        self.send_goal_ahead(10)

        if goal_msg.priority == 302:
            self.clear_octomap(self.start_pos, 10, 10)

        if goal_msg.priority == 103: ## First GOAL
            pass

        if goal_msg.priority == 304: ## MiddlePoint
            pass

        if goal_msg.priority == 105: ## Last GOAL
            pass

        if goal_msg.priority == 306:
            self.generate_bar(8, 2, -1)

    def on_last_goal_reached(self, msg):
        pass

if __name__ == "__main__":
    try:
        a = IGVCBasicSouth()
    except rospy.ROSInterruptException:
        pass
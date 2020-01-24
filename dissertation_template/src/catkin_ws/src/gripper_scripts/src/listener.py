#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
import sys, select, termios, tty
from std_msgs.msg import Int32

def callback(data):
	rospy.loginfo(rospy.get_caller_id()+ "I have heard "+str( data))

def listener():
        
	rospy.init_node('listener', anonymous=True)
	rospy.Subscriber("cmd_vel", Int32, callback)
	rospy.spin()

if __name__ == '__main__':
	listener()
	

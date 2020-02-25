#!/usr/bin/env python

from __future__ import print_function
from std_msgs.msg import Int8
from std_msgs.msg import Int16
from std_msgs.msg import String

import roslib; roslib.load_manifest('teleop_twist_keyboard')
import rospy
# from tkinter import *

import sys, select, termios, tty

msg = """
Reading from the keyboard
Publishing to Motor. 
Ensure correct configuration for motor has been set in 
teleop_twist_keyboard.py
---------------------------

o : open (+x)
p : close (-x)

anything else : nothing/stops rotation

CTRL-C to quit
"""

moveBindings = {
        'o':10,
        'p':-10,

    }



def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


if __name__=="__main__":
    settings = termios.tcgetattr(sys.stdin)
    pubRotate = rospy.Publisher('cmd_vel', Int16, queue_size = 1)
    rospy.init_node('teleop_twist_keyboard')
    x = 0
    total = 0
    try:
        print(msg)
        while(1):
            key = getKey()
            if key in moveBindings.keys():
                x = moveBindings[key]
            	total += x
	    else:
                x = 0
                if (key == '\x03'):
                    break
	    #rospy.loginfo("Key has value: "+str(x))
	    pubRotate.publish(total)		#For Servo Motor
            #pubRotate.publish(x)		#For Dynamixel Motor
    except Exception as e:
        print(e)

    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)

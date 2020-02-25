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

def getMotorType():
	correctInput = False
	while not correctInput:
	    motorType = raw_input("Please enter motor type:\n For Stepper: st, For Servo: sv \n")
	    motorType=motorType.lower()
	    if(motorType=="sv" or motorType=="st"):
		correctInput=True
	    else:
		print("Unrecognised motor type, please try again!")
	return motorType


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
	motorType = getMotorType()
        print(msg)
        while(1):
            key = getKey()
            if key in moveBindings.keys():
                x = moveBindings[key]
		if motorType=="sv":
		    if total > 150 :
			total = 150
		    elif total < 0: #If servo motor, don't go out of 180 degree bounds
            		total = 0
		    else:
			total += x
				
	    else:
                x = 0
                if (key == '\x03'):
                    break
	    if motorType=="sv":
		print("Servo trying to turn to angle: "+ str(total))
		pubRotate.publish(total)
	    elif motorType=="st":
	        print("Servo trying to turn in direction: "+ str(x))
            	pubRotate.publish(x)		
    except Exception as e:
        print(e)

    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)

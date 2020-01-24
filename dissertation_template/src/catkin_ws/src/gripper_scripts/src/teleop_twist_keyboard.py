#!/usr/bin/env python

from __future__ import print_function
from std_msgs.msg import Int32

import roslib; roslib.load_manifest('teleop_twist_keyboard')
import rospy


import sys, select, termios, tty

msg = """
Reading from the keyboard  and Publishing to Twist!
---------------------------

o : open (+x)
p : close (-x)

anything else : nothing

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

    pub = rospy.Publisher('cmd_vel', Int32, queue_size = 1)
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
		rospy.loginfo("Total Pos value is: "+str(total))
	    else:
                x = 0
                if (key == '\x03'):
                    break

            pub.publish(total)

    except Exception as e:
        print(e)

    finally:
        pub.publish(total)

        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)

# Readme

Put a brief description of your code here. This should at least describe the file structure.

## Build instructions
###############################################################

It is assumed that ROS has been installed and configured on your computer already. 
If this isn't the case, please carefully follow the instructions here -->
http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment

Once this is completed, please copy the files found at 
/src/catkin_ws

Paste into your catkin_ws folder and run commands 
$  cd ~/catkin_ws
$  catkin_make
$  . ~/catkin_ws/devel/setup.bash

###############################################################

Assuming you have already installed Arduino and have an Arduino sketchbook.
Run following commands to install ros libraries for arduino 
(Replace DISTRO with whatever ROS version you're using (e.g. melodic)--

$  sudo apt-get install ros-<DISTRO>-rosserial-arduino
$  sudo apt-get install ros-<DISTRO>-rosserial
  
$  cd <ws>/src
$  git clone https://github.com/ros-drivers/rosserial.git
$  cd <ws>
$  catkin_make
$  catkin_make install

$  cd <sketchbook>/libraries
$  rm -rf ros_lib
$  rosrun rosserial_arduino make_libraries.py .

To check it has worked correctly, restart Arduino IDE, go to File/Examples amd you should see ros_lib.
Now copy the files found (excluding "libraries") in dissertation_template/src/Arduino into your sketchbook folder.

#################################################################

If planning on using a stepper motor as discussed in the report, you must first use the TicGUI. 
This can be found in the /src folder. 
navigate to this folder and run the command-

$  sudo pololu-tic-*/install.sh

Then running
$  ticcmd --list
with your stepper motor connected with the Tic T500 and the computer, you should then see that it is recognised on the computer.

e.g. $ ticcmd --list
     00259450,         Tic T500 Stepper Motor Controller

#################################################################

### Requirements

List the all of the pre-requisites software required to set up your project (e.g. compilers, packages, libraries, OS, hardware)


* Python 3.7
* Packages: listed in `requirements.txt` 
* Tested on Ubuntu but should work on most linux Distros that support ROS.
* Requires Arduino Yun

or another example:

* Requires Raspberry Pi 3 
* a Linux host machine with the `arm-none-eabi` toolchain (at least version `x.xx`) installed
* a working LuaJIT installation > 2.1.0
###############################################################
### Build steps
Setup required

Terminal Commands (In seperate terminal tabs)
$  roscore
$  roslaunch teleop_twist_keyboard gripper.launch

#################################################################

These are the commands to run the two nodes separately, instead of running them together using the launch package.

command should run both together.
$  rosrun teleop_twist_keyboard teleop_twist_keyboard.py 
$  rosrun rosserial_python serial_node.py /dev/ttyACM0

#################################################################

Arduino Setup
For Servo Motor
-- VDD to 5vPin
-- GND to GNDpin
-- Data to pin9
#################################################################

Stepper Motor Setup
Stepper Motor to TIC T500
-- Blue to B2
-- Red to B1
-- Black to A1
-- Green to A2

TIC T500 to Arduino
-- SDA/AN to ArduinoPin10
-- GND to ArduinoGND


* Must be setup first using the TicGUI.
Run:
$  ticgui

* This will open up the Ticgui, which can be used to read values from the stepper motor and perform configurations. 
* Moving to the "Input and motor settings" tab, change the control mode to Analog Speed. 
* Click Apply Settings
* On the RC and Analog Scaling box, set values: 
-- Maximum: 4095
-- Neutral Max: 3500
-- Neutral Min: 500
-- Minimum: 50
-- Maximum Target : 2000000
-- Minimum Target : -2000000
* Apply settings, resume. 
* Motor is then ran with the same commands as the Servo. 


### Test steps

List steps needed to show your software works. This might be running a test suite, or just starting the program; but something that could be used to verify your code is working correctly.

Examples:

* Run automated tests by running `pytest`
* Start the software by running `bin/editor.exe` and opening the file `examples/example_01.bin`







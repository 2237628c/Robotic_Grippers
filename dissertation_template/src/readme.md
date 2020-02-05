# Readme

Put a brief description of your code here. This should at least describe the file structure.

## Build instructions
It is assumed that ROS has been installed and configured on your computer already. 
If this isn't the case, please carefully follow the instructions here -->
http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment

Once this is completed, please copy the files found at dissertation_template/src/catkin_ws
Paste into your catkin_ws folder and run commands 
  cd ~/catkin_ws
  catkin_make
  . ~/catkin_ws/devel/setup.bash


Assuming you have already installed Arduino and have an Arduino sketchbook.
Run following commands to install ros libraries for arduino 
(Replace DISTRO with whatever ROS version you're using (e.g. melodic)--

  sudo apt-get install ros-<DISTRO>-rosserial-arduino
  sudo apt-get install ros-<DISTRO>-rosserial
  
  cd <ws>/src
  git clone https://github.com/ros-drivers/rosserial.git
  cd <ws>
  catkin_make
  catkin_make install

  cd <sketchbook>/libraries
  rm -rf ros_lib
  rosrun rosserial_arduino make_libraries.py .

To check it has worked correctly, restart Arduino IDE, go to File/Examples amd you should see ros_lib.
Now copy the files found (excluding "libraries") in dissertation_template/src/Arduino into your sketchbook folder. 


**You must** include the instructions necessary to build and deploy this project successfully. If appropriate, also include 
instructions to run automated tests. 

### Requirements

List the all of the pre-requisites software required to set up your project (e.g. compilers, packages, libraries, OS, hardware)

For example:

* Python 3.7
* Packages: listed in `requirements.txt` 
* Tested on Windows 10

or another example:

* Requires Raspberry Pi 3 
* a Linux host machine with the `arm-none-eabi` toolchain (at least version `x.xx`) installed
* a working LuaJIT installation > 2.1.0

### Build steps
Terminal Commands (In seperate terminal tabs)
roscore
roslaunch teleop_twist_keyboard gripper.launch

These are the commands to run the two nodes separately, however roslaunch 
command should run both together.
---rosrun teleop_twist_keyboard teleop_twist_keyboard.py 
---rosrun rosserial_python serial_node.py /dev/ttyACM0

Arduino Setup
For Servo Motor
-- VDD to 5vPin
-- GND to GNDpin
-- Data to pin9

For Dynamixel Motor
-- VDD to 12V supply
-- GND to GND of 12v supply
-- Data to Pin2 (I think atm)

List the steps required to build software. 

Hopefully something simple like `pip install -e .` or `make` or `cd build; cmake ..`. In
some cases you may have much more involved setup required.

### Test steps

List steps needed to show your software works. This might be running a test suite, or just starting the program; but something that could be used to verify your code is working correctly.

Examples:

* Run automated tests by running `pytest`
* Start the software by running `bin/editor.exe` and opening the file `examples/example_01.bin`







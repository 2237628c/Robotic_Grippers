cmake_minimum_required(VERSION 2.8.3)
project(gripper_ui)


find_package(catkin REQUIRED COMPONENTS)



###################################
## catkin specific configuration ##
###################################
catkin_package()

###########
## Build ##
###########
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS
   gripper_ui.py
   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)


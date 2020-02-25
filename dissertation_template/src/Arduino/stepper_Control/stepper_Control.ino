#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#define USE_USBCON
#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <stdio.h>
#include <unistd.h>

const int drivePin = 10;
ros::NodeHandle  nh;
void servo_cb( const std_msgs::Int16& cmd_msg){
  if(cmd_msg.data < 0){ //gripper will close
    analogWrite(drivePin, 255);
  }else if(cmd_msg.data > 0){ //gripper will open
    analogWrite(drivePin, 0);
  }else{
    analogWrite(drivePin, 127);
  }
  
 }

ros::Subscriber<std_msgs::Int16> sub("cmd_vel", servo_cb);
void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(1);
}

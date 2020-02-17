#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#define USE_USBCON

#include <ros.h>
#include <std_msgs/Int16.h>
#include <stdio.h>
#include <unistd.h>
#define LED13 0x0D
ros::NodeHandle  nh;
const int drivePin = 9;


void servo_cb( const std_msgs::Int16& cmd_msg){
  if(cmd_msg.data > 0){
    analogWrite(drivePin, 255);
  }else if(cmd_msg.data < 0){
    analogWrite(drivePin, 0);
  }else{
    analogWrite(drivePin, 127);
  }
}
ros::Subscriber<std_msgs::Int16> sub("cmd_vel", servo_cb);
void setup() {
  nh.initNode();
  nh.subscribe(sub);
  pinMode(drivePin, OUTPUT);
  analogWrite(drivePin, 127);
}

void loop() {
  nh.spinOnce();
  delay(10);
}

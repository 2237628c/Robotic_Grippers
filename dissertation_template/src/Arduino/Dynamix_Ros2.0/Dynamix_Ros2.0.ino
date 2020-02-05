/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#define USE_USBCON
#include <Dynamixel_Serial.h>       // Library needed to control Dynamixal servo

#include <ros.h>
#include <std_msgs/Int16.h>
#include <stdio.h>
#include <unistd.h>

#define SERVO_ID 0x01               // ID of which we will set Dynamixel too 
#define SERVO_ControlPin 0x02       // Control pin of buffer chip, NOTE: this does not matter becasue we are not using a half to full contorl buffer.
#define SERVO_SET_Baudrate 100000  // Baud rate speed which the Dynamixel will be set too (1Mbps)
#define LED13 0x0D                  // Pin of Visual indication for runing "heart beat" using onboard LED


ros::NodeHandle  nh;


void servo_cb( const std_msgs::Int16& cmd_msg){
  if(cmd_msg.data > 0){
    Serial.println("WHEELING RIGHT");
    Dynamixel.wheel(SERVO_ID,RIGHT,0x3FF);
  }else if(cmd_msg.data < 0){
    Serial.println("WHEELING RIGHT");
    Dynamixel.wheel(SERVO_ID,LEFT,0x3FF);
  }else{
    Dynamixel.wheel(SERVO_ID,RIGHT,0x000);
  }
}


ros::Subscriber<std_msgs::Int16> sub("cmd_vel", servo_cb);


void setup(){
  nh.initNode();
  nh.subscribe(sub);
  Dynamixel.begin(57600,SERVO_ControlPin);                 // Set Ardiuno Serial speed to factory default speed of 57600
  Dynamixel.setID(0xFE,SERVO_ID);
  delay(15);
  Dynamixel.begin(SERVO_SET_Baudrate,SERVO_ControlPin);
  Dynamixel.ledState(SERVO_ID, ON);
  delay(5);
  Dynamixel.setMode(SERVO_ID, WHEEL,0x000,0xFFF);              // Turn mode to SERVO, must be WHEEL if using wheel mode
}

void loop(){
  nh.spinOnce();
  delay(10);
}

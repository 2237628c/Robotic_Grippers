#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#define USE_USBCON
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <stdio.h>
#include <unistd.h>

ros::NodeHandle  nh;
Servo servo;
const int drivePin = 9;

/*
 *Motor type, 
 * True= Servo
 * False = Stepper Motor
 */
bool motorType;


void motor_set( const std_msgs::Int8& cmd_type){
    if(cmd_type.data==1){
       motorType = false;
    }else if(cmd_type.data==2){
      motorType = true;
    }
}


void servo_cb( const std_msgs::Int16& cmd_msg){
  if(motorType==true){
    servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  }else{
    if(cmd_msg.data > 0){
      analogWrite(drivePin, 255);
    }else if(cmd_msg.data < 0){
      analogWrite(drivePin, 0);
    }else{
      analogWrite(drivePin, 127);
    }
  }
 }

 
ros::Subscriber<std_msgs::Int16> subSpin("cmd_vel", servo_cb);
ros::Subscriber<std_msgs::Int8> subMotor("motor_type", motor_set);
void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.subscribe(subSpin);
  nh.subscribe(subMotor);
  
  servo.attach(9); //attach it to pin 9
}

void loop() {
  // put your main code here, to run repeatedly:

}

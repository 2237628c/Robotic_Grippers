#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <Dynamixel_Serial.h>       // Library needed to control Dynamixal servo
#include <ros.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>

#define SERVO_ID 0x01               // ID of which we will set Dynamixel too
#define SERVO_ControlPin 0x02       // Control pin of buffer chip, NOTE: this does not matter becasue we are not using a half to full contorl buffer.
#define SERVO_SET_Baudrate 100000  // Baud rate speed which the Dynamixel will be set too (1Mbps)
#define USE_USBCON


ros::NodeHandle  nh;
Servo servo;
void servo_cb(const std_msgs::Int16& cmd_msg, const std_msgs::Int8& motor_type) {
  // put your setup code here, to run once:
  //Serial.print(motor_type.data);
  if(motor_type.data == 1){
    //Serial.print("In Dynamixel Section");
    if(cmd_msg.data > 0){
      Dynamixel.wheel(SERVO_ID,LEFT,0x3FF);
    }else if(cmd_msg.data < 0){
      Dynamixel.wheel(SERVO_ID,RIGHT,0x200);
    }else{
      Dynamixel.wheel(SERVO_ID,RIGHT,0x000);
    }    
  }else if(motor_type.data == 2){
    //Serial.print("In Servo Section");
    servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  }
}
ros::Subscriber<std_msgs::Int16> subRotate("cmd_vel", servo_cb);
ros::Subscriber<std_msgs::Int8> subMotorType("motor_type", servo_cb);

void setup(){
  nh.initNode();
  nh.subscribe(subRotate);
  nh.subscribe(subMotorType);
  delay(1000);//To let Dynamixel Power On
  servo.attach(9);
  Dynamixel.begin(57600,SERVO_ControlPin);                 // Set Ardiuno Serial speed to factory default speed of 57600
  Dynamixel.setID(0xFE,SERVO_ID);
  delay(15);
  Dynamixel.begin(SERVO_SET_Baudrate,SERVO_ControlPin);
  delay(5);
  Dynamixel.setMode(SERVO_ID, WHEEL,0x000,0xFFF);   
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(1);
}

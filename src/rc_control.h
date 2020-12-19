#include<Arduino.h>

#ifndef RC_CONTROL_H
#define RC_CONTROL_H

const int MOTOR1 = D0;
const int MOTOR2 = D1;
const int MOTOR3 = D2;
const int MOTOR4 = D3;
const int HORN = D8;

int frequency=2000; //Specified in Hz
bool DEBUG =false;

const int COUNT_START=1000;


void MotorWrite(int motor,int value) {
    if(digitalRead(motor)!=value)
        digitalWrite(motor,value);
}

/*void printRead(){
  Serial.println("D1=");
  Serial.println(digitalRead(D1));
  Serial.println("D2=");
  Serial.println(digitalRead(D2));
  Serial.println("D3=");
  Serial.println(digitalRead(D3));
  Serial.println("D5=");
  Serial.println(digitalRead(D5));
  Serial.println("D8=");
  Serial.println(digitalRead(D8));
}*/

void RC_Controller_setUp(){
   pinMode(MOTOR1, OUTPUT);
   pinMode(MOTOR2, OUTPUT);
   pinMode(MOTOR3, OUTPUT);
   pinMode(MOTOR4, OUTPUT);
   pinMode(HORN, OUTPUT);
   delay(10);  
   digitalWrite(MOTOR1, LOW);
   digitalWrite(MOTOR2, LOW);
   digitalWrite(MOTOR3, LOW);
   digitalWrite(MOTOR4, LOW);
   digitalWrite(HORN,LOW);
   delay(10);
}


void rc_control(char *data){
 
  if(data[0]=='T'){
    if(DEBUG) Serial.println("-------------------------LEFT");
    MotorWrite(MOTOR1, HIGH);
  } else {
    //Serial.println("-------------------------LEFT        XXXXXXX");
    MotorWrite(MOTOR1, LOW);
  }

 if(data[1]=='T'){
    if(DEBUG) Serial.println("-------------------------RIGHT");
    MotorWrite(MOTOR2, HIGH);
  } else {
    //Serial.println("-------------------------RIGHT        XXXXXXX");
    MotorWrite(MOTOR2, LOW);
  }


 if(data[2]=='T'){
   if(DEBUG) Serial.println("-------------------------UP");
    MotorWrite(MOTOR3, HIGH);
  } else {
   //Serial.println("-------------------------UP        XXXXXXX");
    MotorWrite(MOTOR3, LOW);
  }
 if(data[3]=='T'){
  if(DEBUG) Serial.println("-------------------------DOWN");
    MotorWrite(MOTOR4, HIGH);
 } else {
   // Serial.println("-------------------------DOWN        XXXXXXX");
    MotorWrite(MOTOR4, LOW);
 }

 if(data[4]=='T'){
    if(DEBUG) Serial.println("HORN<<<<<<<<<<");
    tone(HORN, frequency);
 } else {
    if(DEBUG) Serial.println("HORN>>>>>>>>>> OFF");
    noTone(HORN);
 }
}


void TurnOffAllMotors(){
    if(DEBUG) Serial.println("Turning off All Motors");
     digitalWrite(MOTOR1, LOW);
     digitalWrite(MOTOR2, LOW);
     digitalWrite(MOTOR3, LOW);
     digitalWrite(MOTOR4, LOW);
     noTone(HORN);
}

#endif
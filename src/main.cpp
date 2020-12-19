#include <ESP8266WiFi.h>
#include <WiFiUDP.h>
#include<string.h>
#include "rc_control.h"
#include "wifi_connection.h"

/*
const char* ssid = "Sampu"; //your WiFi Name
const char* pw = "12345678";  //Your Wifi Password
*/

char* ssid = "DreamBox"; //your hotspot Name
char* pw = "7278586370";  //Your hotspot Password


int BAUD_RATE=9600;

char data[7] ={};
int packetsize = 0;
String receiveddata="";

WiFiUDP Server;
unsigned int localServerPort = 7800;  // local port to listen on
char incomingPacket[7]={};  // buffer for incoming packets

void setup() {
   
  RC_Controller_setUp();  
  Serial.begin(BAUD_RATE);
 
  Wifi_connect(ssid,pw);
  Server.begin(80);

  Server.begin(localServerPort);
  Serial.println("\n\nServer started...");
}

unsigned long lastTime;

void loop() {
  //rc_check();
  int packetSize = Server.parsePacket();
  if (packetSize)
  {
    lastTime=millis();
    //Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Server.remoteIP().toString().c_str(), Server.remotePort());
    int len = Server.read(incomingPacket, 7);
    if (len > 0)
    {
      incomingPacket[len] = '\0';
    }
    rc_control(incomingPacket);
    //printRead();
    Serial.printf("UDP packet contents: %s\n", incomingPacket);
  } else {
    if( (millis()-lastTime)>500){
      TurnOffAllMotors();
      lastTime=millis();
    }
  }
  incomingPacket[0]='\0';
  incomingPacket[1]='\0';
  incomingPacket[2]='\0';
  incomingPacket[3]='\0';
  incomingPacket[4]='\0';
  incomingPacket[5]='\0';
  incomingPacket[6]='\0';
  
 // Serial.flush();
  //if(millis()%10==0)//print data every 100milis
  //  Serial.printf("l%d r%d u%d d%d h%d \n",cl,cr,cu,cd,ch);
  /*
  if (WiFi.status() != WL_CONNECTED) 
  {
    TurnOffAllMotors();
     WiFi.begin(ssid, pw);
     while (WiFi.status() != WL_CONNECTED) 
     {
         delay(500);
         Serial.print("-");
     }
      Serial.print("The IP Address of ESP8266 Module is: ");
      Serial.print(WiFi.localIP());// Print the IP address
  }*///-------------------------------------------------------------For Wifi connection to controller
}



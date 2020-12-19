#ifndef WIFICTL_H
#define WIFICTL_H

#include<ESP8266WiFi.h>
#include<Arduino.h>
#include<ESP8266WiFiAP.h>

 //--------------------------------------------------------------------- Connect to WiFi
void Wifi_connect(char* ssid,char* pw) {
    WiFi.begin(ssid, pw);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print("-");
  }
  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address
}

/*
void Wifi_hotspot_connect(char* ssid,char* pw) {
    //--------------------------------------------------------------------- Create Wifi hotspot
  delay(10); 
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,pw,11);
  WiFi.begin();
  delay(10); 
  Serial.println("\n\nAP started at: ");
  Serial.print(WiFi.softAPIP());
  while (WiFi.softAPgetStationNum()==0) 
  {
    delay(100);
    Serial.print(".");
  }
}
*/
#endif
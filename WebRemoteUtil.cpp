#include "WebRemoteUtil.h"

void connectToWiFi() {
  
  IPAddress ip STATIC_IP; // where xx is the desired IP Address
  IPAddress gateway GATEWAY; // set gateway to match your network
  IPAddress subnet SUBNET_MASK; // set subnet mask to match your network
  
  //Print static IP-Address
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
 
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.config(ip, gateway, subnet); 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");

}

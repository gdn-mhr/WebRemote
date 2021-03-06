#ifndef WEBREMOTECONFIG_H
#define WEBREMOTECONFIG_H

  /*
   * This is an example of how your config file should look like.
   * Please go through the TODOs and fill them up.
   * Use certbot in standalone mode to generate your certificate.
   * When finished, rename the file to "WebRemoteConfig.h"
   */
  
  static const char serverCert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
//TODO: INSERT YOUR CERTIFICATE HERE
-----END CERTIFICATE-----
)EOF";
  
      static const char serverKey[] PROGMEM =  R"EOF(
-----BEGIN PRIVATE KEY-----
//TODO: INSERT YOUR PRIVATE KEY HERE
-----END PRIVATE KEY-----
)EOF";
  
  static const char* const ssid = "wifi"; //TODO: SSID
  static const char* const password = "123456"; //TODO: WIFI PASSWORD
  
  #define IR_LED D2 //TODO: PIN OF IR LED (Default on Wemos D1: D2)
  
  #define STATIC_IP (192, 168, XXX, XXX) //TODO: SET PREFERRED IP ADDRESS 
  #define GATEWAY (192, 168, XXX, XXX) //TODO: SET LOCAL GATEWAY
  #define SUBNET_MASK (255, 255, 255, 0)
  
  #define REDIRECT_URL "https://example.com/webinterface.html"

#endif

#ifndef WEBREMOTEUTIL_H
#define WEBREMOTEUTIL_H

  #include <Arduino.h>
  #include <ESP8266WiFi.h>

  #include "WebRemoteConfig.h"

  void connectToWiFi();
  constexpr unsigned int str2int(const char* str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
  }

#endif

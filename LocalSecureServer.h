#ifndef LOCALSECURESERVER_H
#define LOCALSECURESERVER_H

	#include <ESP8266WiFi.h>
	#include <ESP8266WebServerSecure.h>
	#include <Arduino.h>
  #include <queue>
  #include "Event.h"
  
  #include "WebRemoteConfig.h"

  class LocalSecureServer {
    private:
      BearSSL::ESP8266WebServerSecure server;
      std::queue<Event*>* eventqueue;
    public:
      LocalSecureServer(){}
      LocalSecureServer(std::queue<Event*>* eventqueue);
      void startServer();
      void handleRequest();
  };

#endif

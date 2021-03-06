#ifndef LOCALSECURESERVER_H
#define LOCALSECURESERVER_H

	#include <ESP8266WiFi.h>
	#include <ESP8266WebServerSecure.h>
	#include <DNSServer.h>
	#include <Arduino.h>
  #include <queue>
  
  #include "WebRemoteConfig.h"

  class LocalSecureServer {
    private:
      BearSSL::ESP8266WebServerSecure server;
      ESP8266WebServer serverHTTP;
      DNSServer dnsServer;
      std::queue<String>* eventqueue;
    public:
      LocalSecureServer(){}
      LocalSecureServer(std::queue<String>* eventqueue);
      void startServer();
      void secureRedirect();
      void handleRequest();
  };

#endif

#include "LocalSecureServer.h"

LocalSecureServer::LocalSecureServer(std::queue<Event*>* eventqueue) : server(443) {
  this->eventqueue = eventqueue;
}


void LocalSecureServer::startServer() {
  Serial.println("Configuring Server");
  server.getServer().setRSACert(new BearSSL::X509List(serverCert), new BearSSL::PrivateKey(serverKey));
  server.on("/", [this](){
    server.send(200, "text/plain", "Hello world!");
  });

  server.on("/trigger/", [this](){
    String button = server.arg("value");
    this->eventqueue->push(new Event(button));
    server.sendHeader("Location", String(REDIRECT_URL), true);
    server.send(301, "text/plain", "");
  });

  
  server.on("/makro/", [this](){
    String button = server.arg("value");
    String modifier = server.arg("modifier");
    this->eventqueue->push(new Event(button, modifier));
    server.sendHeader("Location", String(REDIRECT_URL), true);
    server.send(301, "text/plain", "");
  });
  
  server.begin();
  Serial.println("HTTPS server started");
}

void LocalSecureServer::handleRequest() {
  server.handleClient();
}

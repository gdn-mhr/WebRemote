#include "WebRemote.h"

std::queue<Event*> eventqueue;
LocalSecureServer server(&eventqueue);
LGRemote remote (&eventqueue);

void setup() {
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  delay(100);
 
  connectToWiFi();
  server.startServer();
  remote.startRemote();
}

void loop() {
  server.handleRequest();
  remote.handleEvent();
}

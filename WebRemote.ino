/* Boards:
 * - WeMos D1 R1 * esp8266:esp8266:d1:baud=921600,xtal=160,eesz=4M2M,dbg=Disabled,lvl=None____,ip=hb2f,vt=flash,exception=legacy,wipe=none,ssl=all,CONSOLEBAUD=115200
 */
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

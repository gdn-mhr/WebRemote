#ifndef LGREMOTE_H
#define LGREMOTE_H

  #include <Arduino.h>
  
  #include <IRremoteESP8266.h>
  #include <IRsend.h>
  
  #include <queue>
  #include "Event.h"

  #include "WebRemoteUtil.h"
  #include "WebRemoteConfig.h"
  #include "LG.h"
  
  class LGRemote {
    private:
      IRsend irsend;
      std::queue<Event*>* eventqueue;
    public:
      LGRemote(std::queue<Event*>* eventqueue);
      void startRemote();
      bool handleEvent();
      void handleString(Event* event);
      void processSleep(Event* event);
      void processCountedEvent(uint16_t* key, Event* event);
      void pressSingleButton(uint16_t* key, Event* event);
      void pressRepeatedButton(uint16_t* key, int count, int pressDelay, Event* event);
  };

#endif

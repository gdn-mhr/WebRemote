#ifndef LGREMOTE_H
#define LGREMOTE_H

  #include <Arduino.h>
  
  #include <IRremoteESP8266.h>
  #include <IRsend.h>
  
  #include <queue>

  #include "WebRemoteUtil.h"
  #include "WebRemoteConfig.h"
  #include "LG.h"
  
  class LGRemote {
    private:
      IRsend irsend;
      std::queue<String>* eventqueue;
    public:
      LGRemote(std::queue<String>* eventqueue);
      void startRemote();
      bool handleEvent();
      void handleString(String button);
      void pressSingleButton(uint16_t* key, String name);
  };

#endif

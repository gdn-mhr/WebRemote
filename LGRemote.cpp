#include "LGRemote.h"

LGRemote::LGRemote(std::queue<Event*>* eventqueue) : irsend(IR_LED){
  this->eventqueue = eventqueue;
}

void LGRemote::startRemote() {
  irsend.begin();
}

bool LGRemote::handleEvent() {
  if (!this->eventqueue->empty()) {
    Serial.println("New event needs to be handled. Raw string: " + eventqueue->front()->getEventMessage());
    handleString(eventqueue->front());
    delete(eventqueue->front());
    eventqueue->pop();
    return true;
  }
  return false;
}

void LGRemote::pressSingleButton(uint16_t* key, Event* event) {
  Serial.println("Pressing requested button " + event->getEventMessage() + "...");
  irsend.sendPronto(key, getLGLength());  // Send a raw data capture at 38kHz.
}

void LGRemote::pressRepeatedButton(uint16_t* key, int count, int pressDelay, Event* event) {
  for(int i = 0; i < count; i++) {
    pressSingleButton(key,event);
    delay(pressDelay);
  }
}

void LGRemote::processSleep(Event* event) {
  int repeats = 1;
  if (event->getEventModifier() == "180") {
    repeats = 2;
  } else if (event->getEventModifier() == "150") {
    repeats = 3;
  } else if (event->getEventModifier() == "120") {
    repeats = 4;
  } else if (event->getEventModifier() == "90") {
    repeats = 5;
  } else if (event->getEventModifier() == "80") {
    repeats = 6;
  } else if (event->getEventModifier() == "70") {
    repeats = 7;
  } else if (event->getEventModifier() == "60") {
    repeats = 8;
  } else if (event->getEventModifier() == "50") {
    repeats = 9;
  } else if (event->getEventModifier() == "40") {
    repeats = 10;
  } else if (event->getEventModifier() == "30") {
    repeats = 11;
  } else if (event->getEventModifier() == "20") {
    repeats = 12;
  } else if (event->getEventModifier() == "10") {
    repeats = 13;
  }
  
  pressRepeatedButton(getLGSleep(), repeats, 500, event);
}

void LGRemote::processCountedEvent(uint16_t* key, Event* event) {
  int repeats = (event->getEventModifier()).toInt();
    
  pressRepeatedButton(key, repeats, 100, event);
}

void LGRemote::handleString(Event* event) {
  switch(str2int((event->getEventMessage()).c_str()))
  {
    case str2int("LG_POWER"):
      pressSingleButton(getLGPower(), event);
      break;
    case str2int("LG_EJECT"):
      pressSingleButton(getLGEject(), event);
      break;
    case str2int("LG_FOLDER_UP"):
      pressSingleButton(getLGFolderUp(), event);
      break;
    case str2int("LG_FOLDER_DOWN"):
      pressSingleButton(getLGFolderDown(), event);
      break;
    case str2int("LG_FUNCTION"):
      pressSingleButton(getLGFunction(), event);
      break;
    case str2int("LG_MUTE"):
      pressSingleButton(getLGMute(), event);
      break;
    case str2int("LG_VOLUME_UP"):
      if (event->getEventModifier() == "") {
        pressSingleButton(getLGVolumeUp(), event);
      } else {
        processCountedEvent(getLGVolumeUp(), event);
      }
      break;
    case str2int("LG_VOLUME_DOWN"):
      if (event->getEventModifier() == "") {
        pressSingleButton(getLGVolumeDown(), event);
      } else {
        processCountedEvent(getLGVolumeDown(), event);
      }
      break;
    case str2int("LG_PROGRAM"):
      pressSingleButton(getLGProgram(), event);
      break;
    case str2int("LG_EFFECT"):
      pressSingleButton(getLGEffect(), event);
      break;
    case str2int("LG_INFO"):
      pressSingleButton(getLGInfo(), event);
      break;
    case str2int("LG_UP"):
      pressSingleButton(getLGUp(), event);
      break;
    case str2int("LG_LEFT"):
      pressSingleButton(getLGLeft(), event);
      break;
    case str2int("LG_ENTER"):
      pressSingleButton(getLGEnter(), event);
      break;
    case str2int("LG_RIGHT"):
      pressSingleButton(getLGRight(), event);
      break;
    case str2int("LG_DOWN"):
      pressSingleButton(getLGDown(), event);
      break;
    case str2int("LG_SLEEP"):
      if(event->getEventModifier() == "") {
        pressSingleButton(getLGSleep(), event);
      } else {
        processSleep(event);
      }
      break;
    case str2int("LG_USB_REC"):
      pressSingleButton(getLGUSBRec(), event);
      break;
    case str2int("LG_DELETE"):
      pressSingleButton(getLGDelete(), event);
      break;
    case str2int("LG_ONE"):
      pressSingleButton(getLGOne(), event);
      break;
    case str2int("LG_TWO"):
      pressSingleButton(getLGTwo(), event);
      break;
    case str2int("LG_THREE"):
      pressSingleButton(getLGThree(), event);
      break;
    case str2int("LG_FOUR"):
      pressSingleButton(getLGFour(), event);
      break;
    case str2int("LG_FIVE"):
      pressSingleButton(getLGFive(), event);
      break;
    case str2int("LG_SIX"):
      pressSingleButton(getLGSix(), event);
      break;
    case str2int("LG_SEVEN"):
      pressSingleButton(getLGSeven(), event);
      break;
    case str2int("LG_EIGHT"):
      pressSingleButton(getLGEight(), event);
      break;
    case str2int("LG_NINE"):
      pressSingleButton(getLGNine(), event);
      break;
    case str2int("LG_CLOCK"):
      pressSingleButton(getLGClock(), event);
      break;
    case str2int("LG_ZERO"):
      pressSingleButton(getLGZero(), event);
      break;
    case str2int("LG_ALARM"):
      pressSingleButton(getLGAlarm(), event);
      break;
    case str2int("LG_SET"):
      pressSingleButton(getLGSet(), event);
      break;
    case str2int("LG_PTY"):
      pressSingleButton(getLGPTY(), event);
      break;
    default:
      Serial.println("Error. No matching action found for " + event->getEventMessage() + ". Are you sure, that there is no typo in your request?");
      break;
  }
  
}

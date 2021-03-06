#include "LGRemote.h"

LGRemote::LGRemote(std::queue<String>* eventqueue) : irsend(IR_LED){
  this->eventqueue = eventqueue;
}

void LGRemote::startRemote() {
  irsend.begin();
}

bool LGRemote::handleEvent() {
  if (!this->eventqueue->empty()) {
    Serial.println("New event needs to be handled. Raw string: " + eventqueue->front());
    handleString(eventqueue->front());
    eventqueue->pop();
    return true;
  }
  return false;
}

void LGRemote::pressSingleButton(uint16_t* key, String name) {
  Serial.println("Pressing requested button " + name + "...");
  irsend.sendPronto(key, getLGLength());  // Send a raw data capture at 38kHz.
}

void LGRemote::handleString(String button) {
  switch(str2int(button.c_str()))
  {
    case str2int("LG_POWER"):
      pressSingleButton(getLGPower(), button);
      break;
    case str2int("LG_EJECT"):
      pressSingleButton(getLGEject(), button);
      break;
    case str2int("LG_FOLDER_UP"):
      pressSingleButton(getLGFolderUp(), button);
      break;
    case str2int("LG_FOLDER_DOWN"):
      pressSingleButton(getLGFolderDown(), button);
      break;
    case str2int("LG_FUNCTION"):
      pressSingleButton(getLGFunction(), button);
      break;
    case str2int("LG_MUTE"):
      pressSingleButton(getLGMute(), button);
      break;
    case str2int("LG_VOLUME_UP"):
      pressSingleButton(getLGVolumeUp(), button);
      break;
    case str2int("LG_VOLUME_DOWN"):
      pressSingleButton(getLGVolumeDown(), button);
      break;
    case str2int("LG_PROGRAM"):
      pressSingleButton(getLGProgram(), button);
      break;
    case str2int("LG_EFFECT"):
      pressSingleButton(getLGEffect(), button);
      break;
    case str2int("LG_INFO"):
      pressSingleButton(getLGInfo(), button);
      break;
    case str2int("LG_UP"):
      pressSingleButton(getLGUp(), button);
      break;
    case str2int("LG_LEFT"):
      pressSingleButton(getLGLeft(), button);
      break;
    case str2int("LG_ENTER"):
      pressSingleButton(getLGEnter(), button);
      break;
    case str2int("LG_RIGHT"):
      pressSingleButton(getLGRight(), button);
      break;
    case str2int("LG_DOWN"):
      pressSingleButton(getLGDown(), button);
      break;
    case str2int("LG_SLEEP"):
      pressSingleButton(getLGSleep(), button);
      break;
    case str2int("LG_USB_REC"):
      pressSingleButton(getLGUSBRec(), button);
      break;
    case str2int("LG_DELETE"):
      pressSingleButton(getLGDelete(), button);
      break;
    case str2int("LG_ONE"):
      pressSingleButton(getLGOne(), button);
      break;
    case str2int("LG_TWO"):
      pressSingleButton(getLGTwo(), button);
      break;
    case str2int("LG_THREE"):
      pressSingleButton(getLGThree(), button);
      break;
    case str2int("LG_FOUR"):
      pressSingleButton(getLGFour(), button);
      break;
    case str2int("LG_FIVE"):
      pressSingleButton(getLGFive(), button);
      break;
    case str2int("LG_SIX"):
      pressSingleButton(getLGSix(), button);
      break;
    case str2int("LG_SEVEN"):
      pressSingleButton(getLGSeven(), button);
      break;
    case str2int("LG_EIGHT"):
      pressSingleButton(getLGEight(), button);
      break;
    case str2int("LG_NINE"):
      pressSingleButton(getLGNine(), button);
      break;
    case str2int("LG_CLOCK"):
      pressSingleButton(getLGClock(), button);
      break;
    case str2int("LG_ZERO"):
      pressSingleButton(getLGZero(), button);
      break;
    case str2int("LG_ALARM"):
      pressSingleButton(getLGAlarm(), button);
      break;
    case str2int("LG_SET"):
      pressSingleButton(getLGSet(), button);
      break;
    case str2int("LG_PTY"):
      pressSingleButton(getLGPTY(), button);
      break;
    default:
      Serial.println("Error. No matching action found for " + button + ". Are you sure, that there is no typo in your request?");
      break;
  }
  
}

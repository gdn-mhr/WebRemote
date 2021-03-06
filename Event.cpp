#include "Event.h"

Event::Event(String message) {
  this->message = message;
  this->modifier = "";
}

Event::Event(String message, String modifier) {
  this->message = message;
  this->modifier = modifier;
}

void Event::setEventMessage(String message) {
  this->message = message;
}

void Event::setEventModifier(String modifier) {
  this->modifier = modifier;
}

String Event::getEventMessage() {
  return this->message;
}

String Event::getEventModifier() {
  return this-> modifier;
}

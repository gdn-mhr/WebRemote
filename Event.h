#ifndef EVENT_H
#define EVENT_H

  #include <Arduino.h>

  class Event {
    private:
      String message;
      String modifier;
    public:
      Event(String message);
      Event(String message, String modifier);
      void setEventMessage(String);
      void setEventModifier(String);
      String getEventMessage();
      String getEventModifier();
  };

#endif

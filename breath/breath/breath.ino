/*
 Science Hack!
 */
 
#include "MTBASerial.h"

int breathPin = A2;

MTBASerial serial;

void setup() {
  serial.begin();
}

void loop() {
  int breathSignal = analogRead(breathPin);
  serial.send(breathSignal);
  
  delay(16);
}

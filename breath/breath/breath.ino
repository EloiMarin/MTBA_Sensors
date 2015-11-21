/*
 Science Hack!
 */
 
#include "MTBASerial.h"

int breathPin = A2;
int breathSignal = 0;

MTBASerial serial;

void setup() {
  serial.begin();
}

void loop() {
  breathSignal = analogRead(breathPin);
  
  serial.send(breathSignal);
}

#include "MTBASerial.h"

const int pulsePin = A0;
const int breathPin = A2;
const int skinPin = A4;

MTBASerial serial;

void setup() {
  serial.begin();
}

void loop() {
  int pulseSignal = analogRead(pulsePin);
  serial.send(pulseSignal, 0);

  int breathSignal = analogRead(breathPin);
  serial.send(breathSignal, 1);

  int skinSignal = analogRead(skinPin);
  serial.send(skinSignal, 2);
  
  delay(16);
}

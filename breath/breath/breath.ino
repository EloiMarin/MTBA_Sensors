/*
 Science Hack!
 */
 
#include "MTBASerial.h"

int breathPin = A2;
int breathSignal = 0;

MTBASerial serial;

void setup() {
  serial.begin();
  serial.write(123);
  delay(100);
}

void loop() {
  breathSignal = analogRead(breathPin);  
  
  byte msbBreathSignal = breathSignal>>8;  
  byte lsbBreathSignal = breathSignal&255;
  
  serial.write(msbBreathSignal);
  serial.write(lsbBreathSignal);
//  Serial.write(breathSignal);
//  Serial.println(breathSignal);  
}

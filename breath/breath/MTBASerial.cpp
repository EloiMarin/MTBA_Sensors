#include "MTBASerial.h"
#include "Arduino.h"

void MTBASerial::begin()
{
  Serial.begin(_baud);
}

void MTBASerial::write(char data)
{
}

void MTBASerial::write(int data)
{
}

void MTBASerial::write(long data)
{
}

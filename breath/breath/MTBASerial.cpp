#include "MTBASerial.h"

void MTBASerial::begin()
{
  Serial.begin(_baud);
}

void MTBASerial::write(byte data, int channel)
{
  if (!isValidChannel(channel))
    return;
}

void MTBASerial::write(int data, int channel)
{
  if (!isValidChannel(channel))
    return;
}

void MTBASerial::write(long data, int channel)
{
  if (!isValidChannel(channel))
    return;
}

boolean MTBASerial::isValidChannel(int channel)
{
  return channel < _maxChannels;
}

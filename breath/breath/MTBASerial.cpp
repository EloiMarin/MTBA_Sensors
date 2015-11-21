#include "MTBASerial.h"

void MTBASerial::begin()
{
  Serial.begin(_baud);
}

void MTBASerial::write(byte data, int channel)
{
  if (!isValidChannel(channel))
    return;
  
  byte sendBuffer[4] = { 255, channel, 1, data };
  Serial.write(sendBuffer, sizeof(sendBuffer));
}

void MTBASerial::write(int data, int channel)
{
  if (!isValidChannel(channel))
    return;

  byte dataMSB = data >> 8;
  byte dataLSB = data & 255;

  byte sendBuffer[5] = { 255, channel, 2, dataMSB, dataLSB };
  Serial.write(sendBuffer, sizeof(sendBuffer));
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

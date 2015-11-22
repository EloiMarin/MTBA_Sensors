#include "MTBASerial.h"

void MTBASerial::begin()
{
  Serial.begin(_baud);
}

void MTBASerial::send(byte data, word channel)
{
  if (!isValidChannel(channel))
    return;
  
  byte sendBuffer[4] = { 255, channel, 1, data };
  Serial.write(sendBuffer, sizeof(sendBuffer));
}

void MTBASerial::send(int data, word channel)
{
  if (!isValidChannel(channel))
    return;

  byte dataMSB = data >> 8;
  byte dataLSB = data & 255;

  byte sendBuffer[5] = { 255, channel, 2, dataMSB, dataLSB };
  Serial.write(sendBuffer, sizeof(sendBuffer));
}

void MTBASerial::send(long data, word channel)
{
  if (!isValidChannel(channel))
    return;

  byte dataB24 = data >> 24;
  byte dataB16 = data >> 16;
  byte dataB8 = data >> 8;
  byte dataB0 = data & 255;

  byte sendBuffer[7] = { 255, channel, 4, dataB24, dataB16, dataB8, dataB0 };
  Serial.write(sendBuffer, sizeof(sendBuffer));
}

boolean MTBASerial::isValidChannel(word channel)
{
  return channel < _maxChannels;
}

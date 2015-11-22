/*
  MTBASerial.h - Library for reliable serial communication on MTBA.

  A simple communication protocol is agreed between Arduino and
  the client:

    255 - channel - length - data

  - "channel" must be < 5
  - "length" is expressed in bytes and must be < 5. It represents
  the number of bytes in "data".
  - "data" consists on one or more bytes representing the value
  to be transmitted. For values bigger than 1 byte, the value
  is split into multiple single bytes that are transmitted
  sequentially from MSB to LSB. The client should then regroup
  the received bytes to get the original value.

  Created by Eloi Marin Gratacos (eszeken@hotmail.com)
  Released into the public domain.
*/

#ifndef MTBASerial_h
#define MTBASerial_h

#include "Arduino.h"

class MTBASerial
{
  public:
    MTBASerial() : _isInt32b(sizeof(int) == sizeof(long)) {}

    void begin();
    
    void send(byte data, word channel = 0);
    void send(int data, word channel = 0);
    void send(long data, word channel = 0);
    
  private:
    const int _baud = 19200;
    const int _maxChannels = 5;
    const bool _isInt32b;

    boolean isValidChannel(word channel);
};

#endif // MTBASerial_h

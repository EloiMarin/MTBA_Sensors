#ifndef MTBASerial_h
#define MTBASerial_h

#include "Arduino.h"

class MTBASerial
{
  public:
    void begin();
    
    void send(byte data, int channel = 0);
    void send(int data, int channel = 0);
    void send(long data, int channel = 0);
    
  private:
    const int _baud = 14400;
    const int _maxChannels = 5;

    boolean isValidChannel(int channel);
};

#endif // MTBASerial_h

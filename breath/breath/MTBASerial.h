#ifndef MTBASerial_h
#define MTBASerial_h

class MTBASerial
{
  public:
    void begin();
    
    void write(char);
    void write(int);
    void write(long);
    
  private:
    const int _baud = 14400;
};

#endif // MTBASerial_h

#ifndef SEGMENT_7_h
#define SEGMENT_7_h

#include "Arduino.h"
#include "cam_ht16k33.h"


class SEGMENT_7 {
  public:
    CAM_HT16K33 _ht16k33;
    void    begin(uint8_t addr);
    void    write7Seg(int value);
    int8_t  readKey(boolean clear=false);
  private:

    void    writeLED(int pos, bool var);
    void    set7Seg(int pos, int var);
    void    segClear(int pos);
};
#endif

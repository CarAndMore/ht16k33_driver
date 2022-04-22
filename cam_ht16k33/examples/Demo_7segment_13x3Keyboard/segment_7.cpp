
#include "Arduino.h"
#include "cam_ht16k33.h"
#include "segment_7.h"

uint8_t _ziffern_7seg[] = {
  B00111111, // 0
  B00000110, // 1
  B01011011, // 2
  B01001111, // 3
  B01100110, // 4
  B01101101, // 5
  B01111101, // 6
  B00000111, // 7
  B01111111, // 8
  B01101111  // 9
};

void SEGMENT_7::begin(uint8_t addr) {
  _ht16k33.begin(addr);
  _ht16k33.setBrightness(15);
  _ht16k33.clearAll();
}

void SEGMENT_7::write7Seg(int value) {
  set7Seg(0, value % 10);
  if (value >= 10) {
    set7Seg(1, (value / 10) % 10);
  } else {
    segClear(1);
  }
  if (value >= 100) {
    set7Seg(2, (value / 100) % 10);
  } else {
    segClear(2);
  }
  if (value >= 1000) {
    set7Seg(3, (value / 1000) % 10);
  } else {
    segClear(3);
  }
  _ht16k33.sendLed();
}

int8_t SEGMENT_7::readKey(boolean clear=false) {
  return _ht16k33.readKey();
}

/***************************/

void SEGMENT_7::writeLED(int pos, bool var) {
  if (var) {
    _ht16k33.setLed(pos);
  } else {
    _ht16k33.clearLed(pos);
  }
}

void SEGMENT_7::set7Seg(int pos, int var) {
  uint8_t x = _ziffern_7seg[var];
  for (int c = 0; c < 8; c++) {
    writeLED( (c * 16) + pos, x & (1 << c));
  }
}

void SEGMENT_7::segClear(int pos) {
  for (int c = 0; c < 8; c++) {
    _ht16k33.clearLed((c * 16) + pos);
  }
}
/***************************/

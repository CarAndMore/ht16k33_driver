#include "segment_7.h"

#define  lcd_counterMax 9999
#define  lcd_pause 20

long lcd_counter = 0; // on start

SEGMENT_7 seg7;

void setup() {
  seg7.begin(0x74);
  seg7.write7Seg(8888);
  delay(lcd_pause * 8);
}

void loop() {
  int8_t key;
  static uint8_t lastKey = 0;
  
  key = seg7.readKey();
  if (key != 0) { // key is pressed
    if (key != lastKey) {
      lastKey = key;
      if (key > 0) { // is pressed
        seg7.write7Seg(key);
        delay(lcd_pause * 8);
      }
    }
  }
  
  seg7.write7Seg(lcd_counter);
  lcd_counter++;
  if (lcd_counter > lcd_counterMax) {
    lcd_counter = 0;
  }
  delay(lcd_pause);

}

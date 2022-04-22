// #define mySerial Serial
#include "cam_ht16k33.h"

CAM_HT16K33 ht16k33_1;

void setup() {
  ht16k33_1.begin(0x74);
}

void loop() {
  demo1();
}

void demo1() {
  int timer = 100;
  uint8_t led;
  for (led = 0; led < 128; led++) {
    ht16k33_1.setLedNow(led);
    delay(timer);
  } // for led
  //Next clear them
  for (led = 0; led < 128; led++) {
    ht16k33_1.clearLedNow(led);
    delay(timer);
  } // for led
}

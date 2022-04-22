
#define ht16k33_addr 0x74

#define mySerial Serial
#define myBaud 9600

#include "cam_ht16k33.h"

CAM_HT16K33 ht16k33_1;

void setup() {

  ht16k33_1.begin(0x74);
  mySerial.begin(myBaud);
  mySerial.println("");
  mySerial.println("*** Bereit ***");
}

void loop() {
  int8_t key;
  static uint8_t lastKey = 0;

  key = ht16k33_1.readKey();
  if (key != 0) { // key is pressed
    if (key != lastKey) {
      lastKey = key;
      mySerial.print("Taste Nr.: ");
      mySerial.println(key);
      switch (key) {
        case 1:
          mySerial.println("1. Taste wurde gedrückt.");
          break;
        case -1:
          mySerial.println("1. Taste wurde losgelassen.");
          break;
        case 2:
          mySerial.println("2. Taste wurde gedrückt.");
          break;
        case -2:
          mySerial.println("2. Taste wurde losgelassen.");
          break;
          
        case 14:
          mySerial.println("14. Taste wurde gedrückt.");
          break;
        case -14:
          mySerial.println("14. Taste wurde losgelassen.");
          break;
        case 15:
          mySerial.println("15. Taste wurde gedrückt.");
          break;
        case -15:
          mySerial.println("15. Taste wurde losgelassen.");
          break;
      }
    }
  }
  delay(50);
}

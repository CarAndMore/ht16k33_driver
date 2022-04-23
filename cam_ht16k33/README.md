# Matrix LED 

## 16x8 LED Matrix Demo
nacheinander werden die LEDs 1-128 ein geschaltet, danach wieder aus. usw....
```cpp
#define ht16k33_addr  0x70
#define pause  100

#include "cam_ht16k33.h"

CAM_HT16K33 ht16k33_1;

void setup() {
  ht16k33_1.begin(ht16k33_addr);
}

void loop() {
  uint8_t led;
  for (led=0; led<128; led++) {
    ht16k33_1.setLedNow(led);
    delay(pause);
  }
  for (led=0; led<128; led++) {
    ht16k33_1.clearLedNow(led);
    delay(pause);
  }
}
```

## 8 bit LED Counter
Binärzähler
```cpp
#define    ht16k33_addr 0x70
#define    pause        50

#include "cam_ht16k33.h"

CAM_HT16K33 ht16k33_1;

uint8_t COUNTER_D;

void setup() {
  ht16k33_1.begin(ht16k33_addr); //    -   -   -   -   -   -   ht16k33 bereit machen.
  ht16k33_1.setBrightness(5); //   -   -   -   -   -   -   -   Helligkeit der LEDs auf 5/16 stellen
}

void loop() {  
  ht16k33_1.setDisplayRaw(0,   (COUNTER_D & 0xff));  //-   -   überträgt die 8 Bit an den Chip
  
  // invertierte Ausgabe
  ht16k33_1.setDisplayRaw(2,   ~(COUNTER_D & 0xff)); //-   -   überträgt die 8 Bit an den Chip

  ht16k33_1.sendLed(); //   -   -   -   -   -   -   -   -   -   daten vom Chip an die LEDs übertragen.
  
  delay(pause);
  COUNTER_D++;
}
```

Binärzähler
## 16 bit LED Counter
```cpp
#define    ht16k33_addr 0x70
#define    pause        50

#include "cam_ht16k33.h"

CAM_HT16K33 ht16k33_1;

uint16_t COUNTER_D;

void setup() {
  ht16k33_1.begin(ht16k33_addr); //    -   -   -   -   -   -   ht16k33 bereit machen.
  ht16k33_1.setBrightness(5); //   -   -   -   -   -   -   -   Helligkeit der LEDs auf 5/16 stellen
}

void loop() {  
  ht16k33_1.setDisplayRaw(0,   (COUNTER_D & 0xff)); // -   -   überträgt die 1. 8 Bit (LOW BYTE) an den Chip
  ht16k33_1.setDisplayRaw(1,  ((COUNTER_D & 0xff00) >> 8)); // überträgt die 2. 8 Bit (HIGH BYTE) an den Chip
  
  // invertierte Ausgabe
  ht16k33_1.setDisplayRaw(2,   ~(COUNTER_D & 0xff)); // -   -   überträgt die 1. 8 Bit (LOW BYTE) an den Chip
  ht16k33_1.setDisplayRaw(3,  ~((COUNTER_D & 0xff00) >> 8)); // überträgt die 2. 8 Bit (HIGH BYTE) an den Chip

  ht16k33_1.sendLed(); //   -   -   -   -   -   -   -   -   -   daten vom Chip an die LEDs übertragen.
  
  delay(pause);
  COUNTER_D++;
}
```

# Keyboard

## 13x3 Key Matrix Demo
wenn eine Taste gedrückr wurde, wird deren Werte (1 - 39) / (-1 - -39) auf dem Serial Monitor ausgegeben.
```cpp
#define ht16k33_addr 0x70

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
      
    }
  }
  delay(50);
}

```

## auswerten Demo

```cpp
#define ht16k33_addr 0x70

#include "cam_ht16k33.h"

CAM_HT16K33 ht16k33_1;

void setup() {
  ht16k33_1.begin(ht16k33_addr);
}

void loop() {
  int8_t key;
  static uint8_t lastKey = 0;
  key = ht16k33_1.readKey();
  if (key != 0) { // key is pressed
    if (key != lastKey) {
      lastKey = key;
      switch (key) {
        case 1: // 1.1
          mySerial.println("*  1. Taste wurde gedrückt.");
          break;
        case -1: // key 1.1
          mySerial.println("*  1. Taste wurde losgelassen.");
          break;
        case 2: // key 1.2
          mySerial.println("*  2. Taste wurde gedrückt.");
          break;
        case -2: // key 1.2
          mySerial.println("*  2. Taste wurde losgelassen.");
          break;
        case 14: // key 2.1
          mySerial.println("* 14. Taste wurde gedrückt.");
          break;
        case -14: // key 2.1
          mySerial.println("* 4. Taste wurde losgelassen.");
          break;
        case 15: // key 2.2
          mySerial.println("* 15. Taste wurde gedrückt.");
          break;
        case -15: // key 2.2
          mySerial.println("* 15. Taste wurde losgelassen.");
          break;
        case 39:  // key 3.13
          mySerial.println("* 39. Taste wurde gedrückt.");
          break;
        case -39: // key 3.13
          mySerial.println("* 39. Taste wurde losgelassen.");
          break;
      }
    }
  }
  delay(50);
}
```


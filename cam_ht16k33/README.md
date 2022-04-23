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

## Counter mit 8x8 font
```cpp
#define ht16k33_addr  0x74

#define demo1_Pause   1000

// #define mySerial Serial
// #define myBaud 9600

int counterDemo = 20;
int counterDemoMax = 100;

uint8_t cam__8x8_font_C64_hex [][8] = {
  {0x3e, 0x63, 0x73, 0x6b, 0x67, 0x63, 0x3e, 0x00}, // 0
  {0x18, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00}, // 1
  {0x3c, 0x66, 0x60, 0x30, 0x18, 0x0c, 0x7e, 0x00}, // 2
  {0x3c, 0x66, 0x60, 0x38, 0x60, 0x66, 0x3c, 0x00}, // 3
  {0x38, 0x3c, 0x36, 0x33, 0x7f, 0x30, 0x30, 0x00}, // 4
  {0x7e, 0x06, 0x3e, 0x60, 0x60, 0x66, 0x3c, 0x00}, // 5
  {0x3c, 0x66, 0x06, 0x3e, 0x66, 0x66, 0x3c, 0x00}, // 6
  {0x7e, 0x60, 0x60, 0x30, 0x18, 0x18, 0x18, 0x00}, // 7
  {0x3c, 0x66, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x00}, // 8
  {0x3c, 0x66, 0x66, 0x7c, 0x30, 0x18, 0x0c, 0x00}, // 9
  {0x1c, 0x36, 0x63, 0x63, 0x7f, 0x63, 0x63, 0x00}, // A
  {0x3f, 0x63, 0x63, 0x3f, 0x63, 0x63, 0x3f, 0x00}, // B
  {0x3c, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3c, 0x00}, // C
  {0x1f, 0x33, 0x63, 0x63, 0x63, 0x33, 0x1f, 0x00}, // D
  {0x7f, 0x03, 0x03, 0x1f, 0x03, 0x03, 0x7f, 0x00}, // E
  {0x7f, 0x03, 0x03, 0x1f, 0x03, 0x03, 0x03, 0x00}, // F
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //' '
};

#include "cam_ht16k33.h"
CAM_HT16K33 ht16k33_1;
void setup() {
  ht16k33_1.begin(ht16k33_addr);
}

void loop() {
  for (uint8_t x = 0; x < 8; x++) { 
    if (((counterDemo / 10) % 10) == 0) {
      ht16k33_1.setDisplayRaw(x * 2 + 0, cam__8x8_font_C64_hex[16][x]);
    } else {
      ht16k33_1.setDisplayRaw(x * 2 + 0, cam__8x8_font_C64_hex[(counterDemo / 10) % 10][x]);
    }
    ht16k33_1.setDisplayRaw(x * 2 + 1, cam__8x8_font_C64_hex[counterDemo % 10][x]);
  }
  ht16k33_1.sendLed();
  delay(demo1_Pause);
  
  counterDemo += 1;
  if (counterDemo >= counterDemoMax) {
    counterDemo = 0;
  } else if (counterDemo < 0) {
    counterDemo = counterDemoMax -1;
  }
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


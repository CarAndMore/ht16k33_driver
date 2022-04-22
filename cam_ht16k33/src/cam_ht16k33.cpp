#include "Arduino.h"
#include <Wire.h>

#include "cam_ht16k33.h"
#include "BitCommands.h"

// Constructor
CAM_HT16K33::CAM_HT16K33() {
} // CAM_HT16K33

/****************************************************************/
// Setup the env
void CAM_HT16K33::begin(uint8_t address) {
  uint8_t i;
  _address = address;
  Wire.begin();
  i2c_write(HT16K33_SS  | HT16K33_SS_NORMAL); // Wakeup
  i2c_write(HT16K33_DSP | HT16K33_DSP_ON | HT16K33_DSP_NOBLINK); // Display on and no blinking
  i2c_write(HT16K33_RIS | HT16K33_RIS_OUT); // INT pin works as row output
  i2c_write(HT16K33_DIM | HT16K33_DIM_16);  // Brightness set to max
  clearAll();
} // begin

/****************************************************************/
// Put the chip to sleep
uint8_t CAM_HT16K33::sleep() {
  return i2c_write(HT16K33_SS | HT16K33_SS_STANDBY); // Stop oscillator
} // sleep

/****************************************************************/
// Wake up the chip (after it been a sleep )
uint8_t CAM_HT16K33::normal() {
  return i2c_write(HT16K33_SS | HT16K33_SS_NORMAL); // Start oscillator
} // normal

/****************************************************************/
// turn on the display
void CAM_HT16K33::displayOn() {
  i2c_write(HT16K33_DSP | HT16K33_DSP_ON);
} // displayOn

/****************************************************************/
// turn off the display
void CAM_HT16K33::displayOff() {
  i2c_write(HT16K33_DSP | HT16K33_DSP_OFF);
} // displayOff

/****************************************************************
***  Display
****************************************************************/
/* Change brightness of the whole display level 0-15, 0 means display off
  Ändern Sie die Helligkeit des gesamten Displays
  Level 0-15, 0 bedeutet Display aus
*/
uint8_t CAM_HT16K33::setBrightness(uint8_t level) {
  if (HT16K33_DIM_1 >= 0 && level < HT16K33_DIM_16) {
    return i2c_write(HT16K33_DIM | level);
  } else {
    return 1;
  }
} // setBrightness

/****************************************************************/
/* Clear all leds and displays
  Löscht alle LEDs
*/
void CAM_HT16K33::clearAll() {
  memset(displayRam, 0, sizeof(displayRam));
  i2c_write(HT16K33_DDAP, displayRam, sizeof(displayRam));
} // clearAll

/****************************************************************/
uint8_t CAM_HT16K33::getDisplayRaw(uint8_t pos, boolean Fresh) {

  // get the current state from chip
  if (Fresh) {
    i2c_read(HT16K33_DDAP, displayRam, sizeof(displayRam));
  }
  if (pos >= 0 && pos < 16) {
    return displayRam[pos];
  }
} // getDisplayRaw

/****************************************************************/
uint8_t CAM_HT16K33::setDisplayRaw(uint8_t pos, uint8_t val) {
  if (pos < sizeof(displayRam)) {
    displayRam[pos] = val;
    return 0;
  } else {
    return 1;
  }
} // setDisplayRaw

/****************************************************************/

/****************************************************************/
/* Send the display ram info to chip - kind of commit all changes to the outside world
  Senden Sie die Display-RAM-Informationen an den Chip - übertragen Sie alle Änderungen an die Außenwelt
*/
uint8_t CAM_HT16K33::sendLed() {
  return i2c_write(HT16K33_DDAP, displayRam, sizeof(displayRam));
} // sendLed
/****************************************************************/
/* Turn off one led but only in memory
   To do it on chip a call to "sendLed" is needed
*/
uint8_t CAM_HT16K33::clearLed(uint8_t ledno) { // 16x8 = 128 LEDs to turn on, 0-127
  if (ledno >= 0 && ledno < 128) {
    bitClear(displayRam[int(ledno / 8)], (ledno % 8));
    return 0;
  } else {
    return 1;
  }
} // clearLed

/****************************************************************/
/* Turn on one led but only in memory
  To do it on chip a call to "sendLed" is needed
*/
uint8_t CAM_HT16K33::setLed(uint8_t ledno) { // 16x8 = 128 LEDs to turn on, 0-127
  if (ledno >= 0 && ledno < 128) {
    bitSet(displayRam[int(ledno / 8)], (ledno % 8));
    return 0;
  } else {
    return 1;
  }
} // setLed
/****************************************************************/
/* check if a specific led is on(true) or off(false)
  Überprüfen Sie, ob eine bestimmte LED an (true) oder aus (false) ist
*/
boolean CAM_HT16K33::getLed(uint8_t ledno, boolean Fresh) {

  // get the current state from chip
  if (Fresh) {
    i2c_read(HT16K33_DDAP, displayRam, sizeof(displayRam));
  }

  if (ledno >= 0 && ledno < 128) {
    return bitRead(displayRam[int(ledno / 8)], ledno % 8) != 0;
  }
} // getLed

/****************************************************************/
/****************************************************************/
/* set a single LED and update NOW
  Stellen Sie eine einzelne LED ein und aktualisieren Sie JETZT
*/
uint8_t CAM_HT16K33::setLedNow(uint8_t ledno) {
  uint8_t rc;
  rc = setLed(ledno);
  if (rc == 0) {
    return sendLed();
  } else {
    return rc;
  }
} // setLedNow

/****************************************************************/
/* clear a single LED and update NOW
  Löschet eine einzelne LED und aktualisieren Sie JETZT
*/
uint8_t CAM_HT16K33::clearLedNow(uint8_t ledno) {
  uint8_t rc;
  rc = clearLed(ledno);
  if (rc == 0) {
    return sendLed();
  } else {
    return rc;
  }
} // clearLedNow

/****************************************************************
***  Keyboard
****************************************************************/
/* Check the chips interrupt flag
  // 0 if no new key is pressed
  // !0 if some key is pressed and not yet read

  // Überprüfen Sie das Chip-Interrupt-Flag
  // 0 wenn keine neue Taste gedrückt wird
  // !0 wenn eine Taste gedrückt und noch nicht gelesen wurde
*/
uint8_t CAM_HT16K33::keyINTflag() {
  return i2c_read(HT16K33_IFAP);
} // keyINTflag

/****************************************************************/
// Check if any key is pressed
// returns how many keys that are currently pressed
//

//From http://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer
#ifdef __GNUC__
uint16_t _popcount(uint16_t x) {
  return __builtin_popcount(x);
}
#else
uint16_t _popcount(uint16_t i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
#endif

uint8_t CAM_HT16K33::keysPressed() {
  //  Serial.println(_keyram[0]|_keyram[1]|_keyram[2],HEX);
  return (_popcount(_keyram[0]) + _popcount(_keyram[1]) + _popcount(_keyram[2]));
} // keysPressed

/****************************************************************/
// Internal function - update cached key array
//
void CAM_HT16K33::_updateKeyram() {
  uint8_t curkeyram[6];

  i2c_read(HT16K33_KDAP, curkeyram, 6);
  _keyram[0] = curkeyram[1] << 8 | curkeyram[0]; // datasheet page 21, 41H is high 40H is low
  _keyram[1] = curkeyram[3] << 8 | curkeyram[2]; // or LSB MSB
  _keyram[2] = curkeyram[5] << 8 | curkeyram[4];
  return;
} // _updateKeyram

/****************************************************************/
// return the key status
//
void CAM_HT16K33::readKeyRaw(CAM_HT16K33::KEYDATA keydata, boolean Fresh) {
  int8_t i;

  // get the current state
  if (Fresh) {
    _updateKeyram();
  }

  for (i = 0; i < 3; i++) {
    keydata[i] = _keyram[i];
  }

  return;
} // readKeyRaw

/****************************************************************
   read the keys and return the key that changed state
   if more than one is pressed (compared to last scan)
   only one is returned, the first one found
   0 means no key pressed.
   "1" means the key #1 is pressed
   "-1" means the key #1 is released
   "clear"=true means it will only look keys currently pressed down.
       this is so you can detect what key is still pressed down after
       several keys are pressed down and then all but one is released
       (without keeping track of up/down separately)

  Observations:
   As long as the key is pressed the keyram bit is set
   the flag is set when key is pressed down but then cleared at first
   read of key ram.
   When released the key corresponding bit is cleared but the flag is NOT set
   This means that the only way a key release can be detected is
   by only polling readKey and ignoring flag

*/

int8_t CAM_HT16K33::readKey(boolean clear) {
  static CAM_HT16K33::KEYDATA oldKeyData;
  uint16_t diff;
  uint8_t key;
  int8_t i, j;

  // save the current state
  for (i = 0; i < 3; i++) {
    if (clear) {
      oldKeyData[i] = 0;
    } else {
      oldKeyData[i] = _keyram[i];
    }
  }

  _updateKeyram();

  key = 0; //the key that changed state
  for (i = 0; i < 3; i++) {
    diff = _keyram[i] ^ oldKeyData[i]; //XOR old and new, any changed bit is set.
    if ( diff != 0 ) { // something did change
      for (j = 0; j < 13; j++) {
        key++;
        if (((diff >> j) & 1) == 1) {
          if (((_keyram[i] >> j) & 1) == 0) {
            return -key;
          } else {
            return key;
          }
        } // if keyram differs
      } // for j in bits
    } else {
      key += 13;
    } // if diff
  } // for i
  return 0; //apperently no new key was pressed - old might still be held down, pass clear=true to see it
} // readKey

/****************************************************************/


/****************************************************************
  Some helper functions that can be useful in other parts of the code that use this library
****************************************************************/
// internal function - Write a single byte
//
uint8_t CAM_HT16K33::i2c_write(uint8_t val) {
  Wire.beginTransmission(_address);
  Wire.write(val);
  return Wire.endTransmission();
} // i2c_write

/****************************************************************/
/* internal function - Write several bytes
  // "size" is amount of data to send excluding the first command byte
  // if LSB is true then swap high and low byte to send LSB MSB
  // NOTE: Don't send odd amount of data if using LSB, then it will send one to much

  interne Funktion - Mehrere Bytes schreiben
  "Größe" ist die zu sendende Datenmenge ohne das erste Befehlsbyte
  Wenn LSB wahr ist, dann High- und Low-Byte tauschen, um LSB MSB zu senden
  HINWEIS: Senden Sie keine ungeraden Datenmengen, wenn Sie LSB verwenden, dann wird eine zu viel gesendet
*/
uint8_t CAM_HT16K33::i2c_write(uint8_t cmd, uint8_t *data, uint8_t size, boolean LSB) {
  uint8_t i;
  Wire.beginTransmission(_address);
  Wire.write(cmd);
  i = 0;
  while (i < size) {
    if (LSB) {
      Wire.write(data[i + 1]);
      Wire.write(data[i++]);
      i++;
    } else {
      Wire.write(data[i++]);
    }
  }
  return Wire.endTransmission(); // Send out the data
} // i2c_write

/****************************************************************/
// internal function - read a byte from specific address
/*
  - internal function - read a byte from specific address (send one byte(address to read) and read a byte)
  Interne Funktion
  - Lesen Sie ein Byte von einer bestimmten Adresse
   (senden Sie ein Byte (zu lesende Adresse) und lesen Sie ein Byte)
*/
uint8_t CAM_HT16K33::i2c_read(uint8_t addr) {
  i2c_write(addr);
  Wire.requestFrom(_address, (uint8_t) 1);
  return Wire.read();    // read one byte
} // i2c_read

/****************************************************************/
/* read an array from specific address (send a byte and read several bytes back)
  - return value is how many bytes that where really read

  lesen ein Array von einer bestimmten Adresse  (ein Byte senden und mehrere Bytes zurücklesen)
  Rückgabewert ist, wie viele Bytes wirklich gelesen wurden
*/
uint8_t CAM_HT16K33::i2c_read(uint8_t addr, uint8_t *data, uint8_t size) {
  uint8_t i, retcnt, val;

  i2c_write(addr);
  retcnt = Wire.requestFrom(_address, size);
  i = 0;
  while (Wire.available() && i < size) // slave may send less than requested
  {
    data[i++] = Wire.read();    // receive a byte as character
  }

  return retcnt;
} // i2c_read

/****************************************************************/

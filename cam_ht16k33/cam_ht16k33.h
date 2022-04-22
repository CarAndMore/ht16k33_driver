#ifndef CAM_ht16k33_h
#define CAM_ht16k33_h
#include "Arduino.h"

class CAM_HT16K33 {
  public:
    typedef uint16_t KEYDATA[3];
    
    typedef uint8_t  DisplayRam_t[16];
    DisplayRam_t displayRam;

    CAM_HT16K33(); // the class itself
    void    begin(uint8_t address);
    uint8_t sleep();  // stop oscillator to put the chip to sleep
    uint8_t normal(); // wake up chip and start ocillator
    void    displayOn();
    void    displayOff();
    
    // Display    
    uint8_t setBrightness(uint8_t level); // level 0-16, 0 means display off

    void    clearAll(); // clear all LEDs
    
    uint8_t getDisplayRaw(uint8_t pos, boolean Fresh = false); // "line" 0-16, return byte LEDsis
    uint8_t setDisplayRaw(uint8_t pos, uint8_t val); // load byte "pos" with value "val"

    uint8_t sendLed(); // send whatever led patter you set

    boolean getLed(uint8_t ledno, boolean Fresh = false); // check if a specific led is on(true) or off(false)

    uint8_t clearLed(uint8_t ledno); // 16x8 = 128 LEDs to turn on, 0-127
    uint8_t setLed(uint8_t ledno); // 16x8 = 128 LEDs to turn on, 0-127

    uint8_t setLedNow(uint8_t ledno); // Set a single led and send led in one function
    uint8_t clearLedNow(uint8_t ledno); // Clear a single led and send led in one function
    
    // Keyboard
    uint8_t keyINTflag(); // INTerrupt flag value, set when a key is pressed
    uint8_t keysPressed(); // report how many keys that are pressed, clear means report as if new
    int8_t  readKey(boolean clear = false); // read what key was pressed, Fresh=false to go from cache
    void    readKeyRaw(KEYDATA keydata, boolean Fresh = true); //read the raw key info, bitmapped info of all key(s) pressed
    
    // Some helper functions that can be useful in other parts of the code that use this library
    uint8_t i2c_write(uint8_t val);
    uint8_t i2c_write(uint8_t cmd, uint8_t *data, uint8_t size, boolean LSB = false);
    uint8_t i2c_read(uint8_t addr);
    uint8_t i2c_read(uint8_t addr, uint8_t *data, uint8_t size);

  private:
    void _updateKeyram();

    KEYDATA _keyram;
    uint8_t _address;
};
#endif

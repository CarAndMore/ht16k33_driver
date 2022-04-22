#ifndef BitCommands_h
#define BitCommands_h
//Commands
#define HT16K33_DDAP          B00000000 // Display data address pointer: 0000xxxx
#define HT16K33_SS            B00100000 // System setup register
#define HT16K33_SS_STANDBY    B00000000 // System setup - oscillator in standby mode
#define HT16K33_SS_NORMAL     B00000001 // System setup - oscillator in normal mode
#define HT16K33_KDAP          B01000000 // Key Address Data Pointer
#define HT16K33_IFAP          B01100000 // Read status of INT flag
#define HT16K33_DSP           B10000000 // Display setup
#define HT16K33_DSP_OFF       B00000000 // Display setup - display off
#define HT16K33_DSP_ON        B00000001 // Display setup - display on
#define HT16K33_DSP_NOBLINK   B00000000 // Display setup - no blink
#define HT16K33_DSP_BLINK2HZ  B00000010 // Display setup - 2hz blink
#define HT16K33_DSP_BLINK1HZ  B00000100 // Display setup - 1hz blink
#define HT16K33_DSP_BLINK05HZ B00000110 // Display setup - 0.5hz blink
#define HT16K33_RIS           B10100000 // ROW/INT Set
#define HT16K33_RIS_OUT       B00000000 // Set INT as row driver output
#define HT16K33_RIS_INTL      B00000001 // Set INT as int active low
#define HT16K33_RIS_INTH      B00000011 // Set INT as int active high
#define HT16K33_DIM           B11100000 // Dimming set
#define HT16K33_DIM_1         B00000000 // Dimming set - 1/16
#define HT16K33_DIM_2         B00000001 // Dimming set - 2/16
#define HT16K33_DIM_3         B00000010 // Dimming set - 3/16
#define HT16K33_DIM_4         B00000011 // Dimming set - 4/16
#define HT16K33_DIM_5         B00000100 // Dimming set - 5/16
#define HT16K33_DIM_6         B00000101 // Dimming set - 6/16
#define HT16K33_DIM_7         B00000110 // Dimming set - 7/16
#define HT16K33_DIM_8         B00000111 // Dimming set - 8/16
#define HT16K33_DIM_9         B00001000 // Dimming set - 9/16
#define HT16K33_DIM_10        B00001001 // Dimming set - 10/16
#define HT16K33_DIM_11        B00001010 // Dimming set - 11/16
#define HT16K33_DIM_12        B00001011 // Dimming set - 12/16
#define HT16K33_DIM_13        B00001100 // Dimming set - 13/16
#define HT16K33_DIM_14        B00001101 // Dimming set - 14/16
#define HT16K33_DIM_15        B00001110 // Dimming set - 15/16
#define HT16K33_DIM_16        B00001111 // Dimming set - 16/16

#endif

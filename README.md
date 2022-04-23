# ht16k33 für Arduino & Co

This library is used to allow an arduino like platform talk to the holtek ht16k33 chip
to do things like turn on/off LEDs or scan keys

[ht16k33 datasheet](https://cdn-shop.adafruit.com/datasheets/ht16K33v110.pdf) by adafruit

![ht16k33](/img/ht16k33_28-SOP.jpg)

![ht16k33](/img/ht16k33.svg)


# Eagle lib & examples

[ht16k33 libraries](/Eagle/HT16k33.lbr)

![ht16k33](/img/ht16k33_lib.jpg)
![ht16k33](/img/ht16k33_modul.jpg)


## LED Matrix 16*8

![ht16k33](/img/ht16k33_16x8_Led_Matrix(150dpi).png)

## keyboard Matrix 13*3

![ht16k33](/img/ht16k33_keyboard(150dpi).png)

# 8x8 Zeichensätze
## C64 Zeichensatztabelle
By mikrocontrolle [jjflash](https://www.mikrocontroller.net/topic/414276)

![ht16k33](https://www.mikrocontroller.net/attachment/313683/font8x8b.bmp)

```cpp
const uint8_t font8x8[][8] = {

  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e},       // Ascii 0 = ' '

  {0xc3,0xa9,0x85,0x85,0xa9,0xc3,0x7e,0x7e},       // Ascii 1 = ' '

  {0xff,0xd7,0xfb,0xfb,0xd7,0xff,0x7e,0x30},       // Ascii 2 = ' '

  {0x78,0x7c,0x3e,0x7c,0x78,0x30,0x00,0x08},       // Ascii 3 = ' '

  {0x1c,0x3e,0x7f,0x3e,0x1c,0x08,0x00,0x1c},       // Ascii 4 = ' '

  {0x1c,0x69,0x7f,0x69,0x1c,0x1c,0x00,0x0c},       // Ascii 5 = ' '

  {0x1c,0x39,0x7f,0x39,0x1c,0x0c,0x00,0x00},       // Ascii 6 = ' '

  {0x00,0x18,0x3c,0x3c,0x18,0x00,0x00,0xff},       // Ascii 7 = ' '

  {0xff,0xe7,0xc3,0xc3,0xe7,0xff,0xff,0x00},       // Ascii 8 = ' '

  {0x3c,0x66,0x42,0x42,0x66,0x3c,0x00,0xff},       // Ascii 9 = ' '

  {0xc3,0x99,0xbd,0xbd,0x99,0xc3,0xff,0x0e},       // Ascii 10 = ' '

  {0x1f,0x11,0x11,0xbf,0xfe,0xe0,0xf0,0x00},       // Ascii 11 = ' '

  {0x72,0xfa,0x8f,0x8f,0xfa,0x72,0x00,0x06},       // Ascii 12 = ' '

  {0x07,0xfb,0xfe,0x60,0x30,0x00,0x00,0x06},       // Ascii 13 = ' '

  {0x07,0xfb,0xfe,0xa6,0xa7,0xfb,0xfe,0x99},       // Ascii 14 = ' '

  {0x5a,0x24,0xc3,0xc3,0x24,0x5a,0x99,0x00},       // Ascii 15 = ' '

  {0xfe,0x7c,0x7c,0x38,0x38,0x10,0x00,0x00},       // Ascii 16 = ' '

  {0x10,0x38,0x38,0x7c,0x7c,0xfe,0x00,0x00},       // Ascii 17 = ' '

  {0x24,0x66,0xff,0xff,0x66,0x24,0x00,0x00},       // Ascii 18 = ' '

  {0xfa,0xfa,0x00,0xfa,0xfa,0x00,0x00,0x60},       // Ascii 19 = ' '

  {0xf0,0xfe,0xfe,0x80,0xfe,0x80,0x00,0x00},       // Ascii 20 = ' '

  {0x59,0xfd,0xa5,0xbf,0x9a,0x00,0x00,0x00},       // Ascii 21 = ' '

  {0x0e,0x0e,0x0e,0x0e,0x0e,0x0e,0x00,0x00},       // Ascii 22 = ' '

  {0x29,0x6d,0xff,0xff,0x6d,0x29,0x00,0x00},       // Ascii 23 = ' '

  {0x20,0x60,0xff,0xff,0x60,0x20,0x00,0x00},       // Ascii 24 = ' '

  {0x04,0x06,0xff,0xff,0x06,0x04,0x00,0x18},       // Ascii 25 = ' '

  {0x18,0x18,0x18,0x18,0x7e,0x3c,0x18,0x18},       // Ascii 26 = ' '

  {0x3c,0x7e,0x18,0x18,0x18,0x18,0x18,0x00},       // Ascii 27 = ' '

  {0x7c,0x7c,0x04,0x04,0x04,0x04,0x00,0x18},       // Ascii 28 = ' '

  {0x3c,0x7e,0x18,0x18,0x7e,0x3c,0x18,0x00},       // Ascii 29 = ' '

  {0x0e,0x1e,0x3e,0x7e,0x3e,0x1e,0x0e,0x00},       // Ascii 30 = ' '

  {0x70,0x78,0x7c,0x7e,0x7c,0x78,0x70,0x00},       // Ascii 31 = ' '

  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},       // Ascii 32 = ' '

  {0x00,0x00,0x00,0xfa,0xfa,0x00,0x00,0x00},       // Ascii 33 = '!'

  {0x00,0xe0,0xe0,0x00,0xe0,0xe0,0x00,0x00},       // Ascii 34 = '"'

  {0x28,0xfe,0xfe,0x28,0xfe,0xfe,0x28,0x00},       // Ascii 35 = '#'

  {0x00,0x24,0x54,0xfe,0xfe,0x54,0x48,0x00},       // Ascii 36 = '$'

  {0x00,0x62,0x66,0x0c,0x18,0x30,0x66,0x46},       // Ascii 37 = '%'

  {0x00,0x0c,0x5e,0xf2,0xba,0xec,0x5e,0x12},       // Ascii 38 = '&'

  {0x00,0x00,0x20,0xe0,0xc0,0x00,0x00,0x00},       // Ascii 39 = '''

  {0x00,0x00,0x38,0x7c,0xc6,0x82,0x00,0x00},       // Ascii 40 = '('

  {0x00,0x00,0x82,0xc6,0x7c,0x38,0x00,0x00},       // Ascii 41 = ')'

  {0x10,0x54,0x7c,0x38,0x38,0x7c,0x54,0x10},       // Ascii 42 = '*'

  {0x00,0x10,0x10,0x7c,0x7c,0x10,0x10,0x00},       // Ascii 43 = '+'

  {0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00},       // Ascii 44 = ','

  {0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x00},       // Ascii 45 = '-'

  {0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00},       // Ascii 46 = '.'

  {0x06,0x0c,0x18,0x30,0x60,0xc0,0x80,0x00},       // Ascii 47 = '/'

  {0x7c,0xfe,0x8a,0x92,0xa2,0xfe,0x7c,0x00},       // Ascii 48 = '0'

  {0x00,0x00,0x40,0xfe,0xfe,0x00,0x00,0x00},       // Ascii 49 = '1'

  {0x00,0x42,0xc6,0x8e,0x9a,0xf2,0x62,0x00},       // Ascii 50 = '2'

  {0x00,0x44,0xc6,0x92,0x92,0xfe,0x6c,0x00},       // Ascii 51 = '3'

  {0x18,0x38,0x68,0xc8,0xfe,0xfe,0x08,0x00},       // Ascii 52 = '4'

  {0x00,0xe4,0xe6,0xa2,0xa2,0xbe,0x9c,0x00},       // Ascii 53 = '5'

  {0x00,0x7c,0xfe,0x92,0x92,0xde,0x4c,0x00},       // Ascii 54 = '6'

  {0x00,0x80,0x80,0x8e,0x9e,0xf0,0xe0,0x00},       // Ascii 55 = '7'

  {0x00,0x6c,0xfe,0x92,0x92,0xfe,0x6c,0x00},       // Ascii 56 = '8'

  {0x00,0x60,0xf2,0x96,0x9c,0xf8,0x70,0x00},       // Ascii 57 = '9'

  {0x00,0x00,0x00,0x36,0x36,0x00,0x00,0x00},       // Ascii 58 = ':'

  {0x00,0x00,0x80,0xb6,0x36,0x00,0x00,0x00},       // Ascii 59 = ';'

  {0x00,0x10,0x38,0x6c,0xc6,0x82,0x00,0x00},       // Ascii 60 = '<'

  {0x00,0x24,0x24,0x24,0x24,0x24,0x24,0x00},       // Ascii 61 = '='

  {0x00,0x82,0xc6,0x6c,0x38,0x10,0x00,0x00},       // Ascii 62 = '>'

  {0x00,0x40,0xc0,0x8a,0x9a,0xf0,0x60,0x00},       // Ascii 63 = '?'

  {0x7c,0xfe,0x82,0xba,0xba,0xfa,0x78,0x00},       // Ascii 64 = '@'

  {0x3e,0x7e,0xc8,0x88,0xc8,0x7e,0x3e,0x00},       // Ascii 65 = 'A'

  {0xfe,0xfe,0x92,0x92,0x92,0xfe,0x6c,0x00},       // Ascii 66 = 'B'

  {0x38,0x7c,0xc6,0x82,0x82,0xc6,0x44,0x00},       // Ascii 67 = 'C'

  {0xfe,0xfe,0x82,0x82,0xc6,0x7c,0x38,0x00},       // Ascii 68 = 'D'

  {0xfe,0xfe,0x92,0x92,0x92,0x82,0x82,0x00},       // Ascii 69 = 'E'

  {0xfe,0xfe,0x90,0x90,0x90,0x80,0x80,0x00},       // Ascii 70 = 'F'

  {0x38,0x7c,0xc6,0x82,0x8a,0xce,0x4e,0x00},       // Ascii 71 = 'G'

  {0xfe,0xfe,0x10,0x10,0x10,0xfe,0xfe,0x00},       // Ascii 72 = 'H'

  {0x00,0x82,0xfe,0xfe,0x82,0x00,0x00,0x00},       // Ascii 73 = 'I'

  {0x0c,0x0e,0x02,0x02,0x02,0xfe,0xfc,0x00},       // Ascii 74 = 'J'

  {0xfe,0xfe,0x90,0xb8,0x6c,0xc6,0x82,0x00},       // Ascii 75 = 'K'

  {0xfe,0xfe,0x02,0x02,0x02,0x02,0x02,0x00},       // Ascii 76 = 'L'

  {0xfe,0xfe,0x60,0x30,0x60,0xfe,0xfe,0x00},       // Ascii 77 = 'M'

  {0xfe,0xfe,0x60,0x30,0x18,0xfe,0xfe,0x00},       // Ascii 78 = 'N'

  {0x38,0x7c,0xc6,0x82,0xc6,0x7c,0x38,0x00},       // Ascii 79 = 'O'

  {0xfe,0xfe,0x90,0x90,0x90,0xf0,0x60,0x00},       // Ascii 80 = 'P'

  {0x38,0x7c,0xc6,0x8a,0xcc,0x76,0x3a,0x00},       // Ascii 81 = 'Q'

  {0xfe,0xfe,0x90,0x90,0x98,0xfe,0x66,0x00},       // Ascii 82 = 'R'

  {0x64,0xf6,0x92,0x92,0x92,0xde,0x4c,0x00},       // Ascii 83 = 'S'

  {0x80,0x80,0xfe,0xfe,0x80,0x80,0x00,0x00},       // Ascii 84 = 'T'

  {0xfc,0xfe,0x02,0x02,0x02,0xfe,0xfc,0x00},       // Ascii 85 = 'U'

  {0xf8,0xfc,0x06,0x02,0x06,0xfc,0xf8,0x00},       // Ascii 86 = 'V'

  {0xfe,0xfe,0x0c,0x18,0x0c,0xfe,0xfe,0x00},       // Ascii 87 = 'W'

  {0xc6,0xee,0x38,0x10,0x38,0xee,0xc6,0x00},       // Ascii 88 = 'X'

  {0x00,0xe0,0xf0,0x1e,0x1e,0xf0,0xe0,0x00},       // Ascii 89 = 'Y'

  {0x82,0x86,0x8e,0x9a,0xb2,0xe2,0xc2,0x00},       // Ascii 90 = 'Z'

  {0x00,0x00,0xfe,0xfe,0x82,0x82,0x00,0x00},       // Ascii 91 = '['

  {0x80,0xc0,0x60,0x30,0x18,0x0c,0x06,0x00},       // Ascii 92 = '\'

  {0x00,0x00,0x82,0x82,0xfe,0xfe,0x00,0x00},       // Ascii 93 = ']'

  {0x00,0x10,0x30,0x60,0xc0,0x60,0x30,0x10},       // Ascii 94 = '^'

  {0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01},       // Ascii 95 = '_'

  {0x00,0x00,0x80,0xc0,0x60,0x20,0x00,0x00},       // Ascii 96 = '`'

  {0x04,0x2e,0x2a,0x2a,0x2a,0x3e,0x1e,0x00},       // Ascii 97 = 'a'

  {0xfe,0xfe,0x22,0x22,0x22,0x3e,0x1c,0x00},       // Ascii 98 = 'b'

  {0x1c,0x3e,0x22,0x22,0x22,0x36,0x14,0x00},       // Ascii 99 = 'c'

  {0x1c,0x3e,0x22,0x22,0x22,0xfe,0xfe,0x00},       // Ascii 100 = 'd'

  {0x1c,0x3e,0x2a,0x2a,0x2a,0x3a,0x18,0x00},       // Ascii 101 = 'e'

  {0x10,0x7e,0xfe,0x90,0x90,0xc0,0x40,0x00},       // Ascii 102 = 'f'

  {0x19,0x3d,0x25,0x25,0x25,0x3f,0x3e,0x00},       // Ascii 103 = 'g'

  {0xfe,0xfe,0x20,0x20,0x20,0x3e,0x1e,0x00},       // Ascii 104 = 'h'

  {0x00,0x00,0x00,0xbe,0xbe,0x00,0x00,0x00},       // Ascii 105 = 'i'

  {0x02,0x03,0x01,0x01,0xbf,0xbe,0x00,0x00},       // Ascii 106 = 'j'

  {0xfe,0xfe,0x08,0x08,0x1c,0x36,0x22,0x00},       // Ascii 107 = 'k'

  {0x00,0x00,0x00,0xfe,0xfe,0x00,0x00,0x00},       // Ascii 108 = 'l'

  {0x1e,0x3e,0x30,0x18,0x30,0x3e,0x1e,0x00},       // Ascii 109 = 'm'

  {0x3e,0x3e,0x20,0x20,0x20,0x3e,0x1e,0x00},       // Ascii 110 = 'n'

  {0x1c,0x3e,0x22,0x22,0x22,0x3e,0x1c,0x00},       // Ascii 111 = 'o'

  {0x3f,0x3f,0x24,0x24,0x24,0x3c,0x18,0x00},       // Ascii 112 = 'p'

  {0x18,0x3c,0x24,0x24,0x24,0x3f,0x3f,0x00},       // Ascii 113 = 'q'

  {0x3e,0x3e,0x20,0x20,0x20,0x30,0x10,0x00},       // Ascii 114 = 'r'

  {0x12,0x3a,0x2a,0x2a,0x2a,0x2e,0x04,0x00},       // Ascii 115 = 's'

  {0x20,0xfc,0xfe,0x22,0x22,0x26,0x04,0x00},       // Ascii 116 = 't'

  {0x3c,0x3e,0x02,0x02,0x02,0x3e,0x3e,0x00},       // Ascii 117 = 'u'

  {0x38,0x3c,0x06,0x02,0x06,0x3c,0x38,0x00},       // Ascii 118 = 'v'

  {0x3c,0x3e,0x06,0x0c,0x06,0x3e,0x3c,0x00},       // Ascii 119 = 'w'

  {0x22,0x36,0x1c,0x08,0x1c,0x36,0x22,0x00},       // Ascii 120 = 'x'

  {0x39,0x3d,0x05,0x05,0x05,0x3f,0x3e,0x00},       // Ascii 121 = 'y'

  {0x00,0x22,0x26,0x2e,0x3a,0x32,0x22,0x00},       // Ascii 122 = 'z'

  {0x00,0x10,0x10,0x7c,0xee,0x82,0x82,0x00},       // Ascii 123 = '{'

  {0x00,0x00,0x00,0xee,0xee,0x00,0x00,0x00},       // Ascii 124 = '|'

  {0x00,0x82,0x82,0xee,0x7c,0x10,0x10,0x00},       // Ascii 125 = '}'

  {0x00,0x40,0x80,0x80,0x40,0x40,0x80,0x00},       // Ascii 126 = '~'

  {0x0e,0x1e,0x32,0x62,0x62,0x32,0x1e,0x0e},       // Ascii 127 = ' '

};

```

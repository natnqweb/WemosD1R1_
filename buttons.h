#ifndef buttons_h
#define buttons_h

#define D0 3
#define RX D0

#define D1 1
#define TX D1

#define D2 16

#define D3 5

#define D4 4

#define D5 14

#define D6 12

#define D7 13

#define D8 0

#define D9 2
#define BOARD_LED D9

#define D10 15
//custom  constants
#define nopress 30
#define selected 31
#define left 32
#define down 33
#define up 34
#define right 35
#define buttons_pin A0
#define homescreen 36
#define screen2 37
//custom  constants

//link A-pin

#include <LiquidCrystal.h>
LiquidCrystal lcd(D8, D9, D4, D5, D6, D7);
uint8_t view_mode = homescreen;

#endif
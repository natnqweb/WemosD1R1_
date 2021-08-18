#include "buttons.h"
//#include <Simpletimer.h> //you can find it in my repo it's fine way to manage all tasks
//Simpletimer refresh1;
uint8_t currentButtonPressed;
uint8_t get_button_pressed()//this is where you might need to make some edit becouse we work on 3.3 voltage on esp8266 this readings might looks diffrent depend on keypadshield version
{// for me numbers of buttons reduced to left down up right becouse the voltage surpassed 3.3 volts(at least i assume that's the case ) on select 
    int val = analogRead(buttons_pin);
    if (val > 600 && val <= 750)
        return left;
    else if (val > 400 && val <= 600)
        return down;
    else if (val > 100 && val <= 400)
        return up;
   // else if (vall > ---- %% val < ----- )// edit that for yourself when you figure out what the readings are, you might need to add resistors
      //  return select
    else if (val >= 0 && val <= 100)
        return right;
    else
        return nopress;
}
void setup()
{

    pinMode(buttons_pin, INPUT);

    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.print("hello world");
    delay(1000);
    lcd.noDisplay();
    delay(1000);
    lcd.display();
}
void readbuttons()
{
    //if (refresh1.timer(200))
    //{
        currentButtonPressed = get_button_pressed();
    //}
}
void loop()
{

    lcd.setCursor(0, 0);
    readbuttons();

    switch (currentButtonPressed)
    {
    case up:
        lcd.clear();
        view_mode == homescreen ? view_mode = screen2, lcd.clear() : lcd.clear();

        break;
    case down:

        view_mode == screen2 ? view_mode = homescreen, lcd.clear() : lcd.clear();

        break;
    case left:

        break;
    case right:

        break;

    default:

        switch (view_mode)
        {
        case screen2:
            lcd.printf("screen2:%d", screen2);
            break;

        default:
            lcd.printf("homescreen: %d", homescreen);

            break;
        }
        break;
    }
}

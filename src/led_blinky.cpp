#include <Arduino.h>
#include "software_timer.h"
#include "led_blinky.h"
static int state = INIT;
void LED_Blinky(void) {
    switch (state) {
        case INIT:
            pinMode(GPIO_NUM_48, OUTPUT);
            Set_Timer(0, 100);
            state = LED_ON;
            digitalWrite(GPIO_NUM_48, 1);
            break;

        case LED_ON:
            if (Is_Timer_Expired(0) != 1) {break;}

            Set_Timer(0, 100);
            state = LED_OFF;
            digitalWrite(GPIO_NUM_48, 0);
            break;

        case LED_OFF:
            if (Is_Timer_Expired(0) != 1) {break;}

            Set_Timer(0, 100);
            state = LED_ON;
            digitalWrite(GPIO_NUM_48, 1);
            break;
    }
}
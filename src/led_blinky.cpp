#include "led_blinky.h"
#include <Arduino.h>

void LED_Blinky(void) {
    static bool ledState = LOW;
    digitalWrite(GPIO_NUM_48, ledState);
    ledState = !ledState;
}
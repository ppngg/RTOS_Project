#include "heater.h"
#include "htsensor.h"
#include "software_timer.h"
#include <iostream>
// GPIO_NUM_6 -> D3
// GPIO_NUM_7 -> D4
static int state = HEATER_INIT;

void Heater_Run(void) {    
    switch (state) {
        case HEATER_INIT:
            pinMode(GPIO_NUM_6, OUTPUT);  // D3
            pinMode(GPIO_NUM_7, OUTPUT);  // D4
            digitalWrite(GPIO_NUM_6, 0);
            digitalWrite(GPIO_NUM_7, 0);
            Set_Timer(3, 100);
            state = HEATER_GREEN;
            break;

        case HEATER_GREEN:
            if (Is_Timer_Expired(3) != 1) {break;}
            Set_Timer(3, 100);
            digitalWrite(GPIO_NUM_6, 1);
            digitalWrite(GPIO_NUM_7, 0);
            
            // Check for transitions
            if (currentTemperature >= TEMP_LOW && currentTemperature <= TEMP_HIGH) {
                state = HEATER_YELLOW;
            }
            else if (currentTemperature> TEMP_HIGH) {
                state = HEATER_RED;
            }
            break;

        case HEATER_YELLOW:
            if (Is_Timer_Expired(3) != 1) {break;}
            Set_Timer(3, 100);
            digitalWrite(GPIO_NUM_6, 0);
            digitalWrite(GPIO_NUM_7, 1);
            if (currentTemperature < TEMP_LOW) {
                state = HEATER_GREEN;
            }
            else if (currentTemperature > TEMP_HIGH) {
                state = HEATER_RED;
            }
            break;

        case HEATER_RED:
            if (Is_Timer_Expired(3) != 1) {break;}
            Set_Timer(3, 100);
            digitalWrite(GPIO_NUM_6, 1);
            digitalWrite(GPIO_NUM_7, 1);
            
            // Check for transitions
            if (currentTemperature < TEMP_LOW) {
                state = HEATER_GREEN;
            }
            else if (currentTemperature >= TEMP_LOW && currentTemperature <= TEMP_HIGH) {
                state = HEATER_YELLOW;
            }
        break;
    }
}
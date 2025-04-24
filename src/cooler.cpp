#include "cooler.h"
#include "htsensor.h"
#include "software_timer.h"

static int state = COOLER_INIT;

void Cooler_Run(void) {
    switch (state) {
        case COOLER_INIT:
            pinMode(GPIO_NUM_8, OUTPUT);
            pinMode(GPIO_NUM_9, OUTPUT);
            digitalWrite(GPIO_NUM_8, 0);
            digitalWrite(GPIO_NUM_9, 0);
            Set_Timer(2, 100);
            state = COOLER_OFF;
            break;

        case COOLER_OFF:
            if (Is_Timer_Expired(2) != 1) {break;}
            Set_Timer(2, 100);
            digitalWrite(GPIO_NUM_8, 0);
            digitalWrite(GPIO_NUM_9, 0);
            if (currentTemperature > COOLER_TEMP_THRESHOLD) {
                state = COOLER_ON;
            }
            break;

        case COOLER_ON:
            if (Is_Timer_Expired(2) != 1) {break;}
            Set_Timer(2, COOLING_DURATION);
            state = COOLER_OFF;
            digitalWrite(GPIO_NUM_8, 1);
            digitalWrite(GPIO_NUM_9, 0);
            break;
    }
}

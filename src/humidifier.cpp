#include "humidifier.h"
#include "htsensor.h"
#include "software_timer.h"

static int state = HUM_INIT;

void Humidifier_Run(void) {
    switch (state) {
        case HUM_INIT:
            pinMode(GPIO_NUM_10, OUTPUT);
            pinMode(GPIO_NUM_17, OUTPUT);
            Set_Timer(4, 100);
            state = HUM_OFF;
            break;

        case HUM_OFF:
            if (Is_Timer_Expired(4) != 1) {break;}
            Set_Timer(4, 100);
            digitalWrite(GPIO_NUM_10, 0);
            digitalWrite(GPIO_NUM_17, 0);
            
            if (currentHumidity < HUMIDITY_THRESHOLD) {
                state = HUM_GREEN;
            }
            break;

        case HUM_GREEN:
            if (Is_Timer_Expired(4) != 1) {break;}
            Set_Timer(4, 500);
            state = HUM_YELLOW;
            digitalWrite(GPIO_NUM_10, 1);
            digitalWrite(GPIO_NUM_17, 0);
            break;

        case HUM_YELLOW:
            if (Is_Timer_Expired(4) != 1) {break;}
            Set_Timer(4, 300);
            state = HUM_RED;
            digitalWrite(GPIO_NUM_10, 0);
            digitalWrite(GPIO_NUM_17, 1);
            break;

        case HUM_RED:
            if (Is_Timer_Expired(4) != 1){break;}
            Set_Timer(4, 200);
            state = HUM_OFF;
            digitalWrite(GPIO_NUM_10, 1);
            digitalWrite(GPIO_NUM_17, 1);
            break;
    }
} 
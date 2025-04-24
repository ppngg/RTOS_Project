#ifndef HTSENSOR_H
#define HTSENSOR_H

#include <Arduino.h>
#include "DHT20.h"

#define HT_INIT 0
#define HT_IDLE 1
#define HT_READING 2

void HTSensor_Run(void);
extern float currentTemperature;
extern float currentHumidity;
void LED_Blinky(void);

#endif
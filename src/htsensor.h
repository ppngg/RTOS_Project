#ifndef HTSENSOR_H
#define HTSENSOR_H

#include <Arduino.h>
#include "DHT20.h"
void HTSensor_Init(void);
void HTSensor_Read(void);
extern float currentTemperature;
extern float currentHumidity;

void LED_Blinky(void);

#endif
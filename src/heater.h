#ifndef HEATER_H
#define HEATER_H

#include <Arduino.h>
#define TEMP_MIN 15.0
#define TEMP_SAFE_MIN 20.0
#define TEMP_SAFE_MAX 35.0

void Heater_Init(void);
void Heater_Run(void);

#endif

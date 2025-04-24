#ifndef HEATER_H
#define HEATER_H

#include <Arduino.h>

// Temperature thresholds
#define TEMP_LOW 15.0
#define TEMP_HIGH 30.0

// States for heater state machine
#define HEATER_INIT 0
#define HEATER_GREEN 1
#define HEATER_YELLOW 2
#define HEATER_RED 3 

void Heater_Run(void);

#endif

#ifndef COOLER_H
#define COOLER_H
#include <Arduino.h>

#define COOLER_TEMP_THRESHOLD 30.0
#define COOLING_DURATION 500
#define COOLER_INIT 0
#define COOLER_OFF 1
#define COOLER_ON 2

void Cooler_Run(void);

#endif

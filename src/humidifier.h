#ifndef HUMIDIFIER_H
#define HUMIDIFIER_H

#include <Arduino.h>

#define HUMIDITY_THRESHOLD 65.0 // Activate if humidity < 65

#define HUM_INIT 0
#define HUM_OFF 1
#define HUM_GREEN 2
#define HUM_YELLOW 3
#define HUM_RED 4

void Humidifier_Run(void);

#endif
#include "heater.h"
#include "htsensor.h"
#include <iostream>
// GPIO_NUM_6 -> D3
// GPIO_NUM_7 -> D4
void Heater_Init(void) {
    pinMode(GPIO_NUM_6, OUTPUT);
    pinMode(GPIO_NUM_7, OUTPUT);
    digitalWrite(GPIO_NUM_6, 0);
    digitalWrite(GPIO_NUM_7, 0);
}

void Heater_Run(void) {
    float temp = currentTemperature;
    std::cout << "Current temp: " << temp << "\n";
    if (temp >= TEMP_SAFE_MIN && temp <= TEMP_SAFE_MAX) {
        // Safe range: GREEN
        digitalWrite(GPIO_NUM_6, 1);
        digitalWrite(GPIO_NUM_7, 0);
    } 
    else if (temp >= TEMP_MIN && temp < TEMP_SAFE_MIN) {
        // Warning range: ORANGE
        digitalWrite(GPIO_NUM_6, 0);
        digitalWrite(GPIO_NUM_7, 1);
    }
    else {
        // Danger range: RED
        digitalWrite(GPIO_NUM_6, 1);
        digitalWrite(GPIO_NUM_7, 1);
    }
}

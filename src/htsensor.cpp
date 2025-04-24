#include "htsensor.h"
#include <Arduino.h>
#include <Wire.h>
#include "software_timer.h"

float currentTemperature = 0.0;
float currentHumidity = 0.0;

DHT20 dht20;
static int state = HT_INIT;

void HTSensor_Run(void) {
    switch (state) {
        case HT_INIT:
            Serial.begin(115200);   
            Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
            Set_Timer(1, 100);
            if (dht20.begin()) {
                Serial.println("DHT20 sensor initialized successfully!");
                state = HT_IDLE;
            } else {
                Serial.println("Failed to initialize DHT20 sensor!");
                break;
            }
            break;

        case HT_IDLE:
            if (Is_Timer_Expired(1) != 1) {break;}
            Set_Timer(1,100);
            state = HT_READING;
            break;

        case HT_READING:
        {
            if (Is_Timer_Expired(1) != 1) {break;}
            Set_Timer(1, 500);
            state = HT_IDLE;
            dht20.read();
            currentTemperature = dht20.getTemperature();
            currentHumidity = dht20.getHumidity();
            Serial.print("Temperature: ");
            Serial.print(currentTemperature);
            Serial.print("°C\t");
            Serial.print("Humidity: ");
            Serial.print(currentHumidity);
            Serial.println("%");
            break;
        }
    }
}
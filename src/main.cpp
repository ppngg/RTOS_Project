#include <Arduino.h>
#include "software_timer.h"
#include "scheduler.h"
#include "led_blinky.h"
#include "htsensor.h"
#include "humidifier.h"
#include "cooler.h"
#include "heater.h"
#include <Wire.h>
#include "state_machine.h"

void TIMER_ISR(void *pvParameters) {
  while (1) {
    SCH_Update();
    vTaskDelay(pdMS_TO_TICKS(10)); // 10ms tick
  }
}

void setup() {
    Serial.begin(115200);
    pinMode(GPIO_NUM_48, OUTPUT); // Initialize LED pin
    
    // Initialize sensors and devices
    HTSensor_Init();
    Heater_Init();
    
    SCH_Init();
    SCH_Add_Task(Timer_Run, 0, 1);
    SCH_Add_Task(LED_Blinky, 0, 100);
    SCH_Add_Task(HTSensor_Read, 0, 500); // Read every 5 seconds (500 ticks * 10ms = 5000ms)
    SCH_Add_Task(Heater_Run, 0, 100); // Check heater status every second
    // SCH_Add_Task(Humidifier_Run, 0, 1);
    // SCH_Add_Task(Cooler_Run, 0, 1);
    
    Serial.println("System initialized successfully!");
}

void loop() {
  SCH_Update();
  SCH_Dispatch_Tasks();
  delay(10);
}
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
    SCH_Init();
    SCH_Add_Task(Timer_Run, 0, 1);
    SCH_Add_Task(LED_Blinky, 0, 100);
    SCH_Add_Task(HTSensor_Run, 0, 500);
    SCH_Add_Task(Heater_Run, 0, 100);
    SCH_Add_Task(Cooler_Run, 0, 100);
    SCH_Add_Task(Humidifier_Run, 0, 100);
}

void loop() {
  SCH_Update();
  SCH_Dispatch_Tasks();
  delay(10);
}
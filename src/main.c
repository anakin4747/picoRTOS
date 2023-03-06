#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>

#include "pico/stdlib.h"

#define LED_PIN 25
#define GPIO_ON 1
#define GPIO_OFF 0

void GreenLEDTask(void);


int main(void){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    TaskHandle_t gLEDtask = NULL;

    uint32_t status = xTaskCreate(GreenLEDTask, 
                        "Green LED", 1024, NULL,
                        tskIDLE_PRIORITY, &gLEDtask);

    vTaskStartScheduler();

    while(true){
    }
}

void GreenLEDTask(void){
    while(1){
        gpio_put(LED_PIN, GPIO_ON);
        vTaskDelay(100);
        gpio_put(LED_PIN, GPIO_OFF);
        vTaskDelay(100);
    }
}

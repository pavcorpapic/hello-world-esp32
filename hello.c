#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_16

void app_main() {
    gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_PIN, 1); // Turn the LED on
        vTaskDelay(500 / portTICK_PERIOD_MS); 
        gpio_set_level(LED_PIN, 0); // Turn the LED off
        vTaskDelay(500 / portTICK_PERIOD_MS); 
    }
}

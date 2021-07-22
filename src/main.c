#include <driver/gpio.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "sdkconfig.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "dispFuncs.h"
#include "wifiFuncs.h"

// LED
#define BLINK_GPIO 25

static const char *TAG = "main";


void initPins() {

  // set onboard led pin to output and off
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_level(BLINK_GPIO, 0u);
    ESP_LOGI(TAG, "Init of gpio pins done");
}

static void main_task(void *param) {

  while (1) {
    //  printStrToDisp("Turning on LED");
    gpio_set_level(BLINK_GPIO, 1);
    vTaskDelay(500u / portTICK_PERIOD_MS);
    // printStrToDisp("Turning off LED");
    gpio_set_level(BLINK_GPIO, 0);
    vTaskDelay(500u / portTICK_PERIOD_MS);
  }
  return;
}

void app_main() {

  // Init pins
  (void) initPins();

  // Init the oled display
  (void) initDisplay();

  // Init NVS
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES ||
      ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  // Connect to AP
  (void) initWifiStation();

  // Print Ip to display
  // char buff[20];
  //memset(buff, 0, 20);
  //sprintf(buff, IPSTR, IP2STR(&apl_ip_info.ip));
  //(void) printStrToDisp(buff);
  
  // main thread
  xTaskCreate(main_task, "main task", 4096, NULL, 5, NULL);
}

#ifndef DISPFUNCS_H
#define DISPFUNCS_H

#include <u8g2.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include <string.h>

#include "sdkconfig.h"
#include "u8g2_esp32_hal.h"

// SDA - GPIO4
#define PIN_SDA 4

// SCL - GPIO15
#define PIN_SCL 15

// OLED - RESET
#define PIN_OLED_RST 16

void initDisplay();

void printStrToDisp(const char *str);

#endif

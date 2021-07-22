#include "dispFuncs.h"

static const char *TAG = "display";

static u8g2_t u8g2;

void initDisplay() {
  // init hardware abstraction layer for oled display

  u8g2_esp32_hal_t u8g2_esp32_hal = U8G2_ESP32_HAL_DEFAULT;
  u8g2_esp32_hal.reset = PIN_OLED_RST;
  u8g2_esp32_hal.sda = PIN_SDA;
  u8g2_esp32_hal.scl = PIN_SCL;
  u8g2_esp32_hal_init(u8g2_esp32_hal);

  u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8g2_esp32_i2c_byte_cb,
                                         u8g2_esp32_gpio_and_delay_cb);
  u8x8_SetI2CAddress(&u8g2.u8x8, 0x78);

  ESP_LOGI(TAG, "u8g2_InitDisplay");
  u8g2_InitDisplay(&u8g2); // send init sequence to the display, display is in
                           // sleep mode after this,

  ESP_LOGI(TAG, "u8g2_SetPowerSave");
  u8g2_SetPowerSave(&u8g2, 0); // wake up display
  ESP_LOGI(TAG, "u8g2_ClearBuffer");
  u8g2_ClearBuffer(&u8g2);
  ESP_LOGI(TAG, "u8g2_SetFont");
  u8g2_SetFont(&u8g2, u8g2_font_ncenB14_tr);
  ESP_LOGI(TAG, "u8g2_SendBuffer");
  u8g2_SendBuffer(&u8g2);
  ESP_LOGI(TAG, "OLED init done.");
}

void printStrToDisp(const char *str) {

  u8g2_ClearBuffer(&u8g2);
  u8g2_DrawStr(&u8g2, 2,17, str);
  u8g2_SendBuffer(&u8g2);
  
  return;
}

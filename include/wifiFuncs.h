#ifndef WIFIFUNCS_H
#define WIFIFUNCS_H

#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>
#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"


#define EXAMPLE_ESP_WIFI_SSID      "TP-LINK_2E9E9A"
#define EXAMPLE_ESP_WIFI_PASS      "Weingaertnerhaeuschen54"
#define EXAMPLE_ESP_MAXIMUM_RETRY  5

// This structure hold information about the ip, netmask and gateway
extern esp_netif_ip_info_t apl_ip_info;

void initWifiStation();

#endif

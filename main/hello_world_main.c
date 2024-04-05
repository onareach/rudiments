/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
/*
* The following #include statements are pre-processor directives. In English, they are
* instructions to the C compiler (in this case, CMake) to include the functions
* in the files listed. */
/*
* stdio is short for "standard IO". This file includes the printf function below.
* The standard library file included below <stdio.h> is found in /Library/Developer/CommandLineTools/SDKs/ 
* MacOSX12.3.sdk/System/Library/Frameworks/Kernel.framework/Versions/A/Headers/sys */
#include <stdio.h>
// #include <inttypes.h>
/* sdkconfig.h found in /Users/davidlong/esp32_projects/esp-idf/components/nvs_flash/test_nvs_host */
// #include "sdkconfig.h"
/* FreeRTOS.h found in /Users/davidlong/esp/v5.2.1/esp-idf/components/freertos/FreeRTOS-Kernel/include/freertos */
#include "freertos/FreeRTOS.h"
/* task.h found in /Users/davidlong/esp/v5.2.1/esp-idf/components/freertos/FreeRTOS-Kernel/include/freertos */
// #include "freertos/task.h" // None of the code in this file requires the freertos/task.h header.
/* esp_chip_info.h found in /Users/davidlong/esp32_projects/esp-idf/components/esp_hw_support/include */
// #include "esp_chip_info.h"
/* esp_flash.h found in /Users/davidlong/esp32_projects/esp-idf/components/spi_flash/include */
/* esp_flash.h also found in /Users/davidlong/esp/v5.2.1/esp-idf/components/esp_rom/include/esp32c2 */
// #include "esp_flash.h"
/* esp_system.h found in /Users/davidlong/esp32_projects/esp-idf/examples/build_system/cmake/
*  idf_as_lib/stubs/esp32 */
/* esp_system.h also found in /Users/davidlong/esp/v5.2.1/esp-idf/components/esp_system/include */
// #include "esp_system.h"

void app_main(void)
{
    printf("Hello, World!\n");

/*
    //Print chip information
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
*/
 /*   printf("This is an %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");
*/
/*    
    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("Silicon revision v%d.%d, ", major_rev, minor_rev);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }
*/
/*
    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());
*/
    printf("Pausing for 15 seconds before restarting.\n");
    vTaskDelay(15000 / portTICK_PERIOD_MS); // portTICK_PERIOD_MS is in FreeRTOS.h.

/*
    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS); // portTICK_PERIOD_MS is in FreeRTOS.h.
    }
*/
    printf("Restarting now.\n");
    //fflush(stdout); // Function from <stdio.h>. This makes sure the buffer prints immediately,
                    // even if the buffer is not full or there is no new line character in it.
    esp_restart();
}

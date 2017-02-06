#ifndef WBLE_H_
#define WBLE_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>


typedef struct {
    uint32_t connect_connection_interval_min;
    uint32_t connect_connection_interval_max;
    uint32_t scan_interval;
    uint32_t scan_window;
} wble_cfg_t;

int wble_init(void);

bool wble_get_cfg(uint8_t param_tag, uint8_t *resp_str, uint8_t *resp_str_len);
bool wble_set_cfg(uint8_t param_tag, uint8_t param_value);

#endif // WBLE_H
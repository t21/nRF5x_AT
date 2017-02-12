#ifndef WBLE_H_
#define WBLE_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "ble_gap.h"

typedef enum {
    WBLE_DISCOVERY_TYPE_ALL_ONCE = 1,
    WBLE_DISCOVERY_TYPE_GENERAL_ONCE,
    WBLE_DISCOVERY_TYPE_LIMITED_ONCE,
    WBLE_DISCOVERY_TYPE_ALL_ALWAYS
} wble_discovery_type_t;

typedef enum {
    WBLE_SCAN_MODE_ACTIVE = 1,
    WBLE_SCAN_MODE_PASSIVE
} wble_scan_mode_t;

typedef struct {
    uint32_t connect_connection_interval_min;
    uint32_t connect_connection_interval_max;
    uint32_t scan_interval;
    uint32_t scan_window;
} wble_cfg_t;

typedef enum {
    WBLE_EVT_ADV_RECEIVED,
    WBLE_EVT_SCAN_TIMEOUT,
} wble_evt_t;

typedef struct {
    union {
        ble_gap_evt_adv_report_t adv_report;
        uint8_t hej;
    };
} wble_evt_data_t;

typedef void (* wble_evt_handler_t)(wble_evt_t evt, ble_gap_evt_adv_report_t *adv_report);

int wble_init(void);

bool wble_get_cfg(uint8_t param_tag, uint8_t *resp_str, uint8_t *resp_str_len);
bool wble_set_cfg(uint8_t param_tag, uint8_t param_value);

//bool wble_scan_discovery_type_set(wble_discovery_type_t discovery_type);
//bool wble_scan_mode_set(wble_scan_mode_t mode);
bool wble_scan_start(uint8_t discovery_type, wble_scan_mode_t mode, uint16_t discovery_length, wble_evt_handler_t evt_handler);

#endif // WBLE_H
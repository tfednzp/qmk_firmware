#pragma once
#include "ridingqwerty.h"

#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

enum userspace_custom_keycodes {
    VERSION = PLACEHOLDER_SAFE_RANGE,
    QWERTY,
    DVORAK,
    COLEMAK,
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
    GREEK,
    RUSSIAN,
    HIRAGAN,
    RUNES,
#endif
    MAKE,
    FLAG,
    RG_QUOT,
    TESTY,
    GRIND,
    NICE,
    RNGWORD,
    CCCV,
    LISTEN,
    SEED,
    SARCASM,
    VAPORWV,
    STRAYA,
    RUSTY,
    FUEL,
    C0RE,
    MUNKY,
    AR1ST,
    VAXIS,
    OS_LAB,
    CDLOCAL,
    SYSNOC,
    NEW_SAFE_RANGE // start new keyboard-level declarations with NEW_SAFE_RANGE
};

typedef union {
    struct {
        uint8_t aesthetic : 1,
                spongebob : 1,
                uppercase : 1,
                australia : 1,
                unusued   : 4;
    };
    uint8_t all;
} mode_config_t;

extern mode_config_t mode;

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
#ifdef UNICODEMAP_ENABLE
    GREEK,
    RUSSIAN,
    HIRAGANA,
    RUNES,
#endif
    MAKE,
    FLAG,   // todo: reading/displaying mod status -- two keys maybe?
    RG_QUOT,
    TESTY,  // send whatever
    GRIND,  // send command to repeatedly build (but not flash) keymap
    NICE,
    ALT_COMM,
    TEST_LBRC,
    CCCV,
// do a secrets include guard here -- compactify/obsucre?
    RUSTY,
    FUEL,
    C0RE,
    MUNKY,
    AR1ST,
    VAXIS,
    OS_LAB,
    CDLOCAL,
    SYSNOC,
// end secret include guard
    NEW_SAFE_RANGE // start new keyboard-level declarations at NEW_SAFE_RANGE
};

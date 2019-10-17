#include <stdio.h>
#include "ridingqwerty.h"


__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

//uint32_t test_number = 12345;
double test_number = 12.345;

//uint16_t user_mod_state;
uint8_t user_mod_state;
uint16_t user_key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  //uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  switch(keycode) {
    case VERSION:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR(QMK_KEYBOARD ":" QMK_KEYMAP "\nVersion:" QMK_VERSION ", built: " QMK_BUILDDATE), MACRO_TIMER);
      }
      return false; break;
    case QWERTY ... COLEMAK:
#ifdef UNICODE_ENABLE
    case GREEK ... HIRAGANA:
    //case GREEK ... RUNES:
#endif
      if (record->event.pressed) {
        set_single_persistent_default_layer(keycode - QWERTY);
      }
      return false; break;
    case MAKE:
      if (record->event.pressed) {
	send_string_with_delay_P(PSTR("sleep 1 && "), MACRO_TIMER);
        send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), MACRO_TIMER);
#if defined(__arm__)
        //send_string_with_delay_P(PSTR(":flash"), MACRO_TIMER);
        send_string_with_delay_P(PSTR(":dfu-util"), MACRO_TIMER);
#elif defined(BOOTLOADER_HALFKAY)
        send_string_with_delay_P(PSTR(":teensy"), MACRO_TIMER);
#endif
	send_string_with_delay_P(PSTR("\n"), MACRO_TIMER);
	//send_string_with_delay_P(PSTR(" && sleep 2\n"), MACRO_TIMER);
        reset_keyboard();
      }
      return false; break;
    case FLAG:
      if (!record->event.pressed) {
        //send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        //SEND_STRING(BOOTLOADER);
        //user_mod_state = get_mods();
        if(get_mods()&(MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))) { dprintf("shift held\n"); }
        dprintf("FLAG PRESSED, DEBUG IS ENABLED!!\n");
      }
      return false; break;
    case GRIND:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR("while true; do make " QMK_KEYBOARD ":" QMK_KEYMAP " && sleep 2 && echo \"build\nsuccessful\" | toilet && sleep 1 && clear; done"), MACRO_TIMER);
      }
      return false; break;
    case RG_QUOT:
      if (record->event.pressed) {
        user_key_timer = timer_read();
        layer_on(_NUMBER);
        register_mods(MOD_BIT(KC_RGUI));
      } else {
        unregister_mods(MOD_BIT(KC_RGUI));
        layer_off(_NUMBER);
	if (timer_elapsed(user_key_timer) < TAPPING_TERM) {
          register_code(KC_QUOT);
	  unregister_code(KC_QUOT);
	}
      }
      return false; break;
    case TESTY:
      if (record->event.pressed) {
      //send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
      //tap_random_base64();
      //dprintf(" < that shit was random\n");
      //SEND_STRING(user_mod_state);
      //send_string(test_number);
	/*
        int length = snprintf( NULL, 0, "%f", test_number );
        //int length = snprintf( NULL, 0, "%lu", test_number );
	char* str = malloc( length + 1 );
        //snprintf( str, length + 1, "%lu", test_number );
        snprintf( str, length + 1, "%f", test_number );
        send_string(str);
	free(str);
	// make CFLAGS+="-lc -specs=nosys.specs" board:keymap
	*/
      }
      return false; break;
    case CCCV:  // One key copy/paste
      if (record->event.pressed) {
        user_key_timer = timer_read();
      } else {
        if (timer_elapsed(user_key_timer) > TAPPING_TERM) {  // Hold, copy
          register_code(KC_LCTL);
          tap_code(KC_C);
          unregister_code(KC_LCTL);
        } else {  // Tap, paste
          register_code(KC_LCTL);
          tap_code(KC_V);
          unregister_code(KC_LCTL);
        }
      }
      return false; break;
  }
  return process_record_keymap(keycode, record) &&
    process_record_secrets(keycode, record);
}

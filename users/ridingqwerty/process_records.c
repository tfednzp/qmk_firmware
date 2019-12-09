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

/*  // interesting thing in drashna's config
  case KC_QWERTY ... KC_WORKMAN:
     if (record->event.pressed) {
         uint8_t mods = mod_config(get_mods()|get_oneshot_mods());
         if (!mods) {
             set_single_persistent_default_layer(keycode - KC_QWERTY);
         } else if (mods & MOD_MASK_SHIFT) {
             set_single_persistent_default_layer(keycode - KC_QWERTY + 4);
         } else if (mods & MOD_MASK_CTRL) {
             set_single_persistent_default_layer(keycode - KC_QWERTY + 8);
         }
     }
     break;
*/

float nocturne[][2] = SONG(NOCTURNE_OP_9_NO_1);

bool aesthetic_mode = false;
bool spongebob_mode = false;
bool spongebob_case = false;
uint8_t user_mod_state;
uint16_t user_key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  //uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  if (spongebob_mode) {
    switch(keycode) {
      case KC_A ... KC_Z:
      case ED(A):
      case LS(Z):
        if (record->event.pressed) {
	  (spongebob_case ^= 1) == 0 ? tap_code16(S(keycode)) : tap_code(keycode);
	  return false;
        }
	break;
    }
  } 
  
  if (aesthetic_mode) {
    switch(keycode) {
      case KC_1 ... KC_0:
      case KC_A ... KC_Z:
      case ED(A):
      case LS(Z):
        if (record->event.pressed) {
	  register_code(KC_LSFT);
	  tap_code16(keycode);
	  unregister_code(KC_LSFT);
	  tap_code(KC_SPC);
        }
	return false; break;
      case KC_BSPC:
      case NM(BSPC):
        if (record->event.pressed) {
	  tap_code(KC_BSPC);
	  tap_code(KC_BSPC);
        }
	return false; break;
      case KC_SPC:
      case SM(SPC):
        if (record->event.pressed) {
	  tap_code(KC_SPC);
	  tap_code(KC_SPC);
	  tap_code(KC_SPC);
        }
	return false; break;
    }
  } 

  switch(keycode) {

    case VERSION:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR(QMK_KEYBOARD ":" QMK_KEYMAP "\nVersion:" QMK_VERSION ", built: " QMK_BUILDDATE), MACRO_TIMER);
      }
      break;

    case QWERTY ... COLEMAK:
#ifdef UNICODEMAP_ENABLE
    case GREEK ... RUNES:
#endif
      if (record->event.pressed) {
        set_single_persistent_default_layer(keycode - QWERTY);
      }
      break;

    case MAKE:
      if (record->event.pressed) {
	user_mod_state = get_mods() & MOD_MASK_CTRL;
	if (user_mod_state) {
	  clear_mods();
	  send_string_with_delay_P(PSTR("sleep 1 && "), MACRO_TIMER);
	}
        send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), MACRO_TIMER);
	if (user_mod_state) {
#if defined(__arm__)
          //send_string_with_delay_P(PSTR(":flash"), MACRO_TIMER);
          send_string_with_delay_P(PSTR(":dfu-util"), MACRO_TIMER);
#elif defined(BOOTLOADER_HALFKAY)
          send_string_with_delay_P(PSTR(":teensy"), MACRO_TIMER);
#endif
	  send_string_with_delay_P(PSTR("\n"), MACRO_TIMER);
          reset_keyboard();
	} else {
	  send_string_with_delay_P(PSTR("\n"), MACRO_TIMER);
	}  
      }
      break;

    case LISTEN:
      PLAY_SONG(nocturne);
      break;

    case FLAG:
      if (!record->event.pressed) {
        //send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
        //SEND_STRING(BOOTLOADER);
        //user_mod_state = get_mods();
        if (get_mods() & MOD_MASK_SHIFT) { dprintf("shift held\n"); }
        dprintf("FLAG PRESSED, DEBUG IS ENABLED!!\n");
      }
      break;

    case GRIND:
      if (record->event.pressed) {
        send_string_with_delay_P(PSTR("while true; do make " QMK_KEYBOARD ":" QMK_KEYMAP " && sleep 2 && echo \"build\nsuccessful\" | toilet && sleep 1 && clear; done"), MACRO_TIMER);
      }
      break;

    case RG_QUOT:
      if (record->event.pressed) {
        user_key_timer = timer_read();
        layer_on(_NUMBER);
        register_mods(MOD_BIT(KC_RGUI));
      } else {
        unregister_mods(MOD_BIT(KC_RGUI));
        layer_off(_NUMBER);
	if (timer_elapsed(user_key_timer) < TAPPING_TERM) {
	  tap_code(KC_QUOT);
	}
      }
      return false; break;

    case TESTY:
      if (record->event.pressed) {
	user_mod_state = get_mods() & MOD_MASK_CTRL;
	if (user_mod_state) {
	  clear_mods();
	  send_string_with_delay_P(PSTR("string1\n"), MACRO_TIMER);
	  set_mods(user_mod_state);
	} else {
	  SEND_STRING("\\n");
	}
      //tap_random_base64();
      //dprintf(" < that shit was random\n");
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
      break;

    case NICE:  // One key copy/paste
      if (record->event.pressed) {
        send_unicode_hex_string("2588 2588 2588 2557 2007 2007 2007 2588 2588 2557 2588 2588 2557 2007 2588 2588 2588 2588 2588 2588 2557 2588 2588 2588 2588 2588 2588 2588 2557 000A");
        send_unicode_hex_string("2588 2588 2588 2588 2557 2007 2007 2588 2588 2551 2588 2588 2551 2588 2588 2554 2550 2550 2550 2550 255D 2588 2588 2554 2550 2550 2550 2550 255D 000A");
        send_unicode_hex_string("2588 2588 2554 2588 2588 2557 2007 2588 2588 2551 2588 2588 2551 2588 2588 2551 2007 2007 2007 2007 2007 2588 2588 2588 2588 2588 2557 2007 2007 000A");
        send_unicode_hex_string("2588 2588 2551 255A 2588 2588 2557 2588 2588 2551 2588 2588 2551 2588 2588 2551 2007 2007 2007 2007 2007 2588 2588 2554 2550 2550 255D 2007 2007 000A");
        send_unicode_hex_string("2588 2588 2551 2007 255A 2588 2588 2588 2588 2551 2588 2588 2551 255A 2588 2588 2588 2588 2588 2588 2557 2588 2588 2588 2588 2588 2588 2588 2557 000A");
        send_unicode_hex_string("255A 2550 255D 2007 2007 255A 2550 2550 2550 255D 255A 2550 255D 2007 255A 2550 2550 2550 2550 2550 255D 255A 2550 2550 2550 2550 2550 2550 255D 000A 000A");
      }
      break;

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
      break;

    case SPONGEBOB:
      if (record->event.pressed) {
        spongebob_mode ^= 1;
      }
      break;

    case AESTHETIC:
      if (record->event.pressed) {
        aesthetic_mode ^= 1;
      }
      break;

  }
  return process_record_keymap(keycode, record) &&
    process_record_secrets(keycode, record);
}

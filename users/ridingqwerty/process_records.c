#include <stdio.h>
#include <time.h>
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

mode_config_t mode = {.all = 0U};


float nocturne[][2] = SONG(NOCTURNE_OP_9_NO_1);

bool randword_seed  = false;
uint8_t user_mod_state;
uint32_t user_key_timer;


#include "dict.h"

uint16_t alt_keymap[2][3] = {{KC_EXCLAIM, KC_A, KC_AMPR},{KC_1, KC_ASTR, KC_7}};
//uint16_t alt_keymap[2][KEYS_N];
//alt_keymap[0][] = { KC_EXCLAIM, KC_AT, KC_HASH };
//alt_keymap[1][] = { KC_1, KC_2, KC_3 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  //uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  if (mode.spongebob) {
    switch(keycode) {
      case KC_A ... KC_Z:
      case ED(A):
      case LS(Z):
        if (record->event.pressed) {
	  (mode.uppercase ^= 1) == 0 ? tap_code16(S(keycode)) : tap_code(keycode);
	  return false;
        }
	break;
    }
  } 
  
  if (mode.aesthetic) {
    switch(keycode) {
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
      case ED(A):
      case KC_A:
	if (record->event.pressed) {
          send_unicode_hex_string("039B");
	  tap_code(KC_SPC);
	}
	return false; break;
      case KC_E:
	if (record->event.pressed) {
	  send_unicode_hex_string("039E");
	  tap_code(KC_SPC);
	}
	return false; break;
#else
      case ED(A):
      case A:
      case E:
	if (record->event.pressed) {
	  register_code(KC_LSFT);
	  tap_code16(keycode);
	  unregister_code(KC_LSFT);
	  tap_code(KC_SPC);
	}
	return false; break;
#endif
      case KC_B ... KC_D:
      case KC_F ... KC_Z:
      case LS(Z):
        if (record->event.pressed) {
	  tap_code16(S(keycode));
	  tap_code(KC_SPC);
        }
	return false; break;
      case KC_1 ... KC_0:
        if (record->event.pressed) {
	  tap_code(keycode);
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

  if (mode.australia) {
    switch(keycode) {
      // WIP
      // still need handling for backspace, space
      // uppercase letters
      // numbers
      // symbols
      // IDEMPOTENT
      case KC_L:
      case KC_O:
      case KC_S:
      case KC_Z:
      case LS(Z):
	if (record->event.pressed) {
	  tap_code(keycode);
	  tap_code(KC_LEFT);
	}
	return false;

      // INVERTIBLE
      case KC_B:
	if (record->event.pressed) {
	  tap_code(KC_Q);
	  tap_code(KC_LEFT);
	}
	return false;
      case KC_Q:
	if (record->event.pressed) {
	  tap_code(KC_B);
	  tap_code(KC_LEFT);
	}
	return false;
      case KC_D:
	if (record->event.pressed) {
	  tap_code(KC_P);
	  tap_code(KC_LEFT);
	}
	return false;
      case KC_P:
	if (record->event.pressed) {
	  tap_code(KC_D);
	  tap_code(KC_LEFT);
	}
	return false;
      case KC_N:
	if (record->event.pressed) {
	  tap_code(KC_U);
	  tap_code(KC_LEFT);
	}
	return false;
      case KC_U:
	if (record->event.pressed) {
	  tap_code(KC_N);
	  tap_code(KC_LEFT);
	}
	return false;
      
      // TRANSLATE
      case ED(A):
      case KC_A:
        if (record->event.pressed) {
          send_unicode_hex_string("0250");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_C:
        if (record->event.pressed) {
          send_unicode_hex_string("0254");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_E:
        if (record->event.pressed) {
          send_unicode_hex_string("01DD");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_F:
        if (record->event.pressed) {
          send_unicode_hex_string("025F");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_G:
        if (record->event.pressed) {
          send_unicode_hex_string("0183");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_H:
        if (record->event.pressed) {
          send_unicode_hex_string("0265");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_I:
        if (record->event.pressed) {
          send_unicode_hex_string("1D09");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_J:
        if (record->event.pressed) {
          send_unicode_hex_string("027E");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_K:
        if (record->event.pressed) {
          send_unicode_hex_string("029E");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_M:
        if (record->event.pressed) {
          send_unicode_hex_string("026F");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_R:
        if (record->event.pressed) {
          send_unicode_hex_string("0279");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_T:
        if (record->event.pressed) {
          send_unicode_hex_string("0287");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_V:
        if (record->event.pressed) {
          send_unicode_hex_string("028C");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_W:
        if (record->event.pressed) {
          send_unicode_hex_string("028D");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_X:
        if (record->event.pressed) {
          send_unicode_hex_string("2717");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;
      case KC_Y:
        if (record->event.pressed) {
          send_unicode_hex_string("028E");
	  tap_code(KC_LEFT);
	  return false;
        }
	break;

      // TERMINATE
      case KC_ENT:
	tap_code(KC_END);
	tap_code(KC_ENTER);
	return false;
    }
  } 
 

  switch(keycode) {

    case VERSION:
      if (!record->event.pressed) {
        send_string_with_delay_P(PSTR(QMK_KEYBOARD ":" QMK_KEYMAP "\nVersion:" QMK_VERSION ", built: " QMK_BUILDDATE), MACRO_TIMER);
      }
      break;

    case QWERTY ... COLEMAK:
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
    case GREEK ... RUNES:
#endif
      if (record->event.pressed) {
        //set_single_persistent_default_layer(keycode - QWERTY);
        default_layer_set(1U << (keycode - QWERTY));
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

      /*
    case MY_1 ... MY_3:
      if (record->event.pressed) {
        user_mod_state = get_mods() & MOD_MASK_SHIFT;
	clear_mods();
        if(user_mod_state) {
	  tap_code16(alt_keymap[1][keycode - MY_1]);
	} else {
	  tap_code16(alt_keymap[0][keycode - MY_1]);
	}
	set_mods(user_mod_state);
      }
      break;
      */

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

    case RNGWORD:
      ;
      if (randword_seed == false) {
	randword_seed = true;
        srand(timer_read32());
      }
      //uint8_t randseed = timer_read();
      //srand(randseed);
      //srand(timer_read());
      uint16_t key = rand() % NUMBER_OF_WORDS;
      if (record->event.pressed) {
	send_string(dict[key]);
	tap_code(KC_SPC);
      }
      return false; break;

    case RG_QUOT:
      if (record->event.pressed) {
#if defined(UNICODE_ENABLE) || defined(UNICODEMAP_ENABLE)
     	user_mod_state = get_mods() & MOD_MASK_ALT;
	if (user_mod_state) {
	  clear_mods();
	  send_unicode_hex_string("00B0");
	  set_mods(user_mod_state);
	  return false;
	}
#endif
        user_key_timer = timer_read32();
        layer_on(_NUMBER);
        register_mods(MOD_BIT(KC_RGUI));
      } else {
        unregister_mods(MOD_BIT(KC_RGUI));
        layer_off(_NUMBER);
	if (timer_elapsed32(user_key_timer) < TAPPING_TERM) {
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

    case NICE: // s l o w
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
        user_key_timer = timer_read32();
      } else {
        if (timer_elapsed32(user_key_timer) > TAPPING_TERM) {  // Hold, copy
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

    case SEED:
      if (record->event.pressed) {
	srand(timer_read32());
      }
      break;

    case SARCASM:
      if (record->event.pressed) {
        mode.spongebob ^= 1;
      }
      break;

    case VAPORWV:
      if (record->event.pressed) {
        mode.aesthetic ^= 1;
      }
      break;

    case STRAYA:
      if (record->event.pressed) {
        mode.australia ^= 1;
      }
      break;

  }
  return process_record_keymap(keycode, record) &&
    process_record_secrets(keycode, record);
}

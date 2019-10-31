#include "ridingqwerty.h"
#include "tapdances.h"

/*
typedef struct {
    bool is_press_action;
    int state; 
} tap;

static tap xtap_state = {
    .is_press_action = true,
    .state = 0
};

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
    DOUBLE_SINGLE_TAP = 5,
    TRIPLE_TAP = 6,
    TRIPLE_HOLD = 7
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
     // DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     // keystrokes of the key, and not the 'double tap' action/macro.
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

#ifdef UNICODEMAP_ENABLE
void dance_layer_each(qk_tap_dance_state_t* state, void* user_data) {
    // below is a stub
    if (state->count == 1) {
        register_code(KC_ESC);
    }
}

void dance_layer_finished(qk_tap_dance_state_t* state, void* user_data) {
    if (state->count == 1) {
        register_code(KC_ESC);
    }
}

void dance_layer_reset(qk_tap_dance_state_t* state, void* user_data) {
    if (state->count == 1) {
        unregister_code(KC_ESC);
    }
    else {
        uint8_t layer = biton32(layer_state);
	if (layer == _QWERTY) {
	    layer_off(_QWERTY);
	    layer_on(_RUNE);
	} else {
	    layer_off(_RUNE);
	    layer_on(_QWERTY);
	}
    }
}
#endif

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP: register_code(KC_X); break;
        case SINGLE_HOLD: register_code(KC_LCTRL); break;
        case DOUBLE_TAP: register_code(KC_ESC); break;
        case DOUBLE_HOLD: register_code(KC_LALT); break;
        // case DOUBLE_SINGLE_TAP: break; // not defined
    }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP: unregister_code(KC_X); break;
        case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code(KC_ESC); break;
        case DOUBLE_HOLD: unregister_code(KC_LALT); break;
        //case DOUBLE_SINGLE_TAP: unregister_code(KC_X); // not defined
    }
    xtap_state.state = 0;
}

void lbrace_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LSFT);
        register_code(KC_9);
    }
    else if (state->count == 2) {
        register_code(KC_LBRC);
    }
    else {
        register_code(KC_LSFT);
        register_code(KC_LBRC);
    }
}

void lbrace_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LSFT);
        unregister_code(KC_9);
    }
    else if (state->count == 2) {
        unregister_code(KC_LBRC);
    }
    else {
        unregister_code(KC_LSFT);
        unregister_code(KC_LBRC);
    }
}

void rbrace_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_RSFT);
        register_code(KC_0);
    }
    else if (state->count == 2) {
        register_code(KC_RBRC);
    }
    else {
        register_code(KC_RSFT);
        register_code(KC_RBRC);
    }
}

void rbrace_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_RSFT);
        unregister_code(KC_0);
    }
    else if (state->count == 2) {
        unregister_code(KC_RBRC);
    }
    else {
        unregister_code(KC_RSFT);
        unregister_code(KC_RBRC);
    }
}
*/

void braces_finished (qk_tap_dance_state_t *state, void *user_data) {
    if ((state->count == 1) || (state->count == 3)) {
        register_code(KC_LSFT);
    }
}

void braces_reset (qk_tap_dance_state_t *state, void *user_data) {
    // two or three taps for "[]"/"{}"
    if ((state->count == 2) || (state->count == 3)) {
	tap_code(KC_LBRC);
	tap_code(KC_RBRC);
    }
    // one tap for "()"
    else if (state->count == 1) {
	tap_code(KC_9);
	tap_code(KC_0);
    }
   
    // unregister the shift unconditionally
    unregister_code(KC_LSFT);
    
    // move back one space (inside the braces)
    if (state->count <= 3) {
	tap_code(KC_LEFT);
    }

}

void bspace_finished (qk_tap_dance_state_t *state, void *user_data) {
    if ((state->count == 1) && (!state->pressed)) {
      tap_code(KC_BSPC);
    } else {
      register_code(KC_LSFT);
    }
}

void bspace_reset (qk_tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_LSFT);
}

void space_finished (qk_tap_dance_state_t *state, void *user_data) {
    if ((state->count == 1) && (!state->pressed)) {
      tap_code(KC_SPC);
    } else {
      //register_code(KC_LSFT);
      layer_on(_SYMBOL);
    }
}

void space_reset (qk_tap_dance_state_t *state, void *user_data) {
    //unregister_code(KC_LSFT);
    layer_off(_SYMBOL);
}


/*
    else {
        uint8_t layer = biton32(layer_state);
        if (layer == _QWERTY) {
            layer_off(_QWERTY);
            layer_on(_RUNE);
        } else {
            layer_off(_RUNE);
            layer_on(_QWERTY);
        }
*/

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ESC, twice for Caps Lock
    //[TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
    //[TD_QUO_DQUO] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO)
    //[TD_SWP_BASE] = ACTION_TAP_DANCE_FN_ADVANCED (dance_layer_each, dance_layer_finished, dance_layer_reset)
/*
    [TD_SEM_COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_SWP_BASE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_layer_finished, dance_layer_reset),
    [X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, x_finished, x_reset),
    [TD_LBRACE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, lbrace_finished, lbrace_reset),
    [TD_RBRACE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, rbrace_finished, rbrace_reset),
*/
    [TD_BRACES] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, braces_finished, braces_reset),
    [TD_BSPACE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, bspace_finished, bspace_reset, 90),
    [TD_SPACE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, space_finished, space_reset, 90)
};

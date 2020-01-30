#pragma once

#include "quantum.h"

#define TD_ESC TD(TD_SWP_BASE)
#define TD_TEST TD(X_CTL)
#define TD_SEMI TD(TD_SEM_COLN)
#define TD_LBRC TD(TD_LBRACE)
#define TD_RBRC TD(TD_RBRACE)
#define TD_BRC  TD(TD_BRACES)
#define TD_BSPC TD(TD_BSPACE)
#define TD_SPC  TD(TD_SPACE)
#define PGUPLK  TD(TD_PGUPLK)
#define TD_SHFT TD(TD_SFT_CAPS)

enum tapdance_id {
    TD_ESC_CAPS = 0,	// not used presently
    TD_SWP_BASE,	// used to swap between english and runes
    TD_SEM_COLN,
    X_CTL,		// demo multi-tap / hold -- useful to expand upon
    TD_LBRACE,
    TD_RBRACE,
    TD_BRACES,
    TD_BSPACE,
    TD_SPACE,
    TD_PGUPLK,
    TD_SFT_CAPS
};

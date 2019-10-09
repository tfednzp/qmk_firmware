#pragma once
#include "ridingqwerty.h"

#define LAYOUT_atreus_wrapper(...)		LAYOUT_atreus(__VA_ARGS__)
#define LAYOUT_minorca_wrapper(...)		LAYOUT_minorca(__VA_ARGS__)

// TODO
// -center alignment of text in half-row macros may hinder future editing
//  -use set underscore prefix?

//      1......__2......__3......__4......__5......
#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________ATREUS_L1_________________        _________________QWERTY_L1_________________
#define _________________ATREUS_L2_________________        ED(A),   KC_S,    KC_D,    KC_F,    KC_G
#define _________________ATREUS_L3_________________        LS(Z),   KC_X,    KC_C,    KC_V,    KC_B

#define _________________ATREUS_R1_________________        _________________QWERTY_R1_________________
#define _________________ATREUS_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    NM(SCLN)
#define _________________ATREUS_R3_________________        KC_N,    KC_M,    KC_COMM, FK(DOT), RS(SLSH)

// not used
#define ______________FNHOMEROW_L2_________________        C(KC_A), G(KC_S), A(KC_D), S(KC_F), KC_G,
#define ______________FNHOMEROW_R2_________________        KC_H,    S(KC_J), A(KC_K), G(KC_L), C(SCLN)

//#define ____THUMBS_R4___        ED(ESC), SC(TAB)
#define ____THUMBS_R4___        ED(ESC), DB(TAB)
#define _____BLANK_R4___        _______, _______
#define ________________        _______, _______


#define _________________COLEMAK_L1________________        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________        KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________        KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define _________________BOTTOM_L4_________________        LC(ESC), LG(TAB),  LA(LBRC), LS(RBRC), NM(BSPC)
#define _________________BOTTOM_R4_________________        SM(SPC), RS(MINS), RA(EQL),  RG_QUOT,  RC(ENT)


#define _________________NUMROW_L1_________________        KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMROW_R1_________________        KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________NUMPAD_R1_________________        -------, KC_7,    KC_8,    KC_9,    KC_0
#define _________________NUMPAD_R2_________________        _______, KC_4,    KC_5,    KC_6,    _______
#define _________________NUMPAD_R3_________________        _______, KC_1,    KC_2,    KC_3,    KC_BSLS
#define _________________NUMPAD_R4_________________        KC_0,    KC_0,    KC_DOT,  KC_3,    _______ 


#define _________________SYMROW_L1_________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________SYMROW_R1_________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN


#define ________________                                   _______, _______                   
#define _________________________                          _______, _______, _______          
#define __________________________________                 _______, _______, _______, _______          
#define ___________________________________________        _______, _______, _______, _______, _______
#define ___________________________________________        _______, _______, _______, _______, _______
#define ___________________________________________        _______, _______, _______, _______, _______
#define ___________________BLANK___________________        ___________________________________________
#define ___________________BLOCK___________________        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO


#define ________________FKEYROW_L1_________________        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ________________FKEYROW_R1_________________        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10


#define _________________EDITOR_L1_________________        KC_GRV,  _______, KC_END,  _______, KC_F5  
#define _________________EDITOR_L2_________________        KC_HOME, _______, KC_DELT, _______, _______
#define _________________EDITOR_L3_________________        _______, _______, _______, _______, _______

#define _________________EDITOR_R1_________________        _______, _______, KC_INS,  _______, KC_PGUP
#define _________________EDITOR_R2_________________        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________EDITOR_R3_________________        KC_PGDN, _______, _______, _______, KC_BSLS


#ifdef UNICODE_H
// Greek
#define __________________GREEK_L1_________________        THETA,   OMEGA,   EPSLN,   RHO,     TAU
#define __________________GREEK_L2_________________        ALPHA,   SIGMA,   DELTA,   PHI,     GAMMA
#define __________________GREEK_L3_________________        ZETA,    XI,      CHI,     PHI,     BETA

#define __________________GREEK_R1_________________        UPSLN,   UPSLN,   IOTA,    OMCRN,   PI
#define __________________GREEK_R2_________________        ETA,     PSI,     KAPPA,   LAMBA,   KC_SCLN
#define __________________GREEK_R3_________________        NU,      MU,      KC_COMM, KC_DOT,  KC_SLSH


// Elder Futhark
#define __________________FTHRK_L1_________________        INGWZ,   WUNJO,   EHWAZ,   RAIDO,   TIWAZ
#define __________________FTHRK_L2_________________        ANSUZ,   SOWIL,   DAGAZ,   FE,      GEBO
#define __________________FTHRK_L3_________________        ALGIZ,   THURS,   KAUNA,   WUNJO,   BEORC

#define __________________FTHRK_R1_________________        IWAZ,    UR,      ISAZ,    ETHEL,   PERTH
#define __________________FTHRK_R2_________________        HAGLZ,   JERAN,   KAUNA,   LAUKZ,   KC_SCLN
#define __________________FTHRK_R3_________________        NAUDZ,   MANNZ,   KC_COMM, KC_DOT,  KC_SLSH

// Russian Cyrillic
// 3 chars will have to go on R4
#define __________________CYRLC_L1_________________        YA,      SCHA,    IE,      ER,       TE
#define __________________CYRLC_L2_________________        AH,      ES,      DE,      EF,       GHE
#define __________________CYRLC_L3_________________        ZE,      HA,      TSE,     VE,       BE

#define __________________CYRLC_R1_________________        YERU,    UU,      IH,      OH,      PE
#define __________________CYRLC_R2_________________        CHE,     SIH,     KA,      EL,      SOFT
#define __________________CYRLC_R3_________________        EN,      EM,      YU,      SCHA,    EH
#define __________________CYRLC_R4_________________        SM(SPC), IO,      HARD,    ZHE,     RC(ENT)

// Hiragana (L/R issue?)
#define ____________________JIS_R1_________________        JTA,     JTE,     JI,      JSU,     JKA,  
#define ____________________JIS_R2_________________        JTI,     JTO,     JSI,     JHA,     JKI,  
#define ____________________JIS_R3_________________        JTU,     JSA,     JSO,     JHI,     JKO,  

#define ____________________JIS_L1_________________        JN,      JNA,     JNI,     JRA,     JSE,  
#define ____________________JIS_L2_________________        JKU,     JMA,     JNO,     JRI,     JRE,  
#define ____________________JIS_L3_________________        JMI,     JMO,     JNE,     JRU,     JME,  

#endif //UNICODE_H

#define ___________VI_ARROWS______________                 KC_LEFT, KC_DOWN, KC,UP,   KC_RGHT

//U+3040..U+309F
/*
// below would need to be on a shift layer from base hiragana
MI み U+307F N
MO も U+3082 M
NE ね U+306D ,
RU る U+308B .
ME め U+3081 /

RO ろ U+308D `
WA わ U+308F 0
NU ぬ U+306C 1
HU ふ U+3075 2
A あ U+3042 3
U う U+3046 4
E え U+3048 5
O お U+304A 6
YA や U+3084 7
YU ゆ U+3086 8
YU よ U+3088 9
HO ほ U+307B -
HE へ U+3078 =
MU む U+3080 return,bsls
voiced ゛U+309B [
semivoiced ゜U+309C ]
KE け U+3051 '
*/

// QMK_KEYBOARD is def so perhaps we can conditially include languages based on that
// extra stupid for several reasons but could be fun

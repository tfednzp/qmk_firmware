#pragma once

enum unicode_names {
  GE_LAE,
  GE_LEE,
  GE_LOE,
  GE_LUE,
  GE_LSS,
  GE_UAE,
  GE_UEE,
  GE_UOE,
  GE_UUE,
  GE_USS,
  JRO,
  JWA,
  JNU,
  JHU,
  JA,
  JU,
  JE,
  JO,
  JYA,
  JYU,
  JYO,
  JHO,
  JHE,
  JMU,
  JTA,
  JTE,
  JI,
  JSU,
  JKA,
  JN,
  JNA,
  JNI,
  JRA,
  JSE,
  JVV,
  JSV,
  JTI,
  JTO,
  JSI,
  JHA,
  JKI,
  JKU,
  JMA,
  JNO,
  JRI,
  JRE,
  JKE,
  JTU,
  JSA,
  JSO,
  JHI,
  JKO,
  JMI,
  JMO,
  JNE,
  JRU,
  JME
};

const uint32_t PROGMEM unicode_map[] = {
  [GE_LAE] = 0x00E4, // ä
  [GE_LEE] = 0x00EB, // ë
  [GE_LOE] = 0x00F6, // ö
  [GE_LUE] = 0x00FC, // ü
  [GE_LSS] = 0x00DF, // ß
  [GE_UAE] = 0x00C4, // Ä
  [GE_UEE] = 0x00CB, // Ë
  [GE_UOE] = 0x00D6, // Ö
  [GE_UUE] = 0x00DC, // Ü
  [GE_USS] = 0x1E9E, // ẞ
  [JRO]    = 0x308D, // ろ
  [JNU]    = 0x306C, // ぬ
  [JHU]    = 0x3075, // ふ
  [JA]     = 0x3042, // あ
  [JU]     = 0x3046, // う
  [JE]     = 0x3048, // え
  [JO]     = 0x304A, // お
  [JYA]    = 0x3084, // や
  [JYU]    = 0x3086, // ゆ
  [JYO]    = 0x3088, // よ
  [JWA]    = 0x308F, // わ
  [JHO]    = 0x307B, // ほ
  [JHE]    = 0x3078, // へ
  [JMU]    = 0x3080, // む
  [JTA]    = 0x305F, // た
  [JTE]    = 0x3066, // て
  [JI]     = 0x3044, // い
  [JSU]    = 0x3059, // す
  [JKA]    = 0x3095, // ゕ
  [JN]     = 0x3093, // ん
  [JNA]    = 0x306A, // な
  [JNI]    = 0x306B, // に
  [JRA]    = 0x3089, // ら
  [JSE]    = 0x305B, // せ
  [JVV]    = 0x309B, // ゛
  [JSV]    = 0x309C, // ゜
  [JTI]    = 0x3061, // ち
  [JTO]    = 0x3068, // と
  [JSI]    = 0x3057, // し
  [JHA]    = 0x306F, // は
  [JKI]    = 0x304D, // き
  [JKU]    = 0x304F, // く
  [JMA]    = 0x307E, // ま
  [JNO]    = 0x306E, // の
  [JRI]    = 0x308A, // り
  [JRE]    = 0x308C, // れ
  [JKE]    = 0x3051, // け
  [JTU]    = 0x3064, // つ
  [JSA]    = 0x3055, // さ
  [JSO]    = 0x305D, // そ
  [JHI]    = 0x3072, // ひ
  [JKO]    = 0x3053, // こ
  [JMI]    = 0x307F, // み
  [JMO]    = 0x3082, // も
  [JNE]    = 0x306D, // ね
  [JRU]    = 0x308B, // る
  [JME]    = 0x3081  // め
};

#define GE_AE XP(GE_LAE, GE_UAE)
#define GE_EE XP(GE_LEE, GE_UEE)
#define GE_OE XP(GE_LOE, GE_UOE)
#define GE_UE XP(GE_LUE, GE_UUE)
#define GE_SS XP(GE_LSS, GE_USS)


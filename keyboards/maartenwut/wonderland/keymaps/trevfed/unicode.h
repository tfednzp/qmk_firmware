#pragma once

enum unicode_names {
  UALP,
  UBET,
  UGAM,
  UDEL,
  UEPS,
  UZET,
  UETA,
  UTHE,
  UIOT,
  UKAP,
  ULAM,
  UMU,
  UNU,
  UXI,
  UOMI,
  UPI,
  URHO,
  USIG,
  UTAU,
  UUPS,
  UPHI,
  UCHI,
  UPSI,
  UOME,
  LALP,
  LBET,
  LGAM,
  LDEL,
  LEPS,
  LZET,
  LETA,
  LTHE,
  LIOT,
  LKAP,
  LLAM,
  LMU,
  LNU,
  LXI,
  LOMI,
  LPI,
  LRHO,
  LSIG,
  LTAU,
  LUPS,
  LPHI,
  LCHI,
  LPSI,
  LOME,
  LSEQ,
  GREQ
};

const uint32_t PROGMEM unicode_map[] = {
  [UALP] =  0x0391, // Α
  [UBET] =  0x0392, // Β
  [UGAM] =  0x0393, // Γ
  [UDEL] =  0x0394, // Δ
  [UEPS] =  0x0395, // Ε
  [UZET] =  0x0396, // Ζ
  [UETA] =  0x0397, // Η
  [UTHE] =  0x0398, // Θ
  [UIOT] =  0x0399, // Ι
  [UKAP] =  0x039A, // Κ
  [ULAM] =  0x039B, // Λ
  [UMU] =   0x039C, // M
  [UNU] =   0x039D, // Ν
  [UXI] =   0x039E, // Ξ
  [UOMI] =  0x039F, // Ο
  [UPI] =   0x03A0, // Π
  [URHO] =  0x03A1, // Ρ
  [USIG] =  0x03A3, // Σ
  [UTAU] =  0x03A4, // Τ
  [UUPS] =  0x03A5, // Υ
  [UPHI] =  0x03A6, // Φ
  [UCHI] =  0x03A7, // Χ
  [UPSI] =  0x03A8, // Ψ
  [UOME] =  0x03A9, // Ω
  [LALP] =  0x03B1, // α
  [LBET] =  0x03B2, // β
  [LGAM] =  0x03B3, // γ
  [LDEL] =  0x03B4, // δ
  [LEPS] =  0x03B5, // ε
  [LZET] =  0x03B6, // ζ
  [LETA] =  0x03B7, // η
  [LTHE] =  0x03B8, // θ
  [LIOT] =  0x03B9, // ι
  [LKAP] =  0x03BA, // κ
  [LLAM] =  0x03BB, // λ
  [LMU] =   0x03BC, // μ
  [LNU] =   0x03BD, // ν
  [LXI] =   0x03BE, // ξ
  [LOMI] =  0x03BF, // ο
  [LPI] =   0x03C0, // π
  [LRHO] =  0x03C1, // ρ
  [LSIG] =  0x03C3, // σ
  [LTAU] =  0x03C4, // τ
  [LUPS] =  0x03C5, // υ
  [LPHI] =  0x03C6, // φ
  [LCHI] =  0x03C7, // χ
  [LPSI] =  0x03C8, // ψ
  [LOME] =  0x03C9, // ω
  [LSEQ] = 0x2264, // ≤
  [GREQ] = 0x2265  // ≥
};

#define ALPHA XP(LALP, UALP)
#define BETA  XP(LBET, UBET)
#define GAMMA XP(LGAM, UGAM)
#define DELTA XP(LDEL, UDEL)
#define EPSLN XP(LEPS, UEPS)
#define ZETA  XP(LZET, UZET)
#define ETA   XP(LETA, UETA)
#define THETA XP(LTHE, UTHE)
#define IOTA  XP(LIOT, UIOT)
#define KAPPA XP(LKAP, UKAP)
#define LAMBD XP(LLAM, ULAM)
#define GMU   XP(LMU,  UMU)
#define NU    XP(LNU,  UNU)
#define XI    XP(LXI,  UXI)
#define OMCRN XP(LOMI, UOMI)
#define PI    XP(LPI,  UPI)
#define RHO   XP(LRHO, URHO)
#define SIGMA XP(LSIG, USIG)
#define TAU   XP(LTAU, UTAU)
#define UPSLN XP(LUPS, UUPS)
#define PHI   XP(LPHI, UPHI)
#define CHI   XP(LCHI, UCHI)
#define PSI   XP(LPSI, UPSI)
#define OMEGA XP(LOME, UOME)


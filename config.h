

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1214 // "JD" - JoeDeck
#define PRODUCT_ID      0x0304 // JoeDeck
#define DEVICE_VER      0x0000
#define MANUFACTURER    JoeDeck
#define PRODUCT         JoeDeck

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS {F7, F6, F5}
#define MATRIX_COL_PINS {B6, B2, B3, B1}

#define ENCODERS_PAD_A { D4 }
#define ENCODERS_PAD_B { C6 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#include "atomic.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define ___T___ KC_TRNS
#define XXXXXXX KC_NO

// Layer shorthand
#define LAYER_QWERTY           0
#define LAYER_FUNCTION         1
#define LAYER_FUNCTION_2       2

#define MACRO_JUMP_FORWARD     1
#define MACRO_JUMP_BACKWARD    2

#define M_JUMPF                M(MACRO_JUMP_FORWARD)
#define M_JUMPB                M(MACRO_JUMP_BACKWARD)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY - MIT ENHANCED / GRID COMPATIBLE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | ~      | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | JUMPF  | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | [      | ]      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------|
 * | Vol Dn | Vol Up | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | '      | XXXXXX . Enter  |
 * |- 2u ------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSHIFT . XXXXXX | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT | UP     | EXPOSE |
 * |--------+--------+--------+--------+--------+- 2u ------------+- 2u ------------+--------+--------+--------+--------+--------+--------|
 * | FUNC   | FN     | CTRL   | OPT    | CMD    | XXXXXX . SPACE  | XXXXXX . SPACE  | Prev   | Ply    | Next   | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [LAYER_QWERTY] = { /* QWERTY */
  { KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC  },
  { M_JUMPF, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS  },
  { KC_VOLD, KC_VOLU, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_ENT   },
  { KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_F3    },
  { KC_FN0,  _______, KC_LCTRL,KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_MPRV, KC_MPLY, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | NUM LK |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | SCR LK |        | F13    | F14    | F15    | F16    | F17    | F18    | F19    | F20    | F21    | F22    | F23    | PAUSE  | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+- 2u ------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |- 2u ------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+- 2u ------------+- 2u ------------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [LAYER_FUNCTION] = { /* FUNCTION */
  { KC_NLCK, _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______  },
  { M_JUMPB, _______,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_PAUS, KC_PSCR  },
  { KC_F1,   KC_F2,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_RCTRL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

 };

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(LAYER_FUNCTION)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case MACRO_JUMP_FORWARD:
          return (record->event.pressed ?
                  MACRO( D(LALT), T(RGHT), U(LALT), END )
                  :MACRO( END ));
          break;

        case MACRO_JUMP_BACKWARD:
          return (record->event.pressed ?
                  MACRO( D(LALT), T(LEFT), U(LALT), END )
                  :MACRO( END ));
          break;
      }
    return MACRO_NONE;
};

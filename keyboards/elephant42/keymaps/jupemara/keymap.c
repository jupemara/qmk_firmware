/* Copyright 2021 illness072
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define SS_MEM LGUI(LSFT(LCTL(KC_4)))
#define SS_DSK LGUI(LSFT(KC_4))
#define MT_LSFT MT(MOD_LSFT, KC_SPC)
#define MT_RSFT MT(MOD_RSFT, KC_BSPC)
#define MT_RALT MT(MOD_RALT, KC_ENT)
#define LOWER LT(1, KC_LANG2)
#define RAISE LT(2, KC_LANG1)

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,

    NUMBER_OF_LAYERS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                                      KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSPC,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     KC_LCTL, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                                      KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,MT_RALT,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
              KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                                      KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     KC_LGUI,KC_LSFT,LOWER  ,KC_SPC,      MT_RSFT,RAISE  ,KC_ENT, KC_TAB
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_LOWER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     _______, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                                      KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     _______,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,                                     KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,KC_QUOT,_______,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
             KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,                                     KC_MINS,KC_PLUS,KC_LABK,KC_RABK,KC_BSLS,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,_______,_______,     MT_RSFT, MO(3),  _______,_______
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  ),

  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                                      KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_DEL,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     _______,KC_QUOT,KC_DQUO,KC_GRV, KC_MINS,KC_PLUS,                                     KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,KC_PIPE,_______,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
             _______,_______,KC_TILD,KC_UNDS,KC_EQL,                                     KC_LEFT,KC_DOWN,KC_UP,  KC_RIGHT,KC_BSLS,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     _______,_______,MO(3),  _______,     MT_RSFT,_______,_______,_______
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'


  [_ADJUST] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                                    ,-------+-------+-------+-------+-------+-------.
     RESET,  XXXXXXX,XXXXXXX,KC_MUTE,KC_VOLD,KC_VOLU,                                     KC_WH_U,KC_WH_D,KC_PGDN,KC_PGUP,XXXXXXX,KC_EJCT,
  //|-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------|
     _______,XXXXXXX,SS_MEM, SS_DSK, XXXXXXX,KC_MPLY,                                     KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,XXXXXXX,XXXXXXX,
  //`-------+-------+-------+-------+-------+-------|                                    |-------+-------+-------+-------+-------+-------'
             RGB_TOG,RGB_VAI,RGB_MOD,RGB_VAD,RGB_HUI,                                     KC_BTN1,KC_BTN2,KC_HOME,KC_END, XXXXXXX,
  //        `-------+-------+-------+-------+-------+-------+-------.    ,-------+-------+-------+-------+-------+-------+-------'
                                     KC_MPRV,_______,KC_MNXT,KC_MPLY,     KC_DEL ,_______,XXXXXXX,XXXXXXX
  //                                `-------+-------+-------+-------'    `-------+-------+-------+-------'
  )
};

#ifdef KEY_OVERRIDE_ENABLE

const key_override_t ctl_tab = ko_make_basic(
  MOD_MASK_CTRL,
  KC_ESC,
  C(KC_TAB)
);

const key_override_t gui_grv = ko_make_basic(
  MOD_MASK_GUI,
  KC_ESC,
  G(KC_GRV)
);
  
const key_override_t **key_overrides = (const key_override_t *[]){
    &ctl_tab,
    &gui_grv,
    NULL
};

#endif

#ifdef OLED_ENABLE
#   define STEPS 32

uint8_t keypresses = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        keypresses = (keypresses + 1) % STEPS;
    }
    return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        static char layer_names[NUMBER_OF_LAYERS][10] = {"Default", "Lower", "Raise", "Adjust"};
        static char l1[] = "                \x94\x95\x96\x97";
        static char l2[] = "                \xB4\xB5\xB6\xB7";
        static char r1[] = "                \x98\x99\x9A\x9B";
        static char r2[] = "                \xB8\xB9\xBA\xBB";
        int iconShift = keypresses % STEPS;
        if (iconShift > STEPS / 2) {
            iconShift = STEPS - iconShift;
        }
        bool goingLeft = keypresses < STEPS / 2;

        oled_write_P(PSTR("Layer: "), false);
        oled_write_ln(layer_names[get_highest_layer(layer_state)], false);
        oled_advance_page(true);
        oled_write_ln((goingLeft ? l1 : r1) + iconShift, false);
        oled_write_ln((goingLeft ? l2 : r2) + iconShift, false);
    } else {
        oled_advance_page(true);
        static const char PROGMEM logo[] = {
            0x8f,0x90,0x91,0x92,0x93,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x0a,
            0xaf,0xb0,0xb1,0xb2,0xb3,0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0x0a,
            0xcf,0xd0,0xd1,0xd2,0xd3,0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0
        };

        oled_write_ln_P(logo, false);
    }

    return false;
}
#endif

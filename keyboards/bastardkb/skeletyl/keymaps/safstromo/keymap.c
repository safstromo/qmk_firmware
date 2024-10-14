

#include QMK_KEYBOARD_H
enum skeletyl_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAVIGATION,
    LAYER_SYMBOLS,
    LAYER_FUNCTION,
};

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    ARROW_EQL,
};

#define COLEMAK DF(LAYER_BASE)
#define SYM MO(LAYER_SYMBOLS)
#define NAV MO(LAYER_NAVIGATION)
#define FKEYS MO(LAYER_FUNCTION)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)

#define SFT_QT LSFT(RALT(KC_DQT))
#define ALT_SQT RALT(KC_QUOT)
#define ALT_SPC LALT_T(KC_SPC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_SYM LT(LAYER_SYMBOLS, KC_TAB)
#define ENT_NAV LT(LAYER_NAVIGATION, KC_ENT)
#define BSP_NAV LT(LAYER_NAVIGATION, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
* Base Layer: Colemak DH
*
* ,----------------------------------.                              ,----------------------------------.
* |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |
* |------+------+------+------+------|                              |------+------+------+------+------|
* |GUI(A)|alt(R)|sft(S)|ctl(T)|   G  |                              |   M  |ctl(N)|sft(E)|alt(I)|GUI(O)|
* |------+------+------+------+------|                              |------+------+------+------+------|
* |   Z  |   X  |   C  |   D  |   V  |                              |   K  |   H  | ,  < | . >  | /  ? |
* `--------------------+------+------|                              |------+------+------+------+------'
*               | GUI  |  Sym |Space |                              | Enter|  Nav | GUI  |
*               `------`-------------'                              `-------------'------'
*/
  [LAYER_BASE] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                           KC_J,    KC_L,    KC_U,    KC_Y,  KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T),                   KC_G, KC_M, RCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                                            KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TAB_SYM, SPC_NAV,   ENT_NAV, BSP_NAV, KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

/*
     * Nav/Num Layer: Numbers, navigation
     *
     * ,----------------------------------.                              ,----------------------------------.
     * |   1  |   2  |  3   |  4   |  5   |                              |   6  |   7  |   8  |   9  |  0   |
     * |------+------+------+------+------|                              |------+------+------+------+------|
     * |      |      |      |      | Home |                              |  End |  ←   |   ↓  |  ↑   |  →   |
     * |------+------+------+------+------|                              |------+------+------+------+------|
     * |      | CUT  | COPY | UNDO | PASTE|                              |      | Home | PgDn | PgUp |      |
     * `--------------------+------+------|                              |------+------+------+------+------'
     *               | BSPC |Space |Fkeys |                              | Enter|      |      |
     *               `------`-------------'                              `-------------'------'
     */

  [LAYER_NAVIGATION] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, KC_HOME,                               KC_END, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,     CUT,    COPY,    UNDO,   PASTE,                              KC_PGDN, KC_HOME,  KC_PGDN,  KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, FKEYS, KC_TRNS,     KC_TRNS ,KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

/*
     * Sym Layer: Symbols
     *
     * ,----------------------------------.                                ,-----------------------------------.
     * |        |      |   "  |   \  |      |                              |      |      |  '   |      |       |
     * |--------+------+------+------+------|                              |------+------+------+------+-------|
     * |   !    |   @  |   #  |   $  |   %  |                              |   ^  |   [  |   ]  |   &  |   *   |
     * |--------+------+------+------+------|                              |------+------+------+------+-------|
     * |   ESC  |   ~  |   `  |   |  |   \  |                              |   -  |   -  |   =  |   +  |       |
     * `----------------------+------+------|                              |------+------+------+------+-------'
     *                  |     |      |      |                              | Enter| Fkeys|      |
     *                  `-------------------'                              `-------------'------'
     */

  [LAYER_SYMBOLS] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_DQT, SFT_QT, KC_BSLS, _______,                               _______, _______, ALT_SQT, KC_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_EXLM,   KC_AT, KC_HASH, KC_DLR, KC_PERC,                               KC_CIRC, KC_LBRC, KC_RBRC, KC_AMPR, KC_ASTR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_GRV, KC_PIPE, _______,                                KC_MINS, KC_MINS, KC_EQL, KC_PPLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, FKEYS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

/*
     * Function/media Layer: Function/media keys
     *
     * ,----------------------------------.                              ,-----------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |                              |   F6  |  F7  |  F8  |  F9  | F10  |
     * |------+------+------+------+------|                              |-------+------+------+------+------|
     * |  GUI | Alt  |Shift | Ctrl |      |                              |       | Ctrl |Shift |  Alt | F11  |
     * |------+------+------+------+------|                              |-------+------+------+------+------|
     * |Prtscr|      |      |      |      |                              |Colemak|Vol Up|Vol DN| Mute | F12  |
     * `--------------------+------+------|                              |------+------+------+------+-------'
     *                |     |      |      |                              |      |      |      |
     *                `-------------------'                              `-------------'------'
     */
  [LAYER_FUNCTION] = LAYOUT_split_3x5_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                         KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                              _______, KC_LCTL, KC_LSFT, KC_LALT, KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_PSCR, _______, _______, _______, RGB_TOG,                                _______, KC_VOLU, KC_VOLD, KC_MUTE, KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,     _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// combos
const uint16_t PROGMEM backspace_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM esc_combo[]       = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tab_combo[]       = {LALT_T(KC_R), LSFT_T(KC_S), COMBO_END};
const uint16_t PROGMEM del_combo[]       = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM a_combo[]         = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ae_combo[]        = {RSFT_T(KC_E), LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM oe_combo[]        = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM lprn_combo[]      = {KC_F, LSFT_T(KC_S), COMBO_END};
const uint16_t PROGMEM lcbr_combo[]      = {KC_P, LCTL_T(KC_T), COMBO_END};
const uint16_t PROGMEM lbrc_combo[]      = {KC_W, LALT_T(KC_R), COMBO_END};
const uint16_t PROGMEM rbrc_combo[]      = {KC_Y, LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM rprn_combo[]      = {KC_U, RSFT_T(KC_E), COMBO_END};
const uint16_t PROGMEM rcbr_combo[]      = {KC_L, RCTL_T(KC_N), COMBO_END};
const uint16_t PROGMEM under_combo[]     = {KC_M, KC_K, COMBO_END};
const uint16_t PROGMEM arrow_combo[]     = {LCTL_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM arroweql_combo[]  = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM back_to_colemak[] = {KC_ENT, KC_SPC, COMBO_END};
const uint16_t PROGMEM eql_combo[]       = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM plus_combo[]      = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM minus_combo[]     = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM delword_combo[]   = {KC_H, KC_DOT, COMBO_END};
combo_t                key_combos[]      = {
    COMBO(backspace_combo, KC_BSPC), COMBO(esc_combo, KC_ESC), COMBO(tab_combo, KC_TAB), COMBO(del_combo, KC_DEL), COMBO(ae_combo, RALT(KC_Q)), COMBO(oe_combo, RALT(KC_P)), COMBO(a_combo, RALT(KC_W)), COMBO(lbrc_combo, KC_LBRC), COMBO(rbrc_combo, KC_RBRC), COMBO(lprn_combo, KC_LPRN), COMBO(lcbr_combo, KC_LCBR), COMBO(rprn_combo, KC_RPRN), COMBO(rcbr_combo, KC_RCBR), COMBO(under_combo, KC_UNDS), COMBO(arrow_combo, ARROW), COMBO(arroweql_combo, ARROW_EQL), COMBO(back_to_colemak, COLEMAK), COMBO(eql_combo, KC_EQL), COMBO(minus_combo, KC_MINS), COMBO(plus_combo, KC_PPLS), COMBO(delword_combo, LCTL(KC_BSPC)),
};

// Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            break;

        case ARROW_EQL:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            break;
    }
    return true;
};

// Tapping speed
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_O):
            return TAPPING_TERM + 250;
        case LGUI_T(KC_A):
            return TAPPING_TERM + 250;
        default:
            return TAPPING_TERM;
    }
}

// rgb
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv(4, 75, 150); // warmwhite (werte = hue, saturation, value)
  rgblight_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  // layer rgb
  for (uint8_t i = led_min; i < led_max; i++) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
      //base
      case 0:
        rgblight_sethsv(HSV_MAGENTA);
        break;
      // nav
      case 1:
        // <led-index> {siehe ../../skeletyl.c) <rgb-wert>
        // color thumbs
        rgb_matrix_set_color(35, RGB_ORANGE);
        rgb_matrix_set_color(34, RGB_ORANGE);
        rgb_matrix_set_color(33, RGB_ORANGE);
        break;
      // sym
      case 2:
        // color thumbs
        rgb_matrix_set_color(15, RGB_CYAN);
        rgb_matrix_set_color(16, RGB_CYAN);
        rgb_matrix_set_color(17, RGB_CYAN);
        break;
      // function
      case 3:
        // color thumbs
        rgb_matrix_set_color(35, RGB_GREEN);
        rgb_matrix_set_color(34, RGB_GREEN);
        rgb_matrix_set_color(33, RGB_GREEN);
        rgb_matrix_set_color(15, RGB_GREEN);
        rgb_matrix_set_color(16, RGB_GREEN);
        rgb_matrix_set_color(17, RGB_GREEN);
        break;
      default:
        rgblight_sethsv(HSV_MAGENTA);
        break;
    }
  }
  return false;
}

void keyboard_pre_init_user(void) {
// Disable Liatris LED
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

//This part is the same functionality as zmk require-prior-idle
// Decision macro for mod-tap keys to override
#define IS_HOMEROW_MOD_TAP(kc) ( \
    IS_QK_MOD_TAP(kc) && \
    ((QK_MOD_TAP_GET_TAP_KEYCODE(kc) >= KC_A && \
      QK_MOD_TAP_GET_TAP_KEYCODE(kc) <= KC_Z) || \
      QK_MOD_TAP_GET_TAP_KEYCODE(kc) == KC_SPC))

// Decision macro for preceding trigger key and typing interval
#define IS_TYPING(k) ( \
    ((uint8_t)(k) <= KC_Z || (uint8_t)(k) == KC_SPC) && \
    (last_input_activity_elapsed() < QUICK_TAP_TERM)    )

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool     is_pressed[UINT8_MAX];
    static uint16_t prev_keycode;
    const  uint16_t tap_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

    if (record->event.pressed) {
        // Press the tap keycode if the tap-hold key follows the previous key swiftly
        if (IS_HOMEROW_MOD_TAP(keycode) && IS_TYPING(prev_keycode)) {
            is_pressed[tap_keycode] = true;
            record->keycode = tap_keycode;
        }
        // Cache the keycode for subsequent tap decision
        prev_keycode = keycode;
    }

    // Release the tap keycode if pressed
    else if (is_pressed[tap_keycode]) {
        is_pressed[tap_keycode] = false;
        record->keycode = tap_keycode;
    }

    return true;
}


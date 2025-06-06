#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _SYMBOLS,
    _NUMPAD,
    _SPECIAL,
    _FN,
    _SPNSH,
    _TMUX,
    _ADMIN
};

enum custom_keycodes {
    TERM = SAFE_RANGE,
    T_TAB, 
    T_VSPLIT,
    T_HSPLIT,
    T_RENAME,
    T_SCROLL,
    T_ZOOM,
    T_LEFT,
    T_RIGHT,
    T_UP,
    T_DOWN,
    T_INSTL,
    T_0,
    T_1,
    T_2,
    T_3,
    T_4,
    T_5,
    T_6,
    T_7,
    T_8,
    T_9,
    SPN_A,
    SPN_CA,
    SPN_E,
    SPN_CE,
    SPN_I,
    SPN_CI,
    SPN_O,
    SPN_CO,
    SPN_U,
    SPN_CU,
    SPN_N,
    SPN_CN,
    REBOOT,
    SHUTDOWN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LCtrl |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | LSFT | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [_QWERTY] = LAYOUT(
        KC_ESC,             KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     MO(_ADMIN),
        KC_LCTL,            KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC,
        LT(_TMUX, KC_TAB),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,  MO(_FN),
        KC_LSFT,            KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TERM,          LGUI(KC_TAB), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SCLN,  KC_LCTL,
                                        KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,     KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
/* SYMBOLS (LOWER)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  ^   |  @   |  #   |  $   |  /   |                    |  !   |  &   |  |   |  (   |  )   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  '   |  "   |  `   |  ~   |  +   |                    |  ?   |  %   |  :   |  {   |  }   | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  <   |  >   |  \   |  =   |  *   |-------.    ,-------|  -   |  _   |  ;   |  [   |  ]   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | LSFT | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_SYMBOLS] = LAYOUT(
        XXXXXXX, KC_CIRC, KC_AT,   KC_HASH, KC_DLR,  KC_SLSH,                   KC_EXLM, KC_AMPR, KC_PIPE, KC_LPRN, KC_RPRN, XXXXXXX,
        XXXXXXX, KC_QUOT, KC_DQUO, KC_GRV,  KC_TILD, KC_PLUS,                   KC_QUES, KC_PERC, KC_COLN, KC_LCBR, KC_RCBR, KC_DEL,
        XXXXXXX,   KC_LT, KC_GT,   KC_BSLS, KC_EQL,  KC_ASTR,                   KC_MINS, KC_UNDS, KC_SCLN, KC_LBRC, KC_RBRC, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,    KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
/* NUMPAD (RAISE)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  /   |  7   |  8   |  9   |  -   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  %   |  4   |  5   |  6   |  +   |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  1   |  2   |  3   |  *   |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  0   |      |  .   |  =   |-------|    |-------|      |      |      |      |      | NUM  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | LSFT | RALT |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [_NUMPAD] = LAYOUT(
        XXXXXXX, KC_PSLS, KC_P7, KC_P8,   KC_P9,   KC_PMNS,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_PERC, KC_P4, KC_P5,   KC_P6,   KC_PPLS,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_P1, KC_P2,   KC_P3,   KC_PAST,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_FN),
        XXXXXXX, XXXXXXX, KC_P0, XXXXXXX, KC_PDOT, KC_PEQL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NUM,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,  KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
/* SPECIAL (ADJUST)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |PRINT | HOME | PGUP |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|      |      | END  | PGDN |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_SPECIAL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_PSCR, KC_HOME, KC_PGUP, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,    KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
    [_FN] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LALT, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LCTL, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MO(_FN),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,    KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
    [_SPNSH] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, SPN_A,   SPN_E,   SPN_I,   SPN_O,   SPN_U,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, SPN_CA,  SPN_CE,  SPN_CI,  SPN_CO,  SPN_CU,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SPN_N,   SPN_CN,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,    KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
    [_TMUX] = LAYOUT(
        XXXXXXX, XXXXXXX, T_7, T_8,     T_9,     XXXXXXX,                    XXXXXXX,  T_SCROLL, T_ZOOM,  XXXXXXX, XXXXXXX, T_INSTL,
        XXXXXXX, XXXXXXX, T_4, T_5,     T_6,     T_TAB,                      XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, T_1, T_2,     T_3,     T_RENAME,                   T_LEFT,   T_DOWN,   T_UP,    T_RIGHT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, T_0, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, T_HSPLIT, T_VSPLIT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,    KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
    [_ADMIN] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_RALT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, REBOOT,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, SHUTDOWN, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, KC_U,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_LALT, KC_LGUI, MO(_SYMBOLS), KC_SPC,    KC_ENT, MO(_NUMPAD), KC_LSFT, KC_RALT
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _NUMPAD, _SPECIAL);
    state = update_tri_layer_state(state, _NUMPAD, _FN, _SPNSH);
    return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master())
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        //oled_write_ln(read_host_led_state(), false);
        //oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef OLED_ENABLE
            set_keylog(keycode, record);
        #endif
    // set_timelog();
    }
    switch (keycode) {
        case TERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("t"));
            } else {}
        break;
        case T_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"c");
            } else {}
        break;
        case T_VSPLIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"%");
            } else {}
        break;
        case T_HSPLIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"\"");
            } else {}
        break;
        case T_RENAME:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)",");
            } else {}
        break;
        case T_SCROLL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"[");
            } else {}
        break;
        case T_ZOOM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"z");
            } else {}
        break;
        case T_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)SS_TAP(X_LEFT));
            } else {}
        break;
        case T_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)SS_TAP(X_RGHT));
            } else {}
        break;
        case T_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)SS_TAP(X_UP));
            } else {}
        break;
        case T_DOWN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)SS_TAP(X_DOWN));
            } else {}
        break;
        case T_INSTL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)SS_LSFT("i"));
            } else {}
        break;
        case T_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"0");
            } else {}
        break;
        case T_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"1");
            } else {}
        break;
        case T_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"2");
            } else {}
        break;
        case T_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"3");
            } else {}
        break;
        case T_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"4");
            } else {}
        break;
        case T_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"5");
            } else {}
        break;
        case T_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"6");
            } else {}
        break;
        case T_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"7");
            } else {}
        break;
        case T_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"8");
            } else {}
        break;
        case T_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")SS_DELAY(50)"9");
            } else {}
        break;
        case SPN_A:
            if (record->event.pressed) {
                SEND_STRING("á");
            } else {}
        break;
        case SPN_CA:
            if (record->event.pressed) {
                SEND_STRING("Á");
            } else {}
        break;
        case SPN_E:
            if (record->event.pressed) {
                SEND_STRING("e");
            } else {}
        break;
        case SPN_CE:
            if (record->event.pressed) {
                SEND_STRING("É");
            } else {}
        break;
        case SPN_I:
            if (record->event.pressed) {
                SEND_STRING("í");
            } else {}
        break;
        case SPN_CI:
            if (record->event.pressed) {
                SEND_STRING("Í");
            } else {}
        break;
        case SPN_O:
            if (record->event.pressed) {
                SEND_STRING("ó");
            } else {}
        break;
        case SPN_CO:
            if (record->event.pressed) {
                SEND_STRING("Ó");
            } else {}
        break;
        case SPN_U:
            if (record->event.pressed) {
                SEND_STRING("ú");
            } else {}
        break;
        case SPN_CU:
            if (record->event.pressed) {
                SEND_STRING("Ú");
            } else {}
        break;
        case SPN_N:
            if (record->event.pressed) {
                SEND_STRING("ñ");
            } else {}
        break;
        case SPN_CN:
            if (record->event.pressed) {
                SEND_STRING("Ñ");
            } else {}
        break;
        case REBOOT:
            if (record->event.pressed) {
                SEND_STRING("r"SS_DELAY(1000)"e"SS_DELAY(1000)"i"SS_DELAY(1000)"s"SS_DELAY(1000)"u"SS_DELAY(1000)"b");
            } else {}
        break;
        case SHUTDOWN:
            if (record->event.pressed) {
                SEND_STRING("r"SS_DELAY(1000)"e"SS_DELAY(1000)"i"SS_DELAY(1000)"s"SS_DELAY(1000)"u"SS_DELAY(1000)"o");
            } else {}
        break;
    }
    return true;
}

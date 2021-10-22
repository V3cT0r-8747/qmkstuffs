#include QMK_KEYBOARD_H
extern keymap_config_t keymap_config;

//qmk compile -kb yampad -km yeet
enum layers {
  NUM= 0,
  OSU,
  ART,
  RGB
};

enum custom_keycodes {
  KC_DBL0 = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [NUM] = LAYOUT(
    TG(_NV),  KC_PSLS,  KC_PAST,   LT(_FN, KC_PMNS), \
    KC_P7,    KC_P8,    KC_P9,              \
    KC_P4,    KC_P5,    KC_P6,     KC_PPLS, \
    KC_P1,    KC_P2,    KC_P3,              \
    KC_P0,    KC_DBL0,  KC_PDOT,   KC_PENT
  ),

  [OSU] = LAYOUT(
    KC_ESC,   KC_HOME,  KC_PGUP,   TG(_NV), \
    KC_BTN1,  KC_Z,     KC_X,            \
    KC_SPC,   XXXXXXX,  XXXXXXX,   KC_WH_U, \
    XXXXXXX,  KC_UP,    XXXXXXX,            \
    KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_WH_D
  ),

  [ART] = LAYOUT(
    LCTL(KC_MINS), LCTL(KC_EQL), KC_PGUP,   TG(_NV), \
    KC_PGUP,  LCTL(KC_Z), LCTL(LSFT(KC_Z)),            \
    KC_M,  KC_B,       KC_E,   KC_LBRC, \
    LCTL(LALT(LSFT(KC_F))), KC_T     KC_UP,      XXXXXXX,            \
    KC_LEFT,  KC_DOWN,   KC_RGHT,   KC_RBRC
  ),

  [RGB] = LAYOUT(
    RGB_MOD,  RGB_M_P,  RGB_TOG,   _______, \
    RGB_HUD,  RGB_HUI,  XXXXXXX,            \
    RGB_SAD,  RGB_SAI,  XXXXXXX,   XXXXXXX, \
    RGB_VAD,  RGB_VAI,  XXXXXXX,            \
    RESET,    XXXXXXX,  XXXXXXX,   XXXXXXX
  ),
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  oled_write_P(PSTR("Layer"), false);
  switch (get_highest_layer(layer_state)) {
    case _BL:
      oled_write_ln_P(PSTR(" BAS"), false);
      break;
    case _NV:
      oled_write_ln_P(PSTR(" NAV"), false);
      break;
    case _FN:
      oled_write_ln_P(PSTR(" RGB"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR(" UND"), false);
  }

void oled_task_user(void){
}
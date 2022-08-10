#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum layers {
    _MAIN,
};


//keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  KC_F13,  KC_F14,    KC_F15,    KC_F16, 
  KC_F17,  KC_F18,    KC_F19,    KC_F20, 
  KC_F21,  KC_F22,    KC_F23,    KC_F24
  ),

};







//Loop
void matrix_scan_user(void){
	if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

//encoder

   bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (index == 1) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         Page Down key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_VOLU);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_VOLD);
    }
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
  } else if (index == 0) { /* Second encoder */
    if (clockwise) {
  if (!is_alt_tab_active) {
    is_alt_tab_active = true;
    register_code(KC_LALT);
  }
  alt_tab_timer = timer_read();
  tap_code16(KC_TAB);
} else {
  if (!is_alt_tab_active) {
    is_alt_tab_active = true;
    register_code(KC_LALT);
  }
  alt_tab_timer = timer_read();
  tap_code16(S(KC_TAB));
}
  } 
  return false;
}
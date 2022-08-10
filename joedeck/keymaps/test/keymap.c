#include QMK_KEYBOARD_H


//keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  KC_1,  KC_2,    KC_3,    KC_4, 
  KC_5,  KC_6,    KC_7,    KC_8, 
  KC_9,  KC_0,    KC_6,    KC_9
  ),

};


//Loop
void matrix_scan_user(void){
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
  tap_code16(C(KC_TAB));
} else {
  tap_code16(S(C(KC_TAB)));
}
  } 
  return false;
}
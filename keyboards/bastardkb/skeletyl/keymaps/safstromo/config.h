#pragma once
#define EE_HANDS
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// rgb
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220
#define SPLIT_LAYER_STATE_ENABLE // for layer indicators
#define RGB_TRIGGER_ON_KEYDOWN // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
// rgb timeout; https://gist.github.com/aashreys/01cb34605a290a7cfb94a856bdabc94c?permalink_comment_id=4520204#gistcomment-4520204
#define RGB_MATRIX_TIMEOUT 180000 // = 3min; number of milliseconds to wait until rgb automatically turns off

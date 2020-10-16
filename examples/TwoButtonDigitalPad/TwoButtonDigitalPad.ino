#include <BasicJoystick.h>

// PIN IO
#define DPAD_UP A5
#define DPAD_DOWN A4
#define DPAD_LEFT A3
#define DPAD_RIGHT A2

// Buttons using SNES terminology
#define BUTTON_Y 4
#define BUTTON_B 5

void setup() {
    pinMode(DPAD_LEFT, INPUT_PULLUP);
    pinMode(DPAD_UP, INPUT_PULLUP);
    pinMode(DPAD_RIGHT, INPUT_PULLUP);
    pinMode(DPAD_DOWN, INPUT_PULLUP);

    pinMode(BUTTON_Y, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
}

// Create joystick state structure for HID status reporting
JoyState_t state;

void loop() {
    // Assign button inputs to the state structure
    // Note that most buttons are active low (pressed = signal grounded)
    // so they require inversion.
    
    state.button_Y = !digitalRead(BUTTON_Y);
    state.button_B = !digitalRead(BUTTON_B);

    // Convert the digital joystick position into analog X/Y axis
    if (!digitalRead(DPAD_LEFT))
        state.xAxis = 0;
    else if (!digitalRead(DPAD_RIGHT))
        state.xAxis = 255;
    else
        state.xAxis = 127;

    if (!digitalRead(DPAD_UP))
        state.yAxis = 0;
    else if (!digitalRead(DPAD_DOWN))
        state.yAxis = 255;
    else
        state.yAxis = 127;
    
    // Set the state values and send back to the host device
    BasicJoystick.setState(state);
}

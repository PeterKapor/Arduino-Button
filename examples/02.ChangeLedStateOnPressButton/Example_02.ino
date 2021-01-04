#include "Button.h"

#define LED_PIN 13
#define BUTTON_PIN 12

#define BUTTON_DEBOUNCE_TIME 10

Button button12(BUTTON_PIN, Button::ButtonInputSetting::DownIsLow, BUTTON_DEBOUNCE_TIME);
bool ledState = LOW;

void setup() {
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, ledState);
}

void loop() {
	// refresh state of the button
	button12.refresh();

	// check the button state
	if (button12.isPressed()) {
		// change the ledState
		ledState = !ledState;
		
		// turn on or off the LED
		digitalWrite(LED_PIN, ledState);
	}
}

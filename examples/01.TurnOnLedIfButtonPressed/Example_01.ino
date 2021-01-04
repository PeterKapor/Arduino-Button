#include "Button.h"

#define LED_PIN 13
#define BUTTON_PIN 12

#define BUTTON_DEBOUNCE_TIME 10

Button button12(BUTTON_PIN, Button::ButtonInputSetting::DownIsLow, BUTTON_DEBOUNCE_TIME);

void setup() {
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
	// refresh state of the button
	button12.refresh();

	// check the button state and set the LED state
	bool ledState = (button12.isDown())
		? HIGH
		: LOW;

	// turn on or off the LED
	digitalWrite(LED_PIN, ledState);
}

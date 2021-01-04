#include "Button.h"

#define BUTTON_PIN 12

#define BUTTON_DEBOUNCE_TIME 10

Button button12(BUTTON_PIN, Button::ButtonInputSetting::DownIsLow, BUTTON_DEBOUNCE_TIME);

void setup() {
	Serial.begin(9600);
}

void loop() {
	// refresh state of the button
	button12.refresh();

	// check the button state
	Button::ButtonState buttonState = button12.getState();
	
	// send button state
	Serial.print("Button state: ");
	Serial.println(buttonStateToString(buttonState));

	delay(100);
}

String buttonStateToString(int buttonState) {
	switch (buttonState) {
		case Button::ButtonState::Up:
			return "Up";
		case Button::ButtonState::Down:
			return "Down";
		case Button::ButtonState::Released:
			return "Released";
		case Button::ButtonState::Pressed:
			return "Pressed";
		default:
			return "undefined";
	}
	return "undefined";
}

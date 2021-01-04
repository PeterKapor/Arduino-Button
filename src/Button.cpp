#include "Button.h"

Button::Button(uint8_t buttonPin, ButtonInputSetting buttonInputSetting, uint32_t debounceDelay) {
	_buttonPin = buttonPin;
	_debounceDelay = debounceDelay;
	pinMode(_buttonPin, INPUT);

	_downState = (buttonInputSetting == ButtonInputSetting::DownIsHigh) ? HIGH : LOW;
	_upState = (buttonInputSetting == ButtonInputSetting::DownIsHigh) ? LOW : HIGH;
	
	_lastButtonState = (digitalRead(_buttonPin) == _downState)
		? Button::ButtonState::Down
		: Button::ButtonState::Up;
	_lastDebounceTime = millis();
}

void Button::refresh() {
	long actualTime = millis();
	Button::ButtonState actualButtonState = (digitalRead(_buttonPin) == _downState)
		? Button::ButtonState::Down
		: Button::ButtonState::Up;

	// not changed
	if (actualButtonState == _lastButtonState) {
		return;
	}

	// changed
	bool hasLastStateChangedFlag = isChanged();
	bool isDebounced = (actualTime > _lastDebounceTime)
		? ((actualTime - _lastDebounceTime) >= _debounceDelay)
		: ((_lastDebounceTime - actualTime) <= _debounceDelay);
	_lastDebounceTime = actualTime;

	if (hasLastStateChangedFlag) {
		_lastButtonState = (Button::ButtonState)(_lastButtonState & ~Button::ButtonState::Changed);
	}
	else if (isDebounced) {
		_lastButtonState = (Button::ButtonState)(actualButtonState | Button::ButtonState::Changed);
	}
	else {
		_lastButtonState = actualButtonState;
	}
}

Button::ButtonState Button::getState() {
	return _lastButtonState;
}

bool Button::isUp() {
	return (_lastButtonState & Button::ButtonState::Up) == Button::ButtonState::Up;
}

bool Button::isDown() {
	return (_lastButtonState & Button::ButtonState::Down) == Button::ButtonState::Down;
}

bool Button::isChanged() {
	return (_lastButtonState & Button::ButtonState::Changed) == Button::ButtonState::Changed;
}

bool Button::isPressed() {
	return (_lastButtonState & Button::ButtonState::Pressed) == Button::ButtonState::Pressed;
}

bool Button::isReleased() {
	return (_lastButtonState & Button::ButtonState::Released) == Button::ButtonState::Released;
}

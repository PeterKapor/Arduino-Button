// Button.h

#include "Arduino.h"

#ifndef _BUTTON_h
#define _BUTTON_h

class Button {
public:
	enum ButtonInputSetting {
		DownIsLow,
		DownIsHigh
	};

	enum ButtonState : int {
		Up = 0b001,	// 1
		Down = 0b010, // 2
		Changed = 0b100, // 4
		Released = 0b101, // 5 up | changed
		Pressed = 0b110 // 6 down | changed
	};

	Button(uint8_t buttonPin, ButtonInputSetting buttonInputSetting = ButtonInputSetting::DownIsLow, uint32_t debounceDelay = 50);
	void refresh();
	ButtonState getState();
	bool isUp();
	bool isDown();
	bool isChanged();
	bool isPressed();
	bool isReleased();

private:
	uint8_t _buttonPin;
	uint32_t _debounceDelay;
	uint32_t _lastDebounceTime;
	ButtonState _lastButtonState;
	int _downState;
	int _upState;
};

#endif


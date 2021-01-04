# kButton
The kButton library is simple implementation for buttons. It can return states of the button (up, down, changed, pressed or released).

## Features
- Supports **debouncing**
  - default is 50
- Supports multiple **states**
  - **up** - when the button is up (not pressed)
  - **down** - when the button is down (pressed)
  - **changed** - when the state has been changed from the latest **refresh()**
  - **released** - when the state has been changed to up
  - **pressed** - when the state has been changed to down
- Supports both types of button
  - **DownIsLow** - when the button is pressed, it is reading LOW
  - **DownIsHigh** - when the button is pressed, it is reading HIGH

## Examples
- **01.TurnOnLedIfButtonPressed** - turn the LED on or off based on the state of the button (if the button is down the LED is on)
- **02.ChangeLedStateOnPressButton** - toggle the LED when the button is pressed (in **pressed** stated)
- **03.SendState** - send the button state to Serial Monitor

## Constructor and Methods
- **Button**(uint8_t buttonPin, ButtonInputSetting buttonInputSetting = ButtonInputSetting::DownIsLow, uint32_t debounceDelay = 50)
  - buttonPin - pin where the button is connected
  - buttonInputSetting - type of button (DownIsLow or DownIsHigh), default is DownIsLow
  - debounceDelay - debounce settings, default is 50
- **refresh()** - required to be called periodically (e.g. on the beggining of the loop) before checking of the state
- **getState()** - get raw state (enum)
- **isUp()** - returns true if Up flag is on (Up or Pressed state)
- **isDown()** - returns true if Down flag is on (Down or Released state)
- **isChanged()** - returns true if Changed flag is on (Pressed or Released state)
- **isPressed()** - returns true if Changed flag and Down flag is on (only Pressed state)
- **isReleased()** - returns true if Changed flag and Up flag is on (only Released state)

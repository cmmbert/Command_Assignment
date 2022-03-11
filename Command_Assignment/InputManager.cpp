//#define WIN32_LEAN_AND_MEAN //why was this in the example?
#include "InputManager.h"


#include "DuckCommand.h"
#include "FartCommand.h"
#include "FireCommand.h"
#include "JumpCommand.h"


void dae::InputManager::ProcessInput()
{
	CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &currentState);

	auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
	buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
	buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);
}


Command* dae::InputManager::HandleInput()
{
	CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &currentState);

	auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
	buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
	buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);

	if (IsPressed(eControllerButton::ButtonX)) return new FireCommand();
	if (IsPressed(eControllerButton::ButtonY)) return new JumpCommand();
	if (IsPressed(eControllerButton::ButtonA)) return new DuckCommand();
	if (IsPressed(eControllerButton::ButtonB)) return new FartCommand();

	return nullptr;
}

bool dae::InputManager::IsPressed(eControllerButton buttonMask) const
{
	return buttonsPressedThisFrame & static_cast<int>(buttonMask);
}

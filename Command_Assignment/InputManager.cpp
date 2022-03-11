//#define WIN32_LEAN_AND_MEAN //why was this in the example?
#include "InputManager.h"
#include <Xinput.h>
#pragma comment(lib, "xinput.lib")


#include "DuckCommand.h"
#include "FartCommand.h"
#include "FireCommand.h"
#include "JumpCommand.h"


class dae::InputManager::impl
{
public:
	XINPUT_STATE previousState{};
	XINPUT_STATE currentState{};
};

dae::InputManager::InputManager()
	: pimpl({std::make_unique<impl>()})
{

}

dae::InputManager::~InputManager() = default;

Command* dae::InputManager::HandleInput()
{
	CopyMemory(&pimpl->previousState, &pimpl->currentState, sizeof(XINPUT_STATE));
	ZeroMemory(&pimpl->currentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &pimpl->currentState);

	auto buttonChanges = pimpl->currentState.Gamepad.wButtons ^ pimpl->previousState.Gamepad.wButtons;
	buttonsPressedThisFrame = buttonChanges & pimpl->currentState.Gamepad.wButtons;
	buttonsReleasedThisFrame = buttonChanges & (~pimpl->currentState.Gamepad.wButtons);

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

#pragma once
#include <Windows.h>
#pragma comment(lib, "xinput.lib")
#include <Xinput.h>

namespace dae
{
	enum class eControllerButton
	{
		ButtonA = 0x1000,
		ButtonB = 0x2000,
		ButtonX = 0x4000,
		ButtonY = 0x8000,
	};

	class InputManager
	{
	public:
		void ProcessInput();
		bool IsPressed(eControllerButton buttonMask) const;

	private:
		XINPUT_STATE previousState{};
		XINPUT_STATE currentState{};
		int buttonsPressedThisFrame{};
		int buttonsReleasedThisFrame{};
	};
}

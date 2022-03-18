#pragma once
#include <memory>

class Command;

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
		InputManager();
		~InputManager();
		Command* HandleInput();
		bool IsPressed(eControllerButton buttonMask) const;

	private:
		class impl;
		std::unique_ptr<impl> pimpl;
		int buttonsPressedThisFrame{};
		int buttonsReleasedThisFrame{};
	};
}

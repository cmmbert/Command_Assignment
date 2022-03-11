#include <vld.h>
#include <iostream>
#include <thread>
#include "InputManager.h"

using namespace dae;

int main()
{
	auto inputManager = InputManager();
	auto t = std::chrono::high_resolution_clock::now();

	while (true)
	{
		inputManager.ProcessInput();

		if (inputManager.IsPressed(eControllerButton::ButtonA))
			std::cout << "Button A has been pressed" << std::endl;
		else if (inputManager.IsPressed(eControllerButton::ButtonB))
			std::cout << "Button B has been pressed" << std::endl;
		else if (inputManager.IsPressed(eControllerButton::ButtonY))
			std::cout << "Button Y has been pressed" << std::endl;
		else if (inputManager.IsPressed(eControllerButton::ButtonX))
		{
			std::cout << "Button X has been pressed" << std::endl;
			break;
		}

		t += std::chrono::milliseconds(16); // we want 60 fps
		std::this_thread::sleep_until(t);
	}
	std::cout << "Let's end." << std::endl;

}

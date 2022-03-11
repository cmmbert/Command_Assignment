#include <vld.h>
#include <iostream>
#include <thread>

#include "Command.h"
#include "InputManager.h"

using namespace dae;

//no command impl
void NoCommandInput()
{
	auto inputManager = InputManager();

	inputManager.ProcessInput();

	if (inputManager.IsPressed(eControllerButton::ButtonA))
		std::cout << "Button A has been pressed" << std::endl;
	else if (inputManager.IsPressed(eControllerButton::ButtonB))
		std::cout << "Button B has been pressed" << std::endl;
	else if (inputManager.IsPressed(eControllerButton::ButtonY))
		std::cout << "Button Y has been pressed" << std::endl;
	else if (inputManager.IsPressed(eControllerButton::ButtonX))
		std::cout << "Button X has been pressed" << std::endl;
}


int main()
{
	auto inputManager = InputManager();
	auto t = std::chrono::high_resolution_clock::now();

	while (true)
	{
		Command* command = inputManager.HandleInput();

		if(command)
		{
			command->Execute();
		}

		t += std::chrono::milliseconds(16); // we want 60 fps
		std::this_thread::sleep_until(t);
	}
	std::cout << "Let's end." << std::endl;

}

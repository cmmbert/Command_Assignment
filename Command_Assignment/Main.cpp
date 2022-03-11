#include <vld.h>
#include <iostream>
#include <thread>

#include "Command.h"
#include "InputManager.h"

using namespace dae;



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

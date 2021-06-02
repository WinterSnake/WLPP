/*
	Window Library: Window Test
	Written by: Ryan Smith
*/

// Include: Standard Library
#include <memory>
#include <string>

// Include: WL
#include "WL/wl.hpp"

int main(int argc, char** argv)
{
	WL::Properties properties = {
		.title = "My First Window",
		.size = {
			.width = 800,
			.height = 600
		}
	};

	std::unique_ptr<WL::Window> window = WL::Window::Create(properties);

	while (WL::Event event = window->Poll_Event())
	{
		if (event.type == WL::EVENT::KEY_PRESS && event.key == WL::KEY::ESC)
		{
			window->Exit_Event_Poll();
		}
	}
	return 0;
}


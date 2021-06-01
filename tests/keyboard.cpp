/*
	Window Library: Keyboard Input Test
	Written by: Ryan Smith
*/

// Include: Standard Library
#include <memory>

// Include: WL
#include "WL/wl.hpp"

int main(int argc, char** argv)
{
	WL::Properties properties = {
		.title = "Keyboard Input Testing",
		.size = {
			.width = 800,
			.height = 600
		}
	};

	std::unique_ptr<WL::Window> window = WL::Window::Create(properties);

	return 0;
}


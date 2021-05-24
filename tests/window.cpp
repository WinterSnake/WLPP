/*
	Window Library: Main Window Test
	Written by: Ryan Smith
*/

// Include: WL
#include "WL/wl.hpp"

int main(int argc, char** argv)
{
	WL::Properties properties = {
		.title = "My first Window",
		.size = {
			.fullscreen = true
		}
	};

	return 0;
}

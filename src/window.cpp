/*
	Window Library
	Written by: Ryan Smith

	- Agnostic Window Class
*/

// Include: WL
#include "window.hpp"

namespace WL
{
	// Window Creation & Deletion
	Window::Window(Properties& properties)
	:window_properties(properties) {}
	Window::~Window() {}

	// Agnostic Window API
	void Window::Exit_Event_Poll()
	{
		_exitloop = true;
	}

	Event Window::Poll_Event()
	{
		if (_exitloop)
		{
			return Event { .type = EVENT::END_LOOP };
		}
		return Event { .type = EVENT::NONE };
	}
}

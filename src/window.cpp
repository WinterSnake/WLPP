/*
	Window Library
	Written by: Ryan Smith

	- Agnostic Window Class
*/

// Include: WL
#include "window.hpp"

namespace WL
{
	Window::Window(Properties& properties)
	:window_properties(properties) {}
	Window::~Window() {}
}

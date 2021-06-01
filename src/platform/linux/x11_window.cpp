/*
	Window Library
	Written by: Ryan Smith

	- Linux X11 Window Class
*/

// Include: Standard Library
#include <memory>

// Include: WL
#include "platform/linux/x11_window.hpp"

namespace WL
{
	// Window::Create Overwrite
	std::unique_ptr<Window> Window::Create(Properties& properties)
	{
		return std::unique_ptr<Window>(new LinuxWindow_X11(properties));
	}
	// Native Handle
	Native_Handle LinuxWindow_X11::Get_Native_Handle()
	{
		return handle;
	}

	// Linux X11 Window
	LinuxWindow_X11::LinuxWindow_X11(Properties& properties)
	:Window(properties)
	{

	}
	
	LinuxWindow_X11::~LinuxWindow_X11()
	{

	}
}

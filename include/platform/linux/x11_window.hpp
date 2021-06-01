/*
	Window Library
	Written by: Ryan Smith

	- Linux X11 Native Handle Struct
	- Linux X11 Window Class
*/
#pragma once

// Include: X11
#include <X11/Xlib.h>

// Include: WL
#include "window.hpp"

namespace WL
{
	struct Native_Handle
	{
		::Display* display;
		::Window window;
	};

	class LinuxWindow_X11 final: public Window
	{
		public:
			LinuxWindow_X11(Properties& properties);
			~LinuxWindow_X11();
			// Overrides
			Event Poll_Event() override;
			Native_Handle Get_Native_Handle() override;

		private:
			Native_Handle handle;
	};
}

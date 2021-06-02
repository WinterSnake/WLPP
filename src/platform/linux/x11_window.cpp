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

	// Linux X11 Window
	LinuxWindow_X11::LinuxWindow_X11(Properties& properties)
	:Window(properties)
	{
		handle.display = XOpenDisplay(nullptr);
		// Handle display error
		if (!handle.display) {}

		// Create screen and attributes
		int screenID = DefaultScreen(handle.display);

		XSetWindowAttributes attributes = {
			.background_pixel = WhitePixel(handle.display, screenID),
			.event_mask = (
				ExposureMask    | PointerMotionMask |
				KeyPressMask    | KeyReleaseMask    |
				ButtonPressMask | ButtonReleaseMask
			)
		};

		// Handle centering
		// Handle fullscreen

		// Create window
		handle.window = XCreateWindow(
			handle.display, RootWindow(handle.display, screenID),
			properties.position.x, properties.position.y,
			properties.size.width, properties.size.height,
			0, DefaultDepth(handle.display, screenID), InputOutput,
			DefaultVisual(handle.display, screenID),
			CWEventMask | CWBackPixel, &attributes
		);

		// Set title
		XStoreName(handle.display, handle.window, properties.title.c_str());

		// Display window
		XMapWindow(handle.display, handle.window);
	}
	
	LinuxWindow_X11::~LinuxWindow_X11()
	{
		XDestroyWindow(handle.display, handle.window);
		XCloseDisplay(handle.display);
	}

	// Native Handle
	Native_Handle LinuxWindow_X11::Get_Native_Handle()
	{
		return handle;
	}

	// Platform Overrides
	Event LinuxWindow_X11::Poll_Event()
	{
		Event event = Window::Poll_Event();
		// Exit Loop Event
		if (event.type == EVENT::END_LOOP)
		{
			return event;
		}
		// X11 Event Handler
		::XEvent _event;
		XNextEvent(handle.display, &_event);

		switch (event.type)
		{

		}

		return event;
	}
}

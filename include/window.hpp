/*
	Window Library
	Written by: Ryan Smith

	- Window Properties Struct
	- Agnostic Window Class
*/
#pragma once

// Include: Standard Library
#include <memory>
#include <string>

namespace WL
{
	struct Native_Handle;

	struct Properties
	{
		std::string title;
		// Window Dimensions
		struct
		{
			uint32_t x;
			uint32_t y;
			bool centered;
		} position;
		struct
		{
			uint32_t width;
			uint32_t height;
			bool fullscreen;
		} size;
	};

	class Window
	{
		public:
			Window(Properties& properties);
			virtual ~Window();

			// Agnostic Window API
			static std::unique_ptr<Window> Create(Properties& properties);
			Native_Handle Get_Native_Handle();

		protected:
			bool running = false;
			Properties window_properties;
	};
}

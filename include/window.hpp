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

// Include: WL
#include <event.hpp>

namespace WL
{
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
			void Exit_Event_Poll();
			virtual Event Poll_Event();
			virtual struct Native_Handle Get_Native_Handle() = 0;

		protected:
			bool initialized = false;
			Properties window_properties;

		private:
			bool _exitloop = false;
	};
}

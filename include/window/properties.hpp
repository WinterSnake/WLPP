/*
	Window Library
	Written by: Ryan Smith

	- Window Properties Struct
*/

// Include: Standard Library
#include <cstdint>
#include <string>

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
			bool centered = true;
		} position;
		struct
		{
			uint32_t width;
			uint32_t height;
			bool fullscreen = false;
		} size;
	};
}

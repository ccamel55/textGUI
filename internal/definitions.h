#pragma once

#include <Windows.h>

#include <array>
#include <vector>
#include <string>

#define TGUI_TKL_MODE

namespace TGUI {

	using COLOUR = struct TGUI_COLOUR {

		TGUI_COLOUR() = default;

		TGUI_COLOUR(int r, int g, int b) : 
			r(r),
			g(g), 
			b(b) { };

		TGUI_COLOUR(int r, int g, int b, int a) : 
			r(r), 
			g(g), 
			b(b), 
			a(a) { };

		int r = 0;
		int g = 0;
		int b = 0;
		int a = 255;
	};

	using POINT = struct TGUI_POINT {

		TGUI_POINT() = default;

		TGUI_POINT(int x, int y) : 
			x(x), 
			y(y) { };

		int x = 0;
		int y = 0;
	};

	struct TGUI_CONTROL_TEXT {

		TGUI_CONTROL_TEXT() = default;

		TGUI_CONTROL_TEXT(const std::string& name, const TGUI::COLOUR& colour) : 
			m_name(name), 
			m_colour(colour) { }

		std::string m_name = {};
		TGUI::COLOUR m_colour = {};
	};

	using INT_CONTROL_TEXT = std::vector<TGUI::TGUI_CONTROL_TEXT>;
	using BOOL_CONTROL_TEXT = std::array<TGUI::TGUI_CONTROL_TEXT, 2u>;

	namespace KEYBIND {

#ifdef TGUI_TKL_MODE

		// Use arrowkeys and right control to navigate menu
		inline UINT menuOpen = VK_INSERT;
		inline UINT selectOption = VK_DELETE;

		inline UINT moveUp = VK_UP;
		inline UINT moveDown = VK_DOWN;
		inline UINT moveLeft = VK_LEFT;
		inline UINT moveRight = VK_RIGHT;

#else

		// Use the numpad to navigate menu
		inline UINT menuOpen = VK_INSERT;
		inline UINT selectOption = VK_NUMPAD5;

		inline UINT moveUP = VK_NUMPAD8;
		inline UINT moveDown = VK_NUMPAD2;
		inline UINT moveLeft = VK_NUMPAD4;
		inline UINT moveRight = VK_NUMPAD6;

#endif
	}

	namespace OFFSET {

		inline int drawGroupItems = 6;
		inline int drawGroupScrollPadding = 1;

		inline TGUI::POINT menuPosition = { 300, 50 };

		inline TGUI::POINT controlSpacing = { 220, 15 };
		inline TGUI::POINT drawGroupSpacing = { 250, 0 };
	}

	namespace COLOURS {
		
		inline TGUI::COLOUR white = TGUI::COLOUR(255, 255, 255);
		inline TGUI::COLOUR blue = TGUI::COLOUR(45, 125, 215);
		inline TGUI::COLOUR light_blue = TGUI::COLOUR(95, 160, 250);
		inline TGUI::COLOUR green = TGUI::COLOUR(20, 195, 55);
		inline TGUI::COLOUR red = TGUI::COLOUR(215, 40, 25);
		inline TGUI::COLOUR yellow = TGUI::COLOUR(245, 245, 60);
		inline TGUI::COLOUR black = TGUI::COLOUR(0, 0, 0);
	}
}
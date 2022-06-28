#pragma once

// GUI INCLUDEs
#include "definitions.h"

namespace TGUI {

	// need to impliment your own draw and input handing functions
	using TGUI_FONT = std::shared_ptr<class fontClass>;

	namespace RENDER {

		// main control font we will use
		inline TGUI::TGUI_FONT controlFont = nullptr;

		enum TGUI_STRING_ALIGN : UINT {
			leftAlign,
			rightAlign,
		};

		inline void drawString(int posX, int posY, TGUI::TGUI_FONT font, const TGUI::COLOUR& colour, const std::string& string, UINT align = leftAlign) {

			// WRAP YOUR OWN DRAWSTRING FUNCTION

		}

		inline void drawRect(int posX, int posY, int width, int height, const TGUI::COLOUR& colour) {

			// WRAP YOUR OWN DRAWRECT FUNCTION
			
		}

		inline void drawRectFilled(int posX, int posY, int width, int height, const TGUI::COLOUR& colour) {

			// WRAP YOUR OWN DRAWRECTFILLED FUNCTION
			
		}

		inline TGUI_FONT createFont(const std::string& fontName, int height, int weight, bool outline) {

			// WRAP YOUR OWN CREATEFONT FUNCTION
			
		}
	}

	namespace INPUT {

		inline bool keyPressed(UINT vkCode) {

		}

		inline bool keyDown(UINT vkCode) {

		}
	}
}
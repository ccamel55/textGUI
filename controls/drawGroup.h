#pragma once

#include "controls.h"

namespace TGUI {

	class TGUI_DRAW_GROUP :
		public TGUI::TGUI_CONTROL_BASE {
	public:
		TGUI_DRAW_GROUP(const TGUI::POINT& position);
		void addControl(std::shared_ptr<TGUI::TGUI_CONTROL_BASE> control);

		void draw() override;
		void update() override;

		TGUI::POINT getDrawPos() override;
		TGUI::POINT getControlPos()override ;
	private:
		int m_cursor = 0;
		int m_scrollStart = 0;

		TGUI::POINT m_controlOffset = { 0, 0 };
	};
}
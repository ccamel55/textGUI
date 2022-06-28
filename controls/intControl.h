#pragma once

#include "controls.h"
#include "drawGroup.h"

namespace TGUI {

	class TGUI_INT_CONTROL :
		public TGUI::TGUI_CONTROL_BASE {
	public:
		TGUI_INT_CONTROL(const std::string& name, int* var, const TGUI::INT_CONTROL_TEXT& displayText);
		void addDrawGroup(std::shared_ptr<TGUI::TGUI_DRAW_GROUP> drawGroup);

		void draw() override;
		void update() override;

		TGUI::POINT getDrawPos() override;
		TGUI::POINT getControlPos() override;
	private:
		int* m_var = NULL;
		TGUI::INT_CONTROL_TEXT m_displayText = {};
	};
}
#pragma once

#include "controls.h"
#include "drawGroup.h"

namespace TGUI {

	class TGUI_BOOL_CONTROL :
		public TGUI::TGUI_CONTROL_BASE {
	public:
		TGUI_BOOL_CONTROL(const std::string& name, bool* var, const TGUI::BOOL_CONTROL_TEXT& displayText);
		void addDrawGroup(std::shared_ptr<TGUI::TGUI_DRAW_GROUP> drawGroup);

		void draw() override;
		void update() override;

		TGUI::POINT getDrawPos() override;
		TGUI::POINT getControlPos() override;
	private:
		bool* m_var = NULL;
		TGUI::BOOL_CONTROL_TEXT m_displayText = {};
	};
}
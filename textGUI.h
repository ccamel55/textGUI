#pragma once

// use arrow key keybinds
#define TGUI_TKL_MODE

#include "controls/drawGroup.h"
#include "controls/boolControl.h"
#include "controls/intControl.h"

class c_textGUI {
public:
	void createGUI();
	void destroyGUI();
	void drawGUI();
	void updateGUI();
private:
	bool m_isOpen = false;

	std::string m_title = "";
	std::shared_ptr<TGUI::TGUI_DRAW_GROUP> m_mainDrawGroup = NULL;
};

inline c_textGUI textGUI;
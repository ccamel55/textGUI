#include "intControl.h"

TGUI::TGUI_INT_CONTROL::TGUI_INT_CONTROL(const std::string& name, int* var, const TGUI::INT_CONTROL_TEXT& displayText) {

	m_name = name;
	m_displayText = displayText;

	m_var = var;
}

void TGUI::TGUI_INT_CONTROL::draw() {

	const auto controlPos = getControlPos();

	// draw control stuff
	{
		TGUI::RENDER::drawString(controlPos.x, controlPos.y, TGUI::RENDER::controlFont, TGUI::COLOURS::white, m_name);
		TGUI::RENDER::drawString(controlPos.x + TGUI::OFFSET::controlSpacing.x, controlPos.y, TGUI::RENDER::controlFont, m_displayText.at(*m_var).m_colour, m_displayText.at(*m_var).m_name, TGUI::RENDER::rightAlign);
	}
}

void TGUI::TGUI_INT_CONTROL::update() {

	//cycle options
	if (m_parent->hasControl() && TGUI::INPUT::keyPressed(TGUI::KEYBIND::selectOption)) {

		if (*m_var >= m_displayText.size() - 1)
			*m_var = 0;
		else
			*m_var += 1;
	}
}

TGUI::POINT TGUI::TGUI_INT_CONTROL::getDrawPos() {

	// we will always have a parent, we just want to get the draw pos of the drawGroup this control belongs to
	return m_parent->getDrawPos();
}

TGUI::POINT TGUI::TGUI_INT_CONTROL::getControlPos() {

	const auto parentControlPos = m_parent->getControlPos();
	return TGUI::POINT(parentControlPos.x, parentControlPos.y + m_pos.y);
}

void TGUI::TGUI_INT_CONTROL::addDrawGroup(std::shared_ptr<TGUI::TGUI_DRAW_GROUP> drawGroup) {

	drawGroup->setParent(shared_from_this());

	// if we have an m_active, it means we have another drawGroup
	drawGroup->disableControl();
	m_active = drawGroup;
}
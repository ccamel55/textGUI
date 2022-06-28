#include "controls.h"

// in compiler we trust to inline

void TGUI::TGUI_CONTROL_BASE::enableControl() {

	m_hasControl = true;
}

void TGUI::TGUI_CONTROL_BASE::disableControl() {

	m_hasControl = false;
}

bool TGUI::TGUI_CONTROL_BASE::hasControl() {

	return m_hasControl;
}

void TGUI::TGUI_CONTROL_BASE::setName(const std::string& name) {

	m_name = name;
}

std::string TGUI::TGUI_CONTROL_BASE::getName() {

	return m_name;
}

void TGUI::TGUI_CONTROL_BASE::setPos(const TGUI::POINT& pos) {

	m_pos = pos;
}

TGUI::POINT TGUI::TGUI_CONTROL_BASE::getPos() {

	return m_pos;
}

void TGUI::TGUI_CONTROL_BASE::setParent(std::shared_ptr<TGUI::TGUI_CONTROL_BASE> parent) {

	m_parent = parent;
}

std::shared_ptr<TGUI::TGUI_CONTROL_BASE> TGUI::TGUI_CONTROL_BASE::getParent() {

	return m_parent;
}

void TGUI::TGUI_CONTROL_BASE::setActive(std::shared_ptr<TGUI::TGUI_CONTROL_BASE> active) {

	m_active = active;
}

std::shared_ptr<TGUI::TGUI_CONTROL_BASE> TGUI::TGUI_CONTROL_BASE::getActive() {

	return m_active;
}
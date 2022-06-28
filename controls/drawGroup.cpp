#include "drawGroup.h"

TGUI::TGUI_DRAW_GROUP::TGUI_DRAW_GROUP(const TGUI::POINT& position) {

	m_pos = position;
	m_hasControl = true;
}

void TGUI::TGUI_DRAW_GROUP::draw() {

	// draw all our controls
	for (int i = m_scrollStart; i < std::min<int>(TGUI::OFFSET::drawGroupItems + m_scrollStart, static_cast<int>(m_children.size())); i++)
		m_children.at(i)->draw();

	// draw drawGroup if our current element has one
	if (m_active && m_active->getActive())
		m_active->getActive()->draw();

	const auto drawPos = getDrawPos();

	// if we can control this drawGroup, show selection cursor
	if (!m_children.empty() && m_hasControl)
	{
		//draw active indicator
		const auto cursorOffsetY = TGUI::OFFSET::controlSpacing.y * (m_cursor - m_scrollStart);

		TGUI::RENDER::drawRectFilled(drawPos.x - 8, drawPos.y + cursorOffsetY + 1, 3, 13, TGUI::COLOURS::light_blue);
		TGUI::RENDER::drawRect(drawPos.x - 8, drawPos.y + cursorOffsetY + 1, 3, 13, TGUI::COLOURS::black);
	}

	// total element counter
	{
		const auto drawStr = std::string("[" + std::to_string(m_cursor + 1) + "/" + std::to_string(m_children.size()) + "]");
		TGUI::RENDER::drawString(drawPos.x + TGUI::OFFSET::controlSpacing.x, drawPos.y + (TGUI::OFFSET::controlSpacing.y * std::min<int>(TGUI::OFFSET::drawGroupItems, static_cast<int>(m_children.size()))), TGUI::RENDER::controlFont, TGUI::COLOURS::light_blue, drawStr, TGUI::RENDER::rightAlign);
	}
}

void TGUI::TGUI_DRAW_GROUP::update() {

	// when we want to go to the next drawGroup, set m_has_control to false on this group
	//		and stop all control passing on our control element, only pass controls to drawGroup

	if (m_children.size() > 1 && m_hasControl)
	{
		if (TGUI::INPUT::keyPressed(TGUI::KEYBIND::moveUp))
		{
			if (m_cursor <= 0)
				m_cursor = static_cast<int>(m_children.size()) - 1;
			else
				m_cursor -= 1;

			m_active = m_children.at(m_cursor);

			// check if we need to change scrollStart
			if (m_children.size() > TGUI::OFFSET::drawGroupItems) {

				if (m_cursor > m_scrollStart + (TGUI::OFFSET::drawGroupItems - (TGUI::OFFSET::drawGroupScrollPadding * 2)))
					m_scrollStart = std::min<int>(static_cast<int>(m_children.size()) - TGUI::OFFSET::drawGroupItems, m_cursor - (TGUI::OFFSET::drawGroupItems - (TGUI::OFFSET::drawGroupScrollPadding * 2)));
				else if (m_cursor < m_scrollStart + TGUI::OFFSET::drawGroupScrollPadding)
					m_scrollStart = std::max<int>(0, m_cursor - TGUI::OFFSET::drawGroupScrollPadding);
			}

			return;
		}

		if (TGUI::INPUT::keyPressed(TGUI::KEYBIND::moveDown))
		{
			if (m_cursor >= static_cast<int>(m_children.size()) - 1)
				m_cursor = 0;
			else
				m_cursor += 1;

			m_active = m_children.at(m_cursor);

			// check if we need to change scrollStart
			if (m_children.size() > TGUI::OFFSET::drawGroupItems) {

				if (m_cursor > m_scrollStart + (TGUI::OFFSET::drawGroupItems - (TGUI::OFFSET::drawGroupScrollPadding * 2)))
					m_scrollStart = std::min<int>(static_cast<int>(m_children.size()) - TGUI::OFFSET::drawGroupItems, m_cursor - (TGUI::OFFSET::drawGroupItems - (TGUI::OFFSET::drawGroupScrollPadding * 2)));
				else if (m_cursor < m_scrollStart + TGUI::OFFSET::drawGroupScrollPadding)
					m_scrollStart = std::max<int>(0, m_cursor - TGUI::OFFSET::drawGroupScrollPadding);
			}

			return;
		}
	}
	
	// check if current control has a drawGroup
	if (m_active->getActive()) {

		if (TGUI::INPUT::keyPressed(TGUI::KEYBIND::moveRight) && m_hasControl)
		{
			// pass control to other drawGroup
			m_active->getActive()->enableControl();
			m_hasControl = false;

			return;
		}

		if (TGUI::INPUT::keyPressed(TGUI::KEYBIND::moveLeft) && m_active->getActive()->hasControl())
		{
			// pass control to other drawGroup
			m_active->getActive()->disableControl();
			m_hasControl = true;

			return;
		}

		m_active->getActive()->update();
	}

	// process input only on our current control
	m_active->update();
}

TGUI::POINT TGUI::TGUI_DRAW_GROUP::getDrawPos() {

	// if this is main drawGroup, return position of main drawGroup
	if (m_parent == nullptr)
		return TGUI::POINT(TGUI::OFFSET::menuPosition.x + m_pos.x, TGUI::OFFSET::menuPosition.y + m_pos.y);

	// if this is an element drawGroup then we want to get the position of elements drawGroup
	const auto parentPos = m_parent->getDrawPos();
	return TGUI::POINT(parentPos.x + m_pos.x, parentPos.y + m_pos.y);
}

TGUI::POINT TGUI::TGUI_DRAW_GROUP::getControlPos() {

	if (m_parent == nullptr)
		return TGUI::POINT(TGUI::OFFSET::menuPosition.x + m_pos.x, TGUI::OFFSET::menuPosition.y + m_pos.y - (TGUI::OFFSET::controlSpacing.y * m_scrollStart));

	const auto parentPos = m_parent->getDrawPos();
	return TGUI::POINT(parentPos.x + m_pos.x, parentPos.y + m_pos.y - (TGUI::OFFSET::controlSpacing.y * m_scrollStart));
}

void TGUI::TGUI_DRAW_GROUP::addControl(std::shared_ptr<TGUI::TGUI_CONTROL_BASE> control) {

	control->setParent(shared_from_this());

	if (m_active == nullptr)
		m_active = control;

	control->setPos(m_controlOffset);
	m_children.push_back(control);

	m_controlOffset.y += TGUI::OFFSET::controlSpacing.y;
}
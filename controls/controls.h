#pragma once

#include "../internal/definitions.h"
#include "../internal/wrapper.h"

#include <functional>
#include <vector>

namespace TGUI {

	class TGUI_CONTROL_BASE : 
		public std::enable_shared_from_this<TGUI::TGUI_CONTROL_BASE> {
	public:
		virtual void draw() = 0;
		virtual void update() = 0;

		virtual TGUI::POINT getDrawPos() = 0;
		virtual TGUI::POINT getControlPos() = 0;

		void enableControl();
		void disableControl();
		bool hasControl();

		void setName(const std::string& name);
		std::string getName();

		void setPos(const TGUI::POINT& pos);
		TGUI::POINT getPos();

		void setParent(std::shared_ptr<TGUI::TGUI_CONTROL_BASE> parent);
		std::shared_ptr<TGUI::TGUI_CONTROL_BASE> getParent();

		void setActive(std::shared_ptr<TGUI::TGUI_CONTROL_BASE> active);
		std::shared_ptr<TGUI::TGUI_CONTROL_BASE> getActive();
	protected:
		bool m_hasControl = false;

		std::string m_name = {};
		TGUI::POINT m_pos = {};

		std::vector<std::shared_ptr<TGUI::TGUI_CONTROL_BASE>> m_children = {};

		std::shared_ptr<TGUI::TGUI_CONTROL_BASE> m_parent = NULL;
		std::shared_ptr<TGUI::TGUI_CONTROL_BASE> m_active = NULL;
	};
}
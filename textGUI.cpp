#include "textGUI.h"

namespace testVar {

	static bool testBool1 = false;
	static bool testBool2 = false;
	static bool testBool3 = true;
	static bool testBool4 = false;
	static bool testBool5 = true;
	static bool testBool6 = false;
	static bool testBool7 = true;
	static bool testBool8 = false;

	static int testInt1 = 0;
	static int testInt2 = 2;
	static int testInt3 = 0;
	static int testInt4 = 1;

	const TGUI::BOOL_CONTROL_TEXT boolText = {

		TGUI::TGUI_CONTROL_TEXT("False", TGUI::COLOURS::white),
		TGUI::TGUI_CONTROL_TEXT("True", TGUI::COLOURS::green)
	};

	const TGUI::INT_CONTROL_TEXT intText = {

		TGUI::TGUI_CONTROL_TEXT("1", TGUI::COLOURS::white),
		TGUI::TGUI_CONTROL_TEXT("2", TGUI::COLOURS::yellow),
		TGUI::TGUI_CONTROL_TEXT("3", TGUI::COLOURS::green),
		TGUI::TGUI_CONTROL_TEXT("4", TGUI::COLOURS::blue)
	};
}

void c_textGUI::createGUI() {
	
	TGUI::RENDER::controlFont = TGUI::RENDER::createFont("Tahoma", 14, 750, true);

	m_title = "Text GUI Demo";
	m_mainDrawGroup = std::make_shared<TGUI::TGUI_DRAW_GROUP>(TGUI::POINT(30, 20)); {

		const auto boolControl1 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 1", &testVar::testBool1, testVar::boolText);
		const auto boolControl2 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 2", &testVar::testBool2, testVar::boolText); {

			const auto drawGroup2 = std::make_shared<TGUI::TGUI_DRAW_GROUP>(TGUI::OFFSET::drawGroupSpacing); {

				const auto boolControl3 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 3", &testVar::testBool3, testVar::boolText);
				const auto boolControl4 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 4", &testVar::testBool4, testVar::boolText); {

					const auto drawGroup3 = std::make_shared<TGUI::TGUI_DRAW_GROUP>(TGUI::OFFSET::drawGroupSpacing); {

						const auto intControl1 = std::make_shared<TGUI::TGUI_INT_CONTROL>("Int 1", &testVar::testInt1, testVar::intText);
						const auto intControl2 = std::make_shared<TGUI::TGUI_INT_CONTROL>("Int 2", &testVar::testInt2, testVar::intText);

						drawGroup3->addControl(intControl1);
						drawGroup3->addControl(intControl2);
					}

					boolControl4->addDrawGroup(drawGroup3);
				}

				drawGroup2->addControl(boolControl3);
				drawGroup2->addControl(boolControl4);
			}

			boolControl2->addDrawGroup(drawGroup2);
		}

		m_mainDrawGroup->addControl(boolControl1);
		m_mainDrawGroup->addControl(boolControl2);

		const auto intControl1 = std::make_shared<TGUI::TGUI_INT_CONTROL>("Int 3", &testVar::testInt3, testVar::intText);
		const auto intControl2 = std::make_shared<TGUI::TGUI_INT_CONTROL>("Int 4", &testVar::testInt4, testVar::intText);

		const auto boolControl5 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 5", &testVar::testBool5, testVar::boolText);
		const auto boolControl6 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 6", &testVar::testBool6, testVar::boolText);
		const auto boolControl7 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 7", &testVar::testBool7, testVar::boolText);
		const auto boolControl8 = std::make_shared<TGUI::TGUI_BOOL_CONTROL>("Bool 8", &testVar::testBool8, testVar::boolText);

		m_mainDrawGroup->addControl(intControl1);
		m_mainDrawGroup->addControl(intControl2);

		m_mainDrawGroup->addControl(boolControl5);
		m_mainDrawGroup->addControl(boolControl6);
		m_mainDrawGroup->addControl(boolControl7);
		m_mainDrawGroup->addControl(boolControl8);
	}
}

void c_textGUI::destroyGUI() {
	
}

void c_textGUI::drawGUI() {

	// draw menu bar thingy
	{
		TGUI::RENDER::drawString(TGUI::OFFSET::menuPosition.x, TGUI::OFFSET::menuPosition.y, TGUI::RENDER::controlFont, TGUI::COLOURS::white, "[  ]");
		TGUI::RENDER::drawString(TGUI::OFFSET::menuPosition.x + 25, TGUI::OFFSET::menuPosition.y, TGUI::RENDER::controlFont, TGUI::COLOURS::white, m_title);

		if (m_isOpen) {

			TGUI::RENDER::drawRectFilled(TGUI::OFFSET::menuPosition.x + 7, TGUI::OFFSET::menuPosition.y + 5, 2, 6, TGUI::COLOURS::green);
			TGUI::RENDER::drawRect(TGUI::OFFSET::menuPosition.x + 7, TGUI::OFFSET::menuPosition.y + 5, 2, 6, TGUI::COLOURS::black);

		}
		else {

			TGUI::RENDER::drawRectFilled(TGUI::OFFSET::menuPosition.x + 5, TGUI::OFFSET::menuPosition.y + 7, 6, 2, TGUI::COLOURS::white);
			TGUI::RENDER::drawRect(TGUI::OFFSET::menuPosition.x + 5, TGUI::OFFSET::menuPosition.y + 7, 6, 2, TGUI::COLOURS::black);
		}
	}

	if (m_isOpen)
		m_mainDrawGroup->draw();
}

void c_textGUI::updateGUI() {

	if (TGUI::INPUT::keyPressed(TGUI::KEYBIND::menuOpen))
		m_isOpen = !m_isOpen;

	if (m_isOpen)
		m_mainDrawGroup->update();
}
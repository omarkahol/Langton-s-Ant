/*
 * Ant.cpp
 *
 *  Created on: Sep 9, 2018
 *      Author: omykhron
 */

#include "Ant.h"
#include <iostream>

void Ant::move() {
	for (int i = 0; i < 20; i++) {
		if (m_screen.getPixel(m_headX, m_headY)
				== m_screen.getColor(255, 255, 255)) {

			m_screen.setPixel(m_headX, m_headY, 0, 0, 0);

			this->currentDir += 1;
			this->currentDir %= 4;
			this->moveForeward();

		} else if (m_screen.getPixel(m_headX, m_headY)
				== m_screen.getColor(0, 0, 0)) {

			m_screen.setPixel(m_headX, m_headY, 255, 255, 255);

			this->currentDir -= 1;
			this->currentDir %= 4;
			this->moveForeward();

		} else {
			this->m_headX=Screen::SCREEN_WIDTH/2;
			this->m_headY=Screen::SCREEN_HEIGHT/2;
		}
	}
}


void Ant::moveForeward() {
	switch (this->currentDir) {
	case 0:
		this->m_headY -=  1;
		break;
	case 1:
		this->m_headX +=  1;
		break;
	case 2:
		this->m_headY += 1;
		break;
	case 3:
		this->m_headX -= 1;

		break;
	default:
		this->currentDir += 4;
		moveForeward();
	}

}


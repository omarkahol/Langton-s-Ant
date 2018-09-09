/*
 * Ant.h
 *
 *  Created on: Sep 9, 2018
 *      Author: omykhron
 */

#ifndef ANT_H_
#define ANT_H_

#include "Screen.h"
using namespace std;

class Ant {
private:
	int m_headX;
	int m_headY;
	void moveForeward();
	void switchMultiplier();
	Screen& m_screen;
	int currentDir;
public:
	Ant(Screen& screen) :
			m_screen(screen), m_headX(Screen::SCREEN_WIDTH / 2), m_headY(
					Screen::SCREEN_HEIGHT / 2), currentDir(0){
	}
	;
	~Ant() {
	}
	;
	void move();
};

#endif /* ANT_H_ */

#include <iostream>
#include "Screen.h"
#include "Ant.h"
using namespace std;

int main() {
	Screen screen;
	Ant ant(screen);

	while (true) {
		screen.update();
		ant.move();


		if(screen.processEvents()==false) {
			break;
		}
	}

	return 0;
}

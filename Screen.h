/*
 * Screen.h
 *
 *  Created on: Sep 3, 2018
 *      Author: omykhron
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>


using namespace std;

class Screen {

public:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Uint32* m_buffer1;

private:
	bool init();
	void close();
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
	Screen();
	void update();
	Uint32 getPixel(int x, int y);
	bool processEvents();
	void setPixel(int x, int y, Uint32 red, Uint32 green, Uint32 blue);
	virtual ~Screen();
	Uint32 getColor(Uint32 red, Uint32 green,Uint32 blue);
};

#endif /* SCREEN_H_ */

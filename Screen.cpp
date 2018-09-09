/*
 * Screen.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: omykhron
 */

#include "Screen.h"
#include <exception>

using namespace std;

Screen::Screen() { // @suppress("Class members should be properly initialized")
	if (this->init()) {
		return;
	} else {
		throw 1;
	}
}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}
	this->m_window = SDL_CreateWindow("LANGTON'S ANT",
	SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (this->m_window == NULL) {
		SDL_Quit();
		return false;
	}
	this->m_renderer = SDL_CreateRenderer(this->m_window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	this->m_texture = SDL_CreateTexture(this->m_renderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
			SCREEN_HEIGHT);

	if (this->m_renderer == NULL || this->m_texture == NULL) {
		SDL_DestroyWindow(this->m_window);
		SDL_DestroyRenderer(this->m_renderer);
		SDL_DestroyTexture(this->m_texture);
		SDL_Quit();
		return false;
	}

	this->m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(this->m_buffer1, 255,
				this->SCREEN_HEIGHT * this->SCREEN_WIDTH * sizeof(Uint32));

	return true;
}

void Screen::close() {
	delete[] m_buffer1;

	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Screen::update() {
	SDL_UpdateTexture(this->m_texture, NULL, this->m_buffer1,
			SCREEN_WIDTH * sizeof(int));
	SDL_RenderClear(this->m_renderer);
	SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, NULL);
	SDL_RenderPresent(this->m_renderer);
}


bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) == true) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

Uint32 Screen::getColor(Uint32 red, Uint32 green,Uint32 blue){
	Uint32 color = 0;
			color += red;
			color <<= 8;
			color += green;
			color <<= 8;
			color += blue;
			color <<= 8;
			color += 0xff;
			return color;
}

void Screen::setPixel(int x, int y, Uint32 red, Uint32 green, Uint32 blue) {



		if (x < 0 || x > SCREEN_WIDTH || y < 0 || y > SCREEN_HEIGHT) {
			return;
		}

		Uint32 color = 0;
		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xff;
		m_buffer1[(y * SCREEN_WIDTH) + x] = color;
}
Uint32 Screen::getPixel(int x, int y) {
	return m_buffer1[(y * SCREEN_WIDTH) + x];
}

Screen::~Screen() {
	this->close();
}


#include "Game.hpp"

#define WINDOW_HEIGHT 480
#define WINDOW_WIDTH 640

Game::Game():
	width(WINDOW_WIDTH),
	height(WINDOW_HEIGHT),
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bouncing Balls")
{
	for (int i = 0; i < 100; i++) {
		this->balls.push_back( Ball(this) );
	}
}

int Game::getWidth() {
	return this->width;
}

int Game::getHeight() {
	return this->height;
}

void Game::initialize()
{
	window.setFramerateLimit(60);

	while ( window.isOpen() ) {
		sf::Event event;

		while ( window.pollEvent(event) ) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear( sf::Color::White );

		for (auto i = this->balls.begin(); i != this->balls.end(); i++) {
			i->update();
			window.draw(*i);
		}

		window.display();
	}
}
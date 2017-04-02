#pragma once
#include <SFML/Graphics.hpp>
#include "Manager.hpp"
#include "Ball.hpp"
#include <vector>

class Game: public Manager
{
public:
	Game(void);
	void initialize(void);
	int getWidth();
	int getHeight();
private:
	int height, width;
	std::vector<Ball> balls;
	sf::RenderWindow window;
};
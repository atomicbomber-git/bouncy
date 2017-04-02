#pragma once
#include <SFML/Graphics.hpp>
#include "Manager.hpp"

class Ball: public sf::Drawable
{
public:
	Ball(Manager*);
	float vx, vy;
	void update(void);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::CircleShape *image;
	Manager *manager;
};
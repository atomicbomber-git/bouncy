#include "Ball.hpp"

Ball::Ball(Manager *manager):
	manager(manager)
{
	this->vx = (std::rand() % 1000) / 100.0;
	this->vy = (std::rand() % 1000) / 100.0;

	this->image = new sf::CircleShape((std::rand() % 5) + 10);
	this->image->setFillColor(sf::Color( std::rand() % 256 , std::rand() % 256 , std::rand() % 256));
}

void Ball::update(void)
{
	sf::Vector2f old_pos = this->image->getPosition();

	if (old_pos.x < 0 || old_pos.x > this->manager->getWidth()) {
		this->vx *= -1;

		if (old_pos.x < 0) {
			old_pos.x = 0;
		}
		else if (old_pos.x > this->manager->getWidth()) {
			old_pos.x = this->manager->getWidth();
		}

	}

	if (old_pos.y < 0 || old_pos.y > this->manager->getHeight()) {
		this->vy *= -1;

		if (old_pos.y < 0) {
			old_pos.y = 0;
		}
		else if (old_pos.y > this->manager->getHeight()) {
			old_pos.y = this->manager->getHeight();
		}

	}

	float new_x = old_pos.x + this->vx;
	float new_y = old_pos.y + this->vy;

	sf::Vector2f new_pos(new_x, new_y);

	this->image->setPosition(new_pos);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*this->image);
}
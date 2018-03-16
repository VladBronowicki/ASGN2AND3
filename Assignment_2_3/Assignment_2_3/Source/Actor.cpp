#include "..\Include\Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}

void Actor::setVelocity(float x, float y)
{
	_velocity.x = x;
	_velocity.y = y;
}

sf::Vector2f Actor::getVelocity() const
{
	return sf::Vector2f();
}

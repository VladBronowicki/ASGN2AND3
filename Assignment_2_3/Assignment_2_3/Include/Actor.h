#pragma once

#include "SceneNode.h"

class Actor : public SceneNode
{

private:
	sf::Vector2f _velocity;


public:
	Actor();
	~Actor();

	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float x, float y);
	sf::Vector2f getVelocity() const;



};


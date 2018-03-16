#pragma once

#include "Actor.h"
#include "ResourceDefinition.h"

#include <SFML/Graphics/Sprite.hpp>

class Character : public Actor
{
private:
	sf::Sprite _sprite;
	Textures::ID _type;

public:
	Character(TextureContainer& tc, Textures::ID type);

private:
	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;
};
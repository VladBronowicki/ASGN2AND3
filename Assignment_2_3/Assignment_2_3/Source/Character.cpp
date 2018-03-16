#include "Character.h"
#include "ResourceContainer.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Character::Character(TextureContainer& tc, Textures::ID type) :
	_sprite(tc.get(type)),
	_type(type)
{
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Character::drawSelf(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

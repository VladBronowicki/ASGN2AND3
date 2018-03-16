#pragma once

#include "SceneNode.h"
#include "ResourceContainer.h"
#include "ResourceDefinition.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sf
{
	class RenderWindow;
}

class Scene : private sf::NonCopyable
{
public:
	explicit Scene(sf::RenderWindow& window);
	~Scene();

	void update(sf::Time dt);
	void draw();
};

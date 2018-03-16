#pragma once

namespace sf {
	class Texture;
}

namespace Textures {
	enum ID {
		NONE,
		BACKGROUND,
		REDGUY,
		BLUEGUY
	};
}

template <typename identifier, typename resource>
class ResourceContainer;

typedef ResourceContainer<Textures::ID, sf::Texture> TextureContainer;
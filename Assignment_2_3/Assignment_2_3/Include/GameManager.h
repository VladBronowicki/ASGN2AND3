#pragma once

#include <SFML\Graphics.hpp>

#include "Scene.h"

class GameManager
{

private://private members
	static const float _playerSpeed;
	static const sf::Time _timePerFrame;

	Scene _gameScene;

	sf::RenderWindow _window;
	sf::Texture _texture;
	sf::Font _font;
	sf::Text _statisticText;
	sf::Time _statisticUpdateTime;
	std::size_t _statisticNumFrames;

public://public methods
	GameManager();
	~GameManager();

	void run();

private://private methods
	void eventUpdate();
	void gameUpdate(sf::Time elapsed);
	void renderUpdate();
	void statisticUpdate(sf::Time elapsed);
	void handleInput();

};


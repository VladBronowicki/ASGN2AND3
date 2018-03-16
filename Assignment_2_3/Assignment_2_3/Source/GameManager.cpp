#include "GameManager.h"
#include "StringHelper.h"

const float GameManager::_playerSpeed = 5.0f;
const sf::Time GameManager::_timePerFrame = sf::seconds(1.f / 120.f);

GameManager::GameManager() :
	_window(sf::VideoMode(1600, 9000), "Assignment 2 & 3", sf::Style::Close),
	_gameScene(_window),
	_font(),
	_statisticText(),
	_statisticUpdateTime(),
	_statisticNumFrames(0)
{
	_font.loadFromFile("Media/Sansation.tff");
	_statisticText.setFont(_font);
	_statisticText.setPosition(5.f, 5.f);
	_statisticText.setCharacterSize(10);
}


GameManager::~GameManager()
{
}

void GameManager::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (_window.isOpen()) {
		sf::Time elapsed = clock.restart();
		timeSinceLastUpdate += elapsed;
		while (timeSinceLastUpdate > _timePerFrame)
		{
			timeSinceLastUpdate -= _timePerFrame;

			eventUpdate();
			gameUpdate(elapsed);

		}

		statisticUpdate(elapsed);
		renderUpdate();
	}
}

void GameManager::eventUpdate()
{

	//TODO: ADD IMPLEMENTATION

}

void GameManager::gameUpdate(sf::Time elapsed)
{
	_gameScene.update(elapsed);
}

void GameManager::renderUpdate()
{
	_window.clear();
	_gameScene.draw();
	_window.setView(_window.getDefaultView());
	_window.draw(_statisticText);

	_window.display();

}

void GameManager::statisticUpdate(sf::Time elapsed)
{
	_statisticText.setString("FPS: " + toString(_statisticNumFrames) + "\n" + 
		"Time per update: " + toString(_statisticUpdateTime.asMicroseconds() / _statisticNumFrames) + "us");
	_statisticUpdateTime -= sf::seconds(1.0f);
	_statisticNumFrames = 0;
}

void GameManager::handleInput()
{

	//TODO: IMPLEMENTATION

}

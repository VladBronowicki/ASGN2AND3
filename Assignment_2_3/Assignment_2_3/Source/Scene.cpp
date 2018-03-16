#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>

Scene::Scene(sf::RenderWindow& window) : 
	_window(window),
	_sceneView(window.getDefaultView()),
	_textures(),
	_sceneGraph(),
	_sceneBounds(0.f,0.f, _sceneView.getSize().x, 2000.f)
{
	loadTextures();
	buildScene();
}

Scene::~Scene()
{
}

void Scene::update(sf::Time dt)
{
	_sceneGraph.update(dt);
}

void Scene::draw()
{
	_window.setView(_sceneView);
	_window.draw(_sceneGraph);
}

void Scene::loadTextures()
{
	_textures.load(Textures::BLUEGUY, "Filename");
}

void Scene::buildScene()
{
}

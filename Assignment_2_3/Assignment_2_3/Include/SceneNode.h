#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>


#include <vector>
#include <memory>

class SceneNode : sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public://type definitions
	typedef std::unique_ptr<SceneNode> ptr;

private: //private members
	std::vector<ptr> _children;
	SceneNode* _parent;
	int _zIndex = 0;

public:// public methods
	SceneNode();
	~SceneNode();

	void attach(ptr child);
	ptr detach(const SceneNode& node);

	void update(sf::Time dt);

	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;

	int getZIndex();
	void setZIndex(int z);

private: //private methods
	virtual void updateSelf(sf::Time dt);
	void updateChildren(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawSelf(sf::RenderTarget& target, sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

};


#include "SceneNode.h"
#include "Foreach.h"

#include <algorithm>
#include <cassert>

SceneNode::SceneNode() :
	_children(),
	_parent(nullptr)
{
}


SceneNode::~SceneNode()
{
}

void SceneNode::attach(ptr child)
{
	child->_parent = this;
	_children.push_back(std::move(child));
}

SceneNode::ptr SceneNode::detach(const SceneNode & node)
{
	auto found = std::find_if(_children.begin(), _children.end(),
		[&](ptr& p) {
		return p.get() == &node;
	});
	ptr result = std::move(*found);
	result->_parent = nullptr;
	_children.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateSelf(dt);
	updateChildren(dt);
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node->_parent) {
		transform = node->getTransform() * transform;
	}
	return transform;
}

void SceneNode::updateSelf(sf::Time dt)
{
	//TODO: Add implementation
}

void SceneNode::updateChildren(sf::Time dt)
{
	FOREACH(ptr& child, _children)
		child->update(dt);
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	drawSelf(target, states);
	drawChildren(target, states);
}

void SceneNode::drawSelf(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	FOREACH(const ptr& child, _children) {
		child->draw(target, states);
	}
}


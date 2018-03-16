#pragma once

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename identifier, typename resource>
class ResourceContainer
{
public:

	void load(identifier id, const std::string& filename);

	template <typename parameter>
	void load(identifier id, const std::string& filename, const parameter& param);

	resource& get(identifier id);
	const resource& get(identifier id) const;

private:
	void insert(identifier id, std::unique_ptr<resource> res);
	std::map<identifier, std::unique_ptr<resource>> _resourceMap;
};

#include "ResourceContainer.inl"
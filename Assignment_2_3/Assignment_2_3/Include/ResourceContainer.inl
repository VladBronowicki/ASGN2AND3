template<typename identifier, typename resource>
inline void ResourceContainer<identifier, resource>::load(identifier id, const std::string & filename)
{
	std::unique_ptr<resource> res(new resource());
	if (!res->loadFromFile(filename)) {
		throw std::runtime_error("ReserouceContainer::load faild to load " + filename);
	}
	insert(id, std::move(res));
}

template<typename identifier, typename resource>
template<typename parameter>
inline void ResourceContainer<identifier, resource>::load(identifier id, const std::string & filename, const parameter & param)
{
	std::unique_ptr<resource> res(new Resource());
	if (!resource->loadFromFile(filename, param))
		throw std::runtime_error("ReserouceContainer::load faild to load " + filename);
	insert(id, std::move(res));
}

template<typename identifier, typename resource>
inline resource & ResourceContainer<identifier, resource>::get(identifier id)
{
	auto found = _resourceMap.find(id);
	assert(found != _resourceMap.end());

	return *found->second;
}

template<typename identifier, typename resource>
inline const resource & ResourceContainer<identifier, resource>::get(identifier id) const
{
	// TODO: insert return statement here	auto found = _resourceMap.find(id);
	assert(found != _respourceMap.end());

	return *found->second;
}

template<typename identifier, typename resource>
inline void ResourceContainer<identifier, resource>::insert(identifier id, std::unique_ptr<resource> res)
{
	auto inserted = _resourceMap.insert(std::make_pair(id, std::move(res)));
	assert(inserted.second);
}
#pragma once
#include <string>

class Scene
{
public:
	Scene(std::string name);
	std::string name;

	virtual void handleInput();
	virtual void update();
	virtual void render();
};


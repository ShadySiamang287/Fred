#include "Scene.h"
#include <iostream>

Scene::Scene(std::string name)
{
	this->name = name;
}

void Scene::handleInput()
{
}

void Scene::update()
{
	std::cout << name << std::endl;
}

void Scene::render()
{
}

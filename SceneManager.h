#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Scene.h"

class SceneManager
{
public:
	static std::shared_ptr<SceneManager> getInstance();

	void configure(int tableSize);

	struct Entry {
		std::string key;
		std::shared_ptr<Scene> value;
		int probeDistance;
		bool occupied;
	};

	std::shared_ptr<Scene> getCurrentScene();
	
	void addScene(std::shared_ptr<Scene> scene);
	void setCurrentScene(std::string name);

private:
	SceneManager();
	std::shared_ptr<Scene> currentScene;

	int hashFunction(std::string key);
	void rehash();

	void insert(std::string key, std::shared_ptr<Scene> value);

	std::vector<Entry> table;
	int capacity;
	int size;

	float MAX_LOAD;

	static SceneManager* instance_;
};


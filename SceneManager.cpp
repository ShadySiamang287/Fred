#include "SceneManager.h"

std::shared_ptr<SceneManager> SceneManager::getInstance()
{
    if (instance_ == nullptr) {
        instance_ = new SceneManager();
    }
    return std::shared_ptr<SceneManager>(instance_);
}

void SceneManager::configure(int tableSize)
{
    capacity = tableSize;
    size = 0;
    table.resize(tableSize);
    MAX_LOAD = 0.9;
}

std::shared_ptr<Scene> SceneManager::getCurrentScene()
{
    return currentScene;
}

void SceneManager::addScene(std::shared_ptr<Scene> scene)
{
    insert(scene->name, scene);
}

void SceneManager::setCurrentScene(std::string name)
{
    int hash = hashFunction(name);
    int index = hash % capacity;
    int probeDistance = 0;

    while (table[index].occupied) {
        // If probe distance of current entry is less than how far we've probed, key cannot be in table
        if (table[index].probeDistance < probeDistance) {
            break; // key not found
        }

        if (table[index].key == name) {
            currentScene = table[index].value; // key found
        }

        // Move to next slot
        index = (index + 1) % capacity;
        probeDistance++;
    }
    currentScene = table[hashFunction(name)].value;
}

SceneManager::SceneManager()
{
    capacity = 10;
    size = 0;
    table.resize(10);
    MAX_LOAD = 0.9;
}

int SceneManager::hashFunction(std::string key)
{
    int total = 0;
    for (int i = 0; i < key.size(); i++) {
        total += static_cast<int>(key[i]);
    }
    return total % capacity;
}

void SceneManager::rehash() {
    std::vector<Entry> oldTable = table;    // temp reference tidied up at function end
    capacity *= 2;
    table.clear();
    table.resize(capacity);
    size = 0;

    for (const Entry& entry : oldTable) {
        if (entry.occupied) {
            insert(entry.key, entry.value);
        }
    }
}

void SceneManager::insert(std::string key, std::shared_ptr<Scene> value)
{
    // first, check if we must rehash
    if ((static_cast<float>(size + 1) / capacity) >= MAX_LOAD) {
        rehash();
    }

    // generate entry, our count for steps and the first position we will consider
    int pos = hashFunction(key);
    int steps = 1;
    Entry to_place = Entry();
    to_place.key = key;
    to_place.occupied = true;
    to_place.value = value;
    to_place.probeDistance = 0;

    // while the position is occupied
    while (table[pos].occupied) {
        // duplicate key
        if (table[pos].key == key) {
            table[pos].value = value;
        }
        if (to_place.probeDistance > table[pos].probeDistance) {
            std::swap(to_place, table[pos]);
        }

        pos += 1;
        if (pos >= capacity) {
            pos = 0;
        }
        to_place.probeDistance += 1;
        steps += 1;
    }
    // swap elements if needed
    // iterate around the structure

// should have a free space down here, so insert
    table[pos] = to_place;
    size += 1;
}
SceneManager* SceneManager::instance_ = nullptr;

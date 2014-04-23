#pragma once

#include <map>
#include "layers_scenes_transitions_nodes/CCLayer.h"

enum SceneKey
{
	NONE = 0,
	MAIN_MENU_SCENE,
	GAME_SCENE
};

class SceneManager
{
public:
	static SceneManager* GetInstance();


private:

	static SceneManager* instance;

	std::map<SceneKey,cocos2d::CCLayer> scenes;

	SceneManager();
	SceneManager(const SceneManager&);
	~SceneManager();
};
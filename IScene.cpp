#include "IScene.h"

//タイトルシーンで初期化
int IScene::SceneNo = TITLE;

IScene::~IScene()
{
}

int IScene::GetSceneNo()
{
	return SceneNo;
}

void IScene::SetKeys(char* keys, char* preKeys)
{
	keys_ = keys;
	preKeys_ = preKeys;
}



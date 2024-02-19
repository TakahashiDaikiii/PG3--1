#pragma once

#include <memory>
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

class GameManeger
{
public:

	GameManeger(); //コンストラクタ
	~GameManeger(); //デストラクタ

	/// <summary>
	/// ゲームループ処理
	/// </summary>
	/// <returns></returns>
	int Run();

private:
	 //シーンを保持するメンバー変数
	std::unique_ptr<IScene> sceneArr_[4];

	//どのステージを呼び出すかを管理する関数
	int currentSceneNo_; //現在のシーン
	int precSceneNo_; //前のシーン

	// キー入力結果を受け取る箱
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };


};


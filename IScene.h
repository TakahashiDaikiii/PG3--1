#pragma once

enum Scene { TITLE, STAGE, CLEAR, SCENEMAX };


class IScene
{
protected:
	// シーン番号を管理する変数
	static int SceneNo;

	// キー入力結果を受け取る箱
	char* keys_;
	char* preKeys_;

public:

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual void Draw() = 0;

	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();

	/// <summary>
	/// キー入力
	/// </summary>
	void SetKeys(char* keys, char* preKeys);

};


#pragma once
#include "IScene.h"
#include "Vector2.h"


class StageScene :public IScene
{
public:
	void Init() override;

	void Update() override;

	void Draw() override;

	void Rset();

private:

	Vector2 player;

	Vector2 enemy;

	Vector2 bullet;

	Vector2 moveE;

	Vector2 moveP;

	const float radius = 16;


};


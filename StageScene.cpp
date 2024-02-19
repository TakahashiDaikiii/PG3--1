#include "StageScene.h"
#include "Novice.h" 
#include "Vector2.h"


void StageScene::Init()
{
	player = { 640,320 };

	enemy = { 0,8 };

	bullet = { 0,-10 };

	moveE = { 3,3 };

	moveP = { 3,3 };

}

void StageScene::Update()
{

	moveP = { 0,0 };
	enemy.x += moveE.x;

	if (enemy.x <= 0) {
		moveE.x += 3;
	}

	if (enemy.x >= 1280) {
		moveE.x -= 3;
	}

	if (keys_[DIK_A]) {
		moveP.x = -3;
	}
	else if (keys_[DIK_D]) {
		moveP.x = 3;
	}

	if (keys_[DIK_W]) {
		moveP.y = -3;
	}
	else if (keys_[DIK_S]) {
		moveP.y = 3;
	}

	if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0) {
		bullet = player;
	}

	float collision = (enemy.x - bullet.x) * (enemy.x - bullet.x) + (enemy.y - bullet.y) * (enemy.y - bullet.y);

	float r = (radius + radius) * (radius + radius);

	if (r >= collision && bullet.y >= 0) {
		SceneNo = CLEAR;
		Rset();
	}


	player.x += moveP.x;
	player.y += moveP.y;

	bullet.y--;

}

void StageScene::Draw()
{
	Novice::DrawEllipse((int)enemy.x, (int)enemy.y, (int)radius, (int)radius, 0.0f, RED, kFillModeSolid);

	Novice::DrawEllipse((int)bullet.x, (int)bullet.y, (int)radius, (int)radius, 0.0f, BLUE, kFillModeSolid);

	Novice::DrawEllipse((int)player.x, (int)player.y, (int)radius, (int)radius, 0.0f, WHITE, kFillModeSolid);


}

void StageScene::Rset()
{
	player = { 640,320 };

	enemy = { 0,8 };

	bullet = { 0,-10 };

}

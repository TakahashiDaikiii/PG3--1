#include <Novice.h>
#include "InputHandler.h"
#include "Player.h"

const char kWindowTitle[] = "LE2C_13_タカハシ_ダイキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	InputHandler* inputHandler = new InputHandler();
	inputHandler->AssignMoveLeftCommand2PreessKeyA();
	inputHandler->AssignMoveRightCommand2PreessKeyD();

	ICommand* command_ = nullptr;
	Player* player_ = new Player();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		//input->Update();
		///
		/// ↓更新処理ここから
		///

		command_ = inputHandler->HandleInput();

		if (command_) {
			command_->Exec(*player_);
		}


		player_->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player_->Draw();

		///
		/// ↑描画処理ここまで
		///

	// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}


/*GameManeger* gameManeger_ = new GameManeger();
gameManeger_->Run();*/
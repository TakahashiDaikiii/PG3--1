#include "InputHandler.h"
#include "Novice.h"

ICommand* InputHandler::HandleInput()
{

	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}

	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}

	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PreessKeyA()
{
	ICommand* commnad = new LeftCommand();
	pressKeyA_ = commnad;
}

void InputHandler::AssignMoveRightCommand2PreessKeyD()
{
	ICommand* commnad = new RightCommand();
	pressKeyD_ = commnad;
}
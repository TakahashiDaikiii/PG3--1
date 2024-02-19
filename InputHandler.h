#pragma once
#include "ICommand.h"
class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PreessKeyA();
	void AssignMoveRightCommand2PreessKeyD();

private:
	ICommand* pressKeyA_;
	ICommand* pressKeyD_;

};
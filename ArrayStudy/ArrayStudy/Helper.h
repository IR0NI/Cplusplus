#pragma once

enum MoveDir
{
	MD_NONE,
	MD_LEFT,
	MD_RIGHT,
	MD_UP,
	MD_DOWN
};

void HandleKeyInput();
void HandleMove();
void SetCursorPosition(int x, int y);
void SerCursorOnOff(bool visible);

extern MoveDir GMoveDir;


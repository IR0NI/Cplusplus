#include <iostream>
using namespace std;
#include "Helper.h"
#include "Map.h"
#include "Player.h"
#include <Windows.h>



int main() 
{
	SerCursorOnOff(false);

	//MovePlayer(3, 2);
	while (true)
	{
		// �Է�
		HandleKeyInput();

		// ����
		HandleMove();

		// ���
		PrintMap1D();
	}
}


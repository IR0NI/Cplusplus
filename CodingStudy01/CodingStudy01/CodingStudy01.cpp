// CodingStudy01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Gobline = 3
};

PlayerType playertype;
int hp;
int attack;
int armor;

MonsterType monstertype;
int monsterhp;
int monsterattack;
int monsterarmor;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();

int main()
{
	srand(time(0));
	EnterLobby();

}

void EnterLobby() 
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "      로비에 입장      " << endl;
		cout << "---------------------" << endl;
		//플레이어 직업선택
		SelectPlayer();

		cout << "---------------------" << endl;
		cout << "1.필드 입장 2.게임 종료" << endl;
		cout << "---------------------" << endl;

		int input;
		cin >> input;
		if (input == 1) {
			EnterField();
		}
		else {
			return;
		}
	}
	
}

void SelectPlayer() 
{
	while (true)
	{
		cout << "      직업을 선택      " << endl;
		cout << "1.전사 2.궁수 3.마법사" << endl;
		cout << ">";

		int choice;
		cin >> choice;

		if (choice == PT_Knight) {
			cout << "기사 생성중" << endl;
			hp = 150;
			attack = 10;
			armor = 5;
			playertype = PT_Knight;
			break;
		}
		else if (choice == PT_Archer) {
			cout << "궁수 생성중" << endl;
			hp = 100;
			attack = 15;
			armor = 5;
			playertype = PT_Archer;
			break;
		}
		else if (choice == PT_Mage)
		{
			cout << "마법사 생성중" << endl;
			hp = 80;
			attack = 20;
			armor = 3;
			playertype = PT_Mage;
			break;
		}
	}
}

void EnterField() 
{
	while (true)
	{
		cout << "---------------------" << endl;
		cout << "필드에 입장" << endl;
		cout << "---------------------" << endl;

		cout << "체력 : " << hp << " 공격력 : " << attack << " 방어력 : " << armor << endl;
		CreateRandomMonster();
		cout << "---------------------" << endl;
		cout << "1.전투 2.퇴각" << endl;
		cout << ">";
		int input;
		cin >> input;
		if (input == 1)
		{
			EnterBattle();
			if (hp == 0)
				WaitForNextKey();
				return;
		}
		else
		{
			return;
		}
	}
	
}

void CreateRandomMonster()
{
	int Randomchoice = 1+ (rand() % 3);

	switch (Randomchoice)
	{
	case MT_Slime:
		cout << "슬라임 생성중 / 체력 : 30 / 공격력 : 2 / 방어력 : 0" << endl;
		monsterhp = 30;
		monsterattack = 2;
		monsterarmor = 0;
		monstertype = MT_Slime;
		break;
	case MT_Orc:
		cout << "오크 생성중 / 체력 : 40 / 공격력 : 10 / 방어력 : 3" << endl;
		monsterhp = 40;
		monsterattack = 10;
		monsterarmor = 3;
		monstertype = MT_Orc;
		break;
	case MT_Gobline:
		cout << "고블린 생성중 / 체력 : 30 / 공격력 : 5 / 방어력 : 0" << endl;
		monsterhp = 30;
		monsterattack = 5;
		monsterarmor = 0;
		monstertype = MT_Gobline;
		break;
	default:
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = attack - monsterarmor;
		if (monsterarmor > attack)
			damage = 0;

		//선빵
		monsterhp -= damage;
		if (monsterhp < 0)
			monsterhp = 0;

		cout << "몬스터의 남은체력" << monsterhp << endl;

		if (monsterhp == 0) 
		{
			cout << "몬스터 처치" << endl;
			WaitForNextKey();
			return;
		}
		//몬스터 공격
		damage = monsterattack - armor;
		if (damage < 0)
			damage = 0;
		hp -= damage;
		if (hp < 0)
			hp = 0;
		cout << "당신의 남은 체력 : " << hp << endl;

		if (hp == 0)
		{
			cout << "GameOver" << endl;
			return;
		}
	}
}

void WaitForNextKey()
{
	cout << "다시시작하려면 1입력" << endl;
	cout << "<";

	int input;
	cin >> input;

	system("cls");
}


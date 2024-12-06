#ifndef Scorpion_h
#define Scorpion_h

#include "Interface.h"
#include "Player.h"

typedef struct RadScorpion
{
	//����
	int Accuracy; // �⺻�� = 45 +(5��); �������� 95��
	//������
	int HP; // �⺻�� = 30 (+4��); ���� �������� 4�� ����
	//��ø
	int AP; //�⺻�� = 1 (+1)��
	//��
	int Luck; //�⺻�� = 10 (+2��) 10 ~
	//����ġ
	Item inventory;
}Scorpion;

void scorpion_default(Scorpion* a, Player* b)
{
	a->Accuracy = 50;
	a->HP = 30;
	a->Luck = 5; 
	a->AP = 4;
	//�÷��̾��� � ���� ������ Ȯ�� �ٸ���.
	int playerluck = b->SPECIAL[6];
	switch (playerluck)
	{
	case 1:
	case 2:
	case 3:
		a->inventory.Ammo = rand() % 5 + 1; // 1~5
		a->inventory.Stimpack = rand() % 1; // 0~ 1
		break;
	case 4:
	case 5:
	case 6:
		a->inventory.Ammo = rand() % 5 + 6; //5~10
		a->inventory.Stimpack = rand() % 1 + 1; // 1 ~ 2
		break;
	case 7:
	case 8:
	case 9:
		a->inventory.Ammo = rand() % 5 + 11; //10 ~ 15
		a->inventory.Stimpack = rand() % 1 + 2; //2~3
		break;
	case 10:
		a->inventory.Ammo = rand() % 5 + 15; //15~20
		a->inventory.Stimpack = rand() % 1 + 3; //3 ~ 4
		break;
	}
}
void Scorpion_put(int x, int y)
{
	gotoxy(x, y);
	printf("S-");
}
void Scorpion_remove(int x, int y)
{
	gotoxy(x, y);
	putchar(BLANK);
}
#endif
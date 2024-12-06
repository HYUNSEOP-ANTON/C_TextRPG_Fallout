#ifndef Player_h
#define Player_h
#include "Interface.h"

typedef struct Items
{
	int Ammo; //���� 1
	int Stimpack; //���� 1
} Item;
typedef struct ValutBoy
{
	char name[12];
	double SPECIAL[7]; //�⺻���� ������ 1�ϋ�.
	//��
	int Carry; // �⺻�� = 50 + (10��); �������� 150 ĳ�� ���� 50 = ��Ʈ ���ϳ�, �����ϳ� ź�� 50������
	//����
	int Accuracy; // �⺻�� = 45 +(5��); �������� 95��
	//������
	int HP; // �⺻�� = 30 (+4��); ���� �������� 4�� ����
	//ī������
	int Talk; // �⺻�� = 5 (+1��);
	//����
	double Intel; //�⺻�� = 1// 10������ ����ġ�� 2��� ȹ��
	//��ø
	int AP; //�⺻�� = 1 (+1)��
	//��
	int Luck; //�⺻�� = 10 (+2��) 10 ~ �ִ�: 30 
	//����ġ
	int EXP;
	int damage;
	int level;
	Item inventory;
} Player;

void player_getname(Player* a);
void player_default(Player* a);
void player_print_special(Player* a);
void player_print_special_info(int choice);
void player_set_result(Player* a);
void player_set(Player* a);
void player_ingame_info(Player* a);
void player_move(Player* a, char ch, int MAP[MAPHEIGHT][MAPWIDTH], int LEFTMONSTERS[6], int STAGENUMBER);
void player_stimpack(Player* a);
int attack(Player* a);
#endif
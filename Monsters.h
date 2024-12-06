#ifndef Monsters_h
#define Monster_h
#include "Player.h"

//����
typedef struct Scorpion
{
	int Accuracy; //�⺻�� 45
	int HP; //�⺻�� 30
	int AP; //�⺻�� 4
	int LUCK; //�⺻�� 10
	int Give_EXP; //�⺻�� 100
	int damage;//�⺻�� 4
	Item item;
} Scorpion;
typedef struct Raider
{
	int Accuracy;
	int HP;
	int AP;
	int LUCK;
	int Give_EXP;
	int damage;
	Item item;
}Raider;
typedef struct ghoul
{
	int Accuracy;
	int HP;
	int AP;
	int LUCK;
	int Give_EXP;
	int damage;
	Item item;
}ghoul;
typedef struct Mutant
{
	int Accuracy;
	int HP;
	int AP;
	int LUCK;
	int Give_EXP;
	int damage;
	Item item;
}Mutant;
typedef struct Boss
{
	int Accuracy;
	int HP;
	int AP;
	int LUCK;
	int damage;
}Boss;

//������� � ���� �ٸ� �����
void default_scorpion(Scorpion* a, Player* b);
void default_raider(Raider* a, Player* b);
void default_ghoul(ghoul* a, Player* b);
void default_mutant(Mutant* a, Player* b);
void default_boss(Boss* a);

//��������Լ�
void scorpion_ingame_info(Scorpion* a);
void raider_ingame_info(Raider* a);
void ghoul_ingame_info(ghoul* a);
void mutant_ingame_info(Mutant* a);
void boss_ingame_info(Boss* a);
#endif
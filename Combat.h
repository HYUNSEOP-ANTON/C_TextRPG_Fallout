#ifndef Combat_h
#define Combat_h

#include "Player.h"
#include "Monsters.h"
//�����ǿ�
int attack_scorpion(Scorpion* e);
void exp_item_scorpion(Scorpion* e, Player* a);
void combat_scorpion(Player* a);
//���̴�
int attack_raider(Raider* e);
void exp_item_raider(Raider* e, Player* a);
void combat_raider(Player* a);
//����
int attack_ghoul(ghoul* e);
void exp_item_ghoul(ghoul* e, Player* a);
void combat_ghoul(Player* a);
//����Ʈ
int attack_mutant(Mutant* e);
void exp_item_mutant(Mutant* e, Player* a);
void combat_mutant(Player* a);
//����
int attack_boss(Boss* e);
void special_boss_ending();
void combat_boss(Player* a);
//�Ĺ� ����
void combat_main(int i, Player* a);
#endif
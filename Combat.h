#ifndef Combat_h
#define Combat_h

#include "Player.h"
#include "Monsters.h"
//스콜피온
int attack_scorpion(Scorpion* e);
void exp_item_scorpion(Scorpion* e, Player* a);
void combat_scorpion(Player* a);
//레이더
int attack_raider(Raider* e);
void exp_item_raider(Raider* e, Player* a);
void combat_raider(Player* a);
//구울
int attack_ghoul(ghoul* e);
void exp_item_ghoul(ghoul* e, Player* a);
void combat_ghoul(Player* a);
//뮤턴트
int attack_mutant(Mutant* e);
void exp_item_mutant(Mutant* e, Player* a);
void combat_mutant(Player* a);
//보스
int attack_boss(Boss* e);
void special_boss_ending();
void combat_boss(Player* a);
//컴뱃 메인
void combat_main(int i, Player* a);
#endif
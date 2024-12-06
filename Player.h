#ifndef Player_h
#define Player_h
#include "Interface.h"

typedef struct Items
{
	int Ammo; //무게 1
	int Stimpack; //무게 1
} Item;
typedef struct ValutBoy
{
	char name[12];
	double SPECIAL[7]; //기본값은 스탯이 1일떄.
	//힘
	int Carry; // 기본값 = 50 + (10씩); 다찍으면 150 캐리 가능 50 = 볼트 옷하나, 권총하나 탄약 50발정도
	//인지
	int Accuracy; // 기본값 = 45 +(5씩); 다찍으면 95퍼
	//지구력
	int HP; // 기본값 = 30 (+4씩); 이후 레벨업당 4씩 증가
	//카리스마
	int Talk; // 기본값 = 5 (+1씩);
	//지능
	double Intel; //기본값 = 1// 10찍으면 경험치량 2배로 획득
	//민첩
	int AP; //기본값 = 1 (+1)씩
	//운
	int Luck; //기본값 = 10 (+2씩) 10 ~ 최대: 30 
	//경험치
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
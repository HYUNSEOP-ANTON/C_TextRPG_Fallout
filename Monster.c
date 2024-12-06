#include "Monsters.h"
void default_scorpion(Scorpion* a, Player* b)
{
	a->Accuracy = 45;
	a->HP = 45;
	a->AP = 6;
	a->LUCK = 10;
	a->Give_EXP = 100;
	int playerluck = b->SPECIAL[6];
	switch (playerluck)
	{
	case 5:
	case 6:
	case 7:
		a->item.Ammo = rand() % 3 + 4;//5 ~ 15발
		a->item.Stimpack = rand() % 2 + 1; //1 ~ 2
		break;
	case 8:
	case 9:
		a->item.Ammo = rand() % 4 + 7; // 15 ~ 20 발
		a->item.Stimpack = rand() % 3 + 2; // 2 ~ 4
		break;
	case 10:
	case 11:
		a->item.Ammo = rand() % 11 + 10; //21 ~ 30발
		a->item.Stimpack = rand() % 4 + 3;; // 3~7
		break;
	default:
		a->item.Ammo = rand() % 3 + 1; //1 ~ 3발
		a->item.Stimpack = rand() % 2; //0~1발
	}
	a->damage = rand() % 2 + 4; //4 5
}
void default_raider(Raider* a, Player* b)
{
	a->Accuracy = 55;
	a->HP = 55;
	a->AP = 6;
	a->LUCK = 12;
	a->Give_EXP = 200;
	int playerluck = b->SPECIAL[6];
	switch (playerluck)
	{
	case 5:
	case 6:
	case 7:
		a->item.Ammo = rand() % 11 + 4;//5 ~ 15발
		a->item.Stimpack = rand() % 3 + 1; //1 ~ 3
		break;
	case 8:
	case 9:
		a->item.Ammo = rand() % 6 + 14; // 15 ~ 20 발
		a->item.Stimpack = rand() % 3 + 3; // 3 ~ 5
		break;
	case 10:
	case 11:
		a->item.Ammo = rand() % 10 + 21; //21 ~ 30발
		a->item.Stimpack = rand() % 4 + 5; // 5 ~ 8	
		break;
	default:
		a->item.Ammo = rand() % 5 + 1; //1 ~ 5발
		a->item.Stimpack = rand() % 2; //0~1
	}
	a->damage = rand() % 4 + 4; //4 ~ 8
}
void default_ghoul(ghoul* a, Player* b)
{
	a->Accuracy = 65;
	a->HP = 60;
	a->AP = 9;
	a->LUCK = 14;
	a->Give_EXP = 300;
	int playerluck = b->SPECIAL[6];
	switch (playerluck)
	{
	case 5:
	case 6:
	case 7:
		a->item.Ammo = rand() % 11 + 4;//5 ~ 15발
		a->item.Stimpack = rand() % 3 + 1; //1 ~ 3
		break;
	case 8:
	case 9:
		a->item.Ammo = rand() % 6 + 14; // 15 ~ 20 발
		a->item.Stimpack = rand() % 3 + 3; // 3 ~ 5
		break;
	case 10:
	case 11:
		a->item.Ammo = rand() % 10 + 21; //21 ~ 30발
		a->item.Stimpack = rand() % 4 + 5; // 5 ~ 8	
		break;
	default:
		a->item.Ammo = rand() % 5 + 1; //1 ~ 5발
		a->item.Stimpack = rand() % 2; //0~1
	}
	a->damage = rand() % 3 + 7; //7 - 9
}
void default_mutant(Mutant* a, Player* b)
{
	a->Accuracy = 70;
	a->HP = 100;
	a->AP = 9;
	a->LUCK = 15;
	a->Give_EXP = 500;
	int playerluck = b->SPECIAL[6];
	switch (playerluck)
	{
	case 5:
	case 6:
	case 7:
		a->item.Ammo = rand() % 11 + 4;//5 ~ 15발
		a->item.Stimpack = rand() % 3 + 1; //1 ~ 3
		break;
	case 8:
	case 9:
		a->item.Ammo = rand() % 6 + 14; // 15 ~ 20 발
		a->item.Stimpack = rand() % 3 + 3; // 3 ~ 5
		break;
	case 10:
	case 11:
		a->item.Ammo = rand() % 10 + 21; //21 ~ 30발
		a->item.Stimpack = rand() % 4 + 5; // 5 ~ 8	
		break;
	default:
		a->item.Ammo = rand() % 5 + 1; //1 ~ 5발
		a->item.Stimpack = rand() % 2; //0~1
	}
	a->damage = rand() % 4 + 8; //8 -11
}
void default_boss(Boss* a)
{
	a->Accuracy = 85;
	a->AP = 12;
	a->HP = 300;
	a->LUCK = 10;
	a->damage = 15;
}
//정보출력함수
void scorpion_ingame_info(Scorpion* a)
{
	int maxhp = 45;
	gotoxy(84, 16);
	printf("       ");
	gotoxy(84, 16);
	printf("적");
	gotoxy(84, 17);
	printf("            ");
	gotoxy(84, 17);
	printf("Rad Scorpion");
	gotoxy(84, 19);
	printf("            ");
	gotoxy(84, 19);
	printf("HP : [%d/%d]", maxhp, a->HP);
	gotoxy(84, 20);
	printf("               ");
	gotoxy(84, 20);
	printf("공격력 : [%d]", a->damage);
	gotoxy(84, 21);
	printf("                   ");
	gotoxy(84, 21);
	printf("액션포인트 : %d", a->AP);
}
void raider_ingame_info(Raider* a)
{
	int maxhp = 55;
	gotoxy(84, 16);
	printf("       ");
	gotoxy(84, 16);
	printf("적");
	gotoxy(84, 17);
	printf("            ");
	gotoxy(84, 17);
	printf("Wastedland Raider");
	gotoxy(84, 19);
	printf("                  ");
	gotoxy(84, 19);
	printf("HP : [%d/%d]", maxhp, a->HP);
	gotoxy(84, 20);
	printf("               ");
	gotoxy(84, 20);
	printf("공격력 : [%d]", a->damage);
	gotoxy(84, 21);
	printf("                   ");
	gotoxy(84, 21);
	printf("액션포인트 : %d", a->AP);
}
void ghoul_ingame_info(ghoul* a)
{
	int maxhp = 60;
	gotoxy(84, 16);
	printf("       ");
	gotoxy(84, 16);
	printf("적");
	gotoxy(84, 17);
	printf("            ");
	gotoxy(84, 17);
	printf("Feral Ghoul");
	gotoxy(84, 19);
	printf("                  ");
	gotoxy(84, 19);
	printf("HP : [%d/%d]", maxhp, a->HP);
	gotoxy(84, 20);
	printf("               ");
	gotoxy(84, 20);
	printf("공격력 : [%d]", a->damage);
	gotoxy(84, 21);
	printf("                   ");
	gotoxy(84, 21);
	printf("액션포인트 : %d", a->AP);
}
void mutant_ingame_info(Mutant* a)
{
	int maxhp = 100;
	gotoxy(84, 16);
	printf("       ");
	gotoxy(84, 16);
	printf("적");
	gotoxy(84, 17);
	printf("            ");
	gotoxy(84, 17);
	printf("Mutant");
	gotoxy(84, 19);
	printf("                  ");
	gotoxy(84, 19);
	printf("HP : [%d/%d]", maxhp, a->HP);
	gotoxy(84, 20);
	printf("               ");
	gotoxy(84, 20);
	printf("공격력 : [%d]", a->damage);
	gotoxy(84, 21);
	printf("                   ");
	gotoxy(84, 21);
	printf("액션포인트 : %d", a->AP);
}
void boss_ingame_info(Boss* a)
{
	int maxhp = 300;
	gotoxy(84, 16);
	printf("       ");
	gotoxy(84, 16);
	printf("적");
	gotoxy(84, 17);
	printf("            ");
	gotoxy(84, 17);
	printf("Lieutent Mutant");
	gotoxy(84, 19);
	printf("                  ");
	gotoxy(84, 19);
	printf("HP : [%d/%d]", maxhp, a->HP);
	gotoxy(84, 20);
	printf("               ");
	gotoxy(84, 20);
	printf("공격력 : [%d]", a->damage);
	gotoxy(84, 21);
	printf("                   ");
	gotoxy(84, 21);
	printf("액션포인트 : %d", a->AP);
}
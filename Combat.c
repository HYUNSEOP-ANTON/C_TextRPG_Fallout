#include "Combat.h"
//스콜피온
int attack_scorpion(Scorpion* e)
{
	int damage = e->damage;
	int rate = rand() % 100 + 1;
	if (e->LUCK >= rate && e->Accuracy >= rate)
	{
		damage = damage * 2;
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Critical! | X2 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                       ");
	}
	else if (e->Accuracy < rate)
	{
		damage = damage / 2;
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Bad Aim | X0.5 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                         ");
	}
	else if (e->LUCK < rate && e->Accuracy >= rate)
	{
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Hit | X1 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                    ");
	}
	return damage;
}
void exp_item_scorpion(Scorpion* e, Player* a)
{
	char i; int delta;  double exp = e->Give_EXP * a->Intel;
	player_ingame_info(a);
	gotoxy(10, 7);
	printf("[경험치 %d X %.1f 획득]", e->Give_EXP, a->Intel);
	a->EXP += exp;
	player_ingame_info(a);
	gotoxy(10, 11); printf("모두 다 가져가기 (f)");
	gotoxy(10, 13); printf("스팀팩 가져가기 (g)");
	gotoxy(10, 15); printf("9mm 탄약 가져가기 (h)");
	gotoxy(10, 17); printf("종료 (q)");
	while (1)
	{
		gotoxy(10, 9); printf("[전리품 목록]");
		gotoxy(30, 9);
		printf("                                 ");
		gotoxy(30, 9);
		printf("탄약 : %d /스팀팩 : %d", e->item.Ammo, e->item.Stimpack);

		i = getch();
		int cancarry = a->Carry;
		int nowcarry = a->inventory.Ammo + a->inventory.Stimpack;
		int ablecarry = cancarry - nowcarry;

		int reward1 = e->item.Ammo;
		int reward2 = e->item.Stimpack;
		int reward_total = reward1 + reward2;
		switch (i)
		{
		case 'f':
			if (ablecarry >= reward_total)
			{
				a->inventory.Stimpack += e->item.Stimpack;
				a->inventory.Ammo += e->item.Stimpack;
				return;
			}
			else
			{
				gotoxy(32, 11);
				printf("오류");
				Sleep(1500);
				gotoxy(32, 11);
				printf("          ");
				continue;
			}
		case 'g':
			gotoxy(30, 13);
			printf("몇 개를 가지겠습니까? : ");
			scanf("%d", &delta);
			gotoxy(30, 13);
			printf("                                       ");
			if (delta <= e->item.Stimpack && ablecarry >= delta)
			{
				a->inventory.Stimpack += delta;
				e->item.Stimpack -= delta;
				player_ingame_info(a);
				continue;
			}
			else
			{
				gotoxy(30, 13);
				printf("오류");
				Sleep(1500);
				gotoxy(30, 13);
				printf("          ");
				continue;
			}
		case 'h':
			gotoxy(32, 15);
			printf("몇 개를 가지겠습니까? : ");
			scanf("%d", &delta);
			gotoxy(32, 15);
			printf("                                       ");
			if (delta <= e->item.Ammo && ablecarry >= delta)
			{
				a->inventory.Ammo += delta;
				e->item.Ammo -= delta;
				player_ingame_info(a);
				continue;
			}
			else
			{
				gotoxy(32, 15);
				printf("오류");
				Sleep(1500);
				gotoxy(32, 15);
				printf("          ");
				continue;
			}
		case 'q':
			return;
		default:
			continue;
		}
	}
}
void combat_scorpion(Player* a)
{
	Scorpion e;
	default_scorpion(&e, a);
	int PT = a->AP; int FPT = PT;
	int SHP = e.HP;
	int ST = e.AP; int FST = ST;
	char ch;
	draw_interface();
	player_ingame_info(a);
	scorpion_ingame_info(&e);
	while (1)
	{
		gotoxy(10, 5);
		printf("                                       ");
		gotoxy(10, 5);
		printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		if (e.HP <= 0 || a->HP <= 0)
		{
			draw_interface();
			gotoxy(10, 5);
			printf("전투 종료");
			Sleep(1500);
			if (a->HP > 0)
				exp_item_scorpion(&e, a);
			break;
		}
		if (FPT >= 3) //ap가 남으면
		{
			gotoxy(10, 7);
			printf("피스톨 사격 (y) : 3 AP");
			gotoxy(10, 9);
			printf("스팀팩 사용 (t):  3 AP");
			gotoxy(10, 14);
			printf("턴 넘기기 (r)");
			ch = getch();
			switch (ch)
			{
			case 'y':
				if (a->inventory.Ammo > 0)
				{
					e.HP -= attack(a);
					FPT -= 3;
					player_ingame_info(a);
					scorpion_ingame_info(&e);
					break;
				}
				else
				{
					gotoxy(10, 8); textcolor(WHITE, BLACK);
					printf("탄약 부족"); Sleep(1500);
					gotoxy(10, 8); textcolor(GREEN, BLACK);
					printf("          ");
					continue;
				}
			case 't':
				if (a->inventory.Stimpack > 0 && a->HP < a->SPECIAL[2] * 5 + 30)
				{
					player_stimpack(a);
					player_ingame_info(a);
					scorpion_ingame_info(&e);
					FPT -= 3;
					break;
				}
				else
				{
					gotoxy(84, 11); textcolor(WHITE, BLACK);
					printf("스팀팩 사용 불가"); Sleep(1500);
					gotoxy(84, 11); textcolor(GREEN, BLACK);
					printf("                ");
					continue;
				}
			case 'r':
				FPT = 0;
			}
			gotoxy(10, 5);
			printf("                                   ");
			gotoxy(10, 5);
			printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		}
		else
		{
			//전갈 공격
			gotoxy(10, 20);
			printf("상대의 턴");
			Sleep(500);
			for (FST; FST > 0; FST -= 3) {
				a->HP -= attack_scorpion(&e);
				Sleep(500);
				player_ingame_info(a);
			}
			FPT = PT;
			FST = ST;

			gotoxy(10, 20);
			printf("          ");
			gotoxy(10, 20);
			printf("나의 턴");
			Sleep(500);
		}
	}
	return;
}
//레이더
int attack_raider(Raider* e)
{
	int damage = e->damage;
	int rate = rand() % 100 + 1;
	if (e->LUCK >= rate && e->Accuracy >= rate)
	{
		damage = damage * 2;
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Critical! | X2 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                       ");
	}
	else if (e->Accuracy < rate)
	{
		damage = damage / 2;
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Bad Aim | X0.5 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                         ");
	}
	else if (e->LUCK < rate && e->Accuracy >= rate)
	{
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Hit | X1 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                 ");
	}
	return damage;
}
void exp_item_raider(Raider* e, Player* a)
{
	char i; int delta; double exp = a->Intel * e->Give_EXP;
	a->EXP += exp;
	player_ingame_info(a);
	gotoxy(10, 7);
	printf("[경험치 %d X %.1f 획득]", e->Give_EXP, a->Intel);
	player_ingame_info(a);
	gotoxy(10, 11); printf("모두 다 가져가기 (f)");
	gotoxy(10, 13); printf("스팀팩 가져가기 (g)");
	gotoxy(10, 15); printf("9mm 탄약 가져가기 (h)");
	gotoxy(10, 17); printf("종료 (q)");
	while (1)
	{
		gotoxy(10, 9); printf("[전리품 목록]");
		gotoxy(30, 9);
		printf("                                 ");
		gotoxy(30, 9);
		printf("탄약 : %d /스팀팩 : %d", e->item.Ammo, e->item.Stimpack);

		i = getch();
		int cancarry = a->Carry;
		int nowcarry = a->inventory.Ammo + a->inventory.Stimpack;
		int ablecarry = cancarry - nowcarry;

		int reward1 = e->item.Ammo;
		int reward2 = e->item.Stimpack;
		int reward_total = reward1 + reward2;
		switch (i)
		{
		case 'f':
			if (ablecarry >= reward_total)
			{
				a->inventory.Stimpack += e->item.Stimpack;
				a->inventory.Ammo += e->item.Stimpack;
				return;
			}
			else
			{
				gotoxy(32, 11);
				printf("오류");
				Sleep(1500);
				gotoxy(32, 11);
				printf("          ");
				continue;
			}
		case 'g':
			gotoxy(30, 13);
			printf("몇 개를 가지겠습니까? : ");
			scanf("%d", &delta);
			gotoxy(30, 13);
			printf("                                       ");
			if (delta <= e->item.Stimpack && ablecarry >= delta)
			{
				a->inventory.Stimpack += delta;
				e->item.Stimpack -= delta;
				player_ingame_info(a);
				continue;
			}
			else
			{
				gotoxy(30, 13);
				printf("오류");
				Sleep(1500);
				gotoxy(30, 13);
				printf("          ");
				continue;
			}
		case 'h':
			gotoxy(32, 15);
			printf("몇 개를 가지겠습니까? : ");
			scanf("%d", &delta);
			gotoxy(32, 15);
			printf("                                       ");
			if (delta <= e->item.Ammo && ablecarry >= delta)
			{
				a->inventory.Ammo += delta;
				e->item.Ammo -= delta;
				player_ingame_info(a);
				continue;
			}
			else
			{
				gotoxy(32, 15);
				printf("오류");
				Sleep(1500);
				gotoxy(32, 15);
				printf("          ");
				continue;
			}
		case 'q':
			return;
		default:
			continue;
		}
	}
}
void combat_raider(Player* a)
{
	Raider e;
	default_raider(&e, a);
	int PT = a->AP; int FPT = PT;
	int SHP = e.HP;
	int ST = e.AP; int FST = ST;
	char ch;
	draw_interface();
	player_ingame_info(a);
	raider_ingame_info(&e);
	while (1)
	{
		gotoxy(10, 5);
		printf("                                       ");
		gotoxy(10, 5);
		printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		if (e.HP <= 0 || a->HP <= 0)
		{
			draw_interface();
			gotoxy(10, 5);
			printf("전투 종료");
			Sleep(1500);
			if (a->HP > 0)
				exp_item_raider(&e, a);
			break;
		}
		if (FPT >= 3) //ap가 남으면
		{
			gotoxy(10, 7);
			printf("피스톨 사격 (y) : 3 AP");
			gotoxy(10, 9);
			printf("스팀팩 사용 (t):  3 AP");
			gotoxy(10, 14);
			printf("턴 넘기기 (r)");
			ch = getch();
			switch (ch)
			{
			case 'y':
				if (a->inventory.Ammo > 0)
				{
					e.HP -= attack(a);
					FPT -= 3;
					player_ingame_info(a);
					raider_ingame_info(&e);
					break;
				}
				else
				{
					gotoxy(10, 8); textcolor(WHITE, BLACK);
					printf("탄약 부족"); Sleep(1500);
					gotoxy(10, 8); textcolor(GREEN, BLACK);
					printf("          ");
					continue;
				}
			case 't':
				if (a->inventory.Stimpack > 0 && a->HP < a->SPECIAL[2] * 5 + 30)
				{
					player_stimpack(a);
					player_ingame_info(a);
					raider_ingame_info(&e);
					FPT -= 3;
					break;
				}
				else
				{
					gotoxy(84, 11); textcolor(WHITE, BLACK);
					printf("스팀팩 사용 불가"); Sleep(1500);
					gotoxy(84, 11); textcolor(GREEN, BLACK);
					printf("                ");
					continue;
				}
			case 'r':
				FPT = 0;
			}
			gotoxy(10, 5);
			printf("                                   ");
			gotoxy(10, 5);
			printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		}
		else
		{
			//전갈 공격
			gotoxy(10, 20);
			printf("상대의 턴");
			Sleep(500);
			for (FST; FST > 0; FST -= 3) {
				a->HP -= attack_raider(&e);
				Sleep(500);
				player_ingame_info(a);
			}
			FPT = PT;
			FST = ST;

			gotoxy(10, 20);
			printf("          ");
			gotoxy(10, 20);
			printf("나의 턴");
			Sleep(500);
		}
	}
	return;
}
//구울
int attack_ghoul(ghoul* e)
{
	int damage = e->damage;
	int rate = rand() % 100 + 1;
	if (e->LUCK >= rate && e->Accuracy >= rate)
	{
		damage = damage * 2;
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Critical! | X2 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                       ");
	}
	else if (e->Accuracy < rate)
	{
		damage = damage / 2;
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Bad Aim | X0.5 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                         ");
	}
	else if (e->LUCK < rate && e->Accuracy >= rate)
	{
		gotoxy(40, 12);
		textcolor(WHITE, BLACK);
		printf("Hit | X1 damage\a");
		Sleep(500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 12);
		printf("                 ");
	}
	return damage;
}
void exp_item_ghoul(ghoul* e, Player* a)
{
	char i; int delta;
	double exp = a->Intel * e->Give_EXP;
	a->EXP += exp;
	player_ingame_info(a);
	gotoxy(10, 7);
	printf("[경험치 %d X %.1f 획득]", e->Give_EXP, a->Intel);
	player_ingame_info(a);
	gotoxy(10, 11); printf("모두 다 가져가기 (f)");
	gotoxy(10, 13); printf("스팀팩 가져가기 (g)");
	gotoxy(10, 15); printf("9mm 탄약 가져가기 (h)");
	gotoxy(10, 17); printf("종료 (q)");
	while (1)
	{
		gotoxy(10, 9); printf("[전리품 목록]");
		gotoxy(30, 9);
		printf("                                 ");
		gotoxy(30, 9);
		printf("탄약 : %d /스팀팩 : %d", e->item.Ammo, e->item.Stimpack);

		i = getch();
		int cancarry = a->Carry;
		int nowcarry = a->inventory.Ammo + a->inventory.Stimpack;
		int ablecarry = cancarry - nowcarry;

		int reward1 = e->item.Ammo;
		int reward2 = e->item.Stimpack;
		int reward_total = reward1 + reward2;
		switch (i)
		{
		case 'f':
			if (ablecarry >= reward_total)
			{
				a->inventory.Stimpack += e->item.Stimpack;
				a->inventory.Ammo += e->item.Stimpack;
				return;
			}
			else
			{
				gotoxy(32, 11);
				printf("오류");
				Sleep(1500);
				gotoxy(32, 11);
				printf("          ");
				continue;
			}
		case 'g':
			gotoxy(30, 13);
			printf("몇 개를 가지겠습니까? : ");
			scanf("%d", &delta);
			gotoxy(30, 13);
			printf("                                       ");
			if (delta <= e->item.Stimpack && ablecarry >= delta)
			{
				a->inventory.Stimpack += delta;
				e->item.Stimpack -= delta;
				player_ingame_info(a);
				continue;
			}
			else
			{
				gotoxy(30, 13);
				printf("오류");
				Sleep(1500);
				gotoxy(30, 13);
				printf("          ");
				continue;
			}
		case 'h':
			gotoxy(32, 15);
			printf("몇 개를 가지겠습니까? : ");
			scanf("%d", &delta);
			gotoxy(32, 15);
			printf("                                       ");
			if (delta <= e->item.Ammo && ablecarry >= delta)
			{
				a->inventory.Ammo += delta;
				e->item.Ammo -= delta;
				player_ingame_info(a);
				continue;
			}
			else
			{
				gotoxy(32, 15);
				printf("오류");
				Sleep(1500);
				gotoxy(32, 15);
				printf("          ");
				continue;
			}
		case 'q':
			return;
		default:
			continue;
		}
	}

}
void combat_ghoul(Player* a)
{
	ghoul e;
	default_ghoul(&e, a);
	int PT = a->AP; int FPT = PT;
	int SHP = e.HP;
	int ST = e.AP; int FST = ST;
	char ch;
	draw_interface();
	player_ingame_info(a);
	ghoul_ingame_info(&e);
	while (1)
	{
		gotoxy(10, 5);
		printf("                                       ");
		gotoxy(10, 5);
		printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		if (e.HP <= 0 || a->HP <= 0)
		{
			draw_interface();
			gotoxy(10, 5);
			printf("전투 종료");
			Sleep(1500);
			if (a->HP > 0)
				exp_item_ghoul(&e, a);
			break;
		}
		if (FPT >= 3) //ap가 남으면
		{
			gotoxy(10, 7);
			printf("피스톨 사격 (y) : 3 AP");
			gotoxy(10, 9);
			printf("스팀팩 사용 (t):  3 AP");
			gotoxy(10, 14);
			printf("턴 넘기기 (r)");
			ch = getch();
			switch (ch)
			{
			case 'y':
				if (a->inventory.Ammo > 0)
				{
					e.HP -= attack(a);
					FPT -= 3;
					player_ingame_info(a);
					ghoul_ingame_info(&e);
					break;
				}
				else
				{
					gotoxy(10, 8); textcolor(WHITE, BLACK);
					printf("탄약 부족"); Sleep(1500);
					gotoxy(10, 8); textcolor(GREEN, BLACK);
					printf("          ");
					continue;
				}
			case 't':
				if (a->inventory.Stimpack > 0 && a->HP < a->SPECIAL[2] * 5 + 30)
				{
					player_stimpack(a);
					player_ingame_info(a);
					ghoul_ingame_info(&e);
					FPT -= 3;
					break;
				}
				else
				{
					gotoxy(84, 11); textcolor(WHITE, BLACK);
					printf("스팀팩 사용 불가"); Sleep(1500);
					gotoxy(84, 11); textcolor(GREEN, BLACK);
					printf("                ");
					continue;
				}
			case 'r':
				FPT = 0;
			}
			gotoxy(10, 5);
			printf("                                   ");
			gotoxy(10, 5);
			printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		}
		else
		{
			//전갈 공격
			gotoxy(10, 20);
			printf("상대의 턴");
			Sleep(500);
			for (FST; FST > 0; FST -= 3) {
				a->HP -= attack_ghoul(&e);
				Sleep(500);
				player_ingame_info(a);
			}
			FPT = PT;
			FST = ST;

			gotoxy(10, 20);
			printf("          ");
			gotoxy(10, 20);
			printf("나의 턴");
			Sleep(500);
		}
	}
	return;
}
//뮤턴트
int attack_mutant(Mutant* e)
{
	{
		int damage = e->damage;
		int rate = rand() % 100 + 1;
		if (e->LUCK >= rate && e->Accuracy >= rate)
		{
			damage = damage * 2;
			gotoxy(40, 12);
			textcolor(WHITE, BLACK);
			printf("Critical! | X2 damage\a");
			Sleep(500);
			textcolor(GREEN, BLACK);
			gotoxy(40, 12);
			printf("                       ");
		}
		else if (e->Accuracy < rate)
		{
			damage = damage / 2;
			gotoxy(40, 12);
			textcolor(WHITE, BLACK);
			printf("Bad Aim | X0.5 damage\a");
			Sleep(500);
			textcolor(GREEN, BLACK);
			gotoxy(40, 12);
			printf("                         ");
		}
		else if (e->LUCK < rate && e->Accuracy >= rate)
		{
			gotoxy(40, 12);
			textcolor(WHITE, BLACK);
			printf("Hit | X1 damage\a");
			Sleep(500);
			textcolor(GREEN, BLACK);
			gotoxy(40, 12);
			printf("                 ");
		}
		return damage;
	}
}
void exp_item_mutant(Mutant* e, Player* a)
{

	{
		char i; int delta;
		double exp = a->Intel * e->Give_EXP;
		a->EXP += exp;
		player_ingame_info(a);
		gotoxy(10, 7);
		printf("[경험치 %d X %.1f 획득]", e->Give_EXP, a->Intel);
		player_ingame_info(a);
		gotoxy(10, 11); printf("모두 다 가져가기 (f)");
		gotoxy(10, 13); printf("스팀팩 가져가기 (g)");
		gotoxy(10, 15); printf("9mm 탄약 가져가기 (h)");
		gotoxy(10, 17); printf("종료 (q)");
		while (1)
		{
			gotoxy(10, 9); printf("[전리품 목록]");
			gotoxy(30, 9);
			printf("                                 ");
			gotoxy(30, 9);
			printf("탄약 : %d /스팀팩 : %d", e->item.Ammo, e->item.Stimpack);

			i = getch();
			int cancarry = a->Carry;
			int nowcarry = a->inventory.Ammo + a->inventory.Stimpack;
			int ablecarry = cancarry - nowcarry;

			int reward1 = e->item.Ammo;
			int reward2 = e->item.Stimpack;
			int reward_total = reward1 + reward2;
			switch (i)
			{
			case 'f':
				if (ablecarry >= reward_total)
				{
					a->inventory.Stimpack += e->item.Stimpack;
					a->inventory.Ammo += e->item.Stimpack;
					return;
				}
				else
				{
					gotoxy(32, 11);
					printf("오류");
					Sleep(1500);
					gotoxy(32, 11);
					printf("          ");
					continue;
				}
			case 'g':
				gotoxy(30, 13);
				printf("몇 개를 가지겠습니까? : ");
				scanf("%d", &delta);
				gotoxy(30, 13);
				printf("                                       ");
				if (delta <= e->item.Stimpack && ablecarry >= delta)
				{
					a->inventory.Stimpack += delta;
					e->item.Stimpack -= delta;
					player_ingame_info(a);
					continue;
				}
				else
				{
					gotoxy(30, 13);
					printf("오류");
					Sleep(1500);
					gotoxy(30, 13);
					printf("          ");
					continue;
				}
			case 'h':
				gotoxy(32, 15);
				printf("몇 개를 가지겠습니까? : ");
				scanf("%d", &delta);
				gotoxy(32, 15);
				printf("                                       ");
				if (delta <= e->item.Ammo && ablecarry >= delta)
				{
					a->inventory.Ammo += delta;
					e->item.Ammo -= delta;
					player_ingame_info(a);
					continue;
				}
				else
				{
					gotoxy(32, 15);
					printf("오류");
					Sleep(1500);
					gotoxy(32, 15);
					printf("          ");
					continue;
				}
			case 'q':
				return;
			default:
				continue;
			}
		}

	}
}
void combat_mutant(Player* a)
{
	Mutant e;
	default_mutant(&e, a);
	int PT = a->AP; int FPT = PT;
	int SHP = e.HP;
	int ST = e.AP; int FST = ST;
	char ch;
	draw_interface();
	player_ingame_info(a);
	mutant_ingame_info(&e);
	while (1)
	{
		gotoxy(10, 5);
		printf("                                       ");
		gotoxy(10, 5);
		printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		if (e.HP <= 0 || a->HP <= 0)
		{
			draw_interface();
			gotoxy(10, 5);
			printf("전투 종료");
			Sleep(1500);
			if (a->HP > 0)
				exp_item_mutant(&e, a);
			break;
		}
		if (FPT >= 3) //ap가 남으면
		{
			gotoxy(10, 7);
			printf("피스톨 사격 (y) : 3 AP");
			gotoxy(10, 9);
			printf("스팀팩 사용 (t):  3 AP");
			gotoxy(10, 14);
			printf("턴 넘기기 (r)");
			ch = getch();
			switch (ch)
			{
			case 'y':
				if (a->inventory.Ammo > 0)
				{
					e.HP -= attack(a);
					FPT -= 3;
					player_ingame_info(a);
					mutant_ingame_info(&e);
					break;
				}
				else
				{
					gotoxy(10, 8); textcolor(WHITE, BLACK);
					printf("탄약 부족"); Sleep(1500);
					gotoxy(10, 8); textcolor(GREEN, BLACK);
					printf("          ");
					continue;
				}
			case 't':
				if (a->inventory.Stimpack > 0 && a->HP < a->SPECIAL[2] * 5 + 30)
				{
					player_stimpack(a);
					player_ingame_info(a);
					mutant_ingame_info(&e);
					FPT -= 3;
					break;
				}
				else
				{
					gotoxy(84, 11); textcolor(WHITE, BLACK);
					printf("스팀팩 사용 불가"); Sleep(1500);
					gotoxy(84, 11); textcolor(GREEN, BLACK);
					printf("                ");
					continue;
				}
			case 'r':
				FPT = 0;
			}
			gotoxy(10, 5);
			printf("                                   ");
			gotoxy(10, 5);
			printf("VATS MODE | 액션포인트(AP) : %d", FPT);
		}
		else
		{
			//전갈 공격
			gotoxy(10, 20);
			printf("상대의 턴");
			Sleep(500);
			for (FST; FST > 0; FST -= 3) {
				a->HP -= attack_mutant(&e);
				Sleep(500);
				player_ingame_info(a);
			}
			FPT = PT;
			FST = ST;

			gotoxy(10, 20);
			printf("          ");
			gotoxy(10, 20);
			printf("나의 턴");
			Sleep(500);
		}
	}
	return;
}
//보스
int attack_boss(Boss* e)
{
	{
		int damage = e->damage;
		int rate = rand() % 100 + 1;
		if (e->LUCK >= rate && e->Accuracy >= rate)
		{
			damage = damage * 2;
			gotoxy(40, 12);
			textcolor(WHITE, BLACK);
			printf("Critical! | X2 damage\a");
			Sleep(500);
			textcolor(GREEN, BLACK);
			gotoxy(40, 12);
			printf("                       ");
		}
		else if (e->Accuracy < rate)
		{
			damage = damage / 2;
			gotoxy(40, 12);
			textcolor(WHITE, BLACK);
			printf("Bad Aim | X0.5 damage\a");
			Sleep(500);
			textcolor(GREEN, BLACK);
			gotoxy(40, 12);
			printf("                         ");
		}
		else if (e->LUCK < rate && e->Accuracy >= rate)
		{
			gotoxy(40, 12);
			textcolor(WHITE, BLACK);
			printf("Hit | X1 damage\a");
			Sleep(500);
			textcolor(GREEN, BLACK);
			gotoxy(40, 12);
			printf("                 ");
		}
		return damage;
	}
}
void special_boss_ending()
{
	gotoxy(10, 5);
	printf("당신은 높은 지능과 매력으로 뮤턴트를 설득했습니다.");
	getch();
	return;
}
void combat_boss(Player* a)
{
	Boss e;
	default_boss(&e);
	int PT = a->AP; int FPT = PT;
	int ST = e.AP; int FST = ST;
	char ch; char s;
	draw_interface();
	player_ingame_info(a);
	boss_ingame_info(&e);
	if (a->SPECIAL[6] == 10 && a->Talk >= 10 && a->SPECIAL[3] >= 8)
	{
		gotoxy(10, 5);
		printf("뮤턴트와 대화를 해볼 수 있을 것 같습니다.");
		gotoxy(10, 6);
		printf("대화를 시도하시겠습니까?");
		gotoxy(10, 7);
		printf("시도 : y        전투 : n");
		s = getch();
		if (s == 'y')
		{
			draw_interface();
			player_ingame_info(a);
			boss_ingame_info(&e);
			special_boss_ending();
			return;
		}
	}
	else {
		while (1)
		{
			gotoxy(10, 5);
			printf("                                       ");
			gotoxy(10, 5);
			printf("VATS MODE | 액션포인트(AP) : %d", FPT);
			if (e.HP <= 0 || a->HP <= 0)
			{
				draw_interface();
				gotoxy(10, 5);
				printf("전투 종료");
				Sleep(1500);
				return;
			}
			if (FPT >= 3) //ap가 남으면
			{
				gotoxy(10, 7);
				printf("피스톨 사격 (y) : 3 AP");
				gotoxy(10, 9);
				printf("스팀팩 사용 (t):  3 AP");
				gotoxy(10, 14);
				printf("턴 넘기기 (r)");
				ch = getch();
				switch (ch)
				{
				case 'y':
					if (a->inventory.Ammo > 0)
					{
						e.HP -= attack(a);
						FPT -= 3;
						player_ingame_info(a);
						boss_ingame_info(&e);
						break;
					}
					else
					{
						gotoxy(10, 8); textcolor(WHITE, BLACK);
						printf("탄약 부족"); Sleep(1500);
						gotoxy(10, 8); textcolor(GREEN, BLACK);
						printf("          ");
						continue;
					}
				case 't':
					if (a->inventory.Stimpack > 0 && a->HP < a->SPECIAL[2] * 5 + 30)
					{
						player_stimpack(a);
						player_ingame_info(a);
						boss_ingame_info(&e);
						FPT -= 3;
						break;
					}
					else
					{
						gotoxy(84, 11); textcolor(WHITE, BLACK);
						printf("스팀팩 사용 불가"); Sleep(1500);
						gotoxy(84, 11); textcolor(GREEN, BLACK);
						printf("                ");
						continue;
					}
				case 'r':
					FPT = 0;
				}
				gotoxy(10, 5);
				printf("                                   ");
				gotoxy(10, 5);
				printf("VATS MODE | 액션포인트(AP) : %d", FPT);
			}
			else
			{
				//전갈 공격
				gotoxy(10, 20);
				printf("상대의 턴");
				Sleep(500);
				for (FST; FST > 0; FST -= 3) {
					a->HP -= attack_boss(&e);
					Sleep(500);
					player_ingame_info(a);
				}
				FPT = PT;
				FST = ST;

				gotoxy(10, 20);
				printf("          ");
				gotoxy(10, 20);
				printf("나의 턴");
				Sleep(500);
			}
		}
	}
}
//컴뱃 메인
void combat_main(int i, Player* a)
{
	switch (i)
	{
	case 0:
		combat_scorpion(a);
		break;
	case 1:
		combat_raider(a);
		break;
	case 2:
		combat_ghoul(a);
		break;
	case 3:
		combat_mutant(a);
		break;
	case 4:
		combat_boss(a);
		break;
	}
	return;
}
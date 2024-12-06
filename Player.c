#include "Player.h"

void player_getname(Player* a)
{
	draw_interface();
	gotoxy(5, 4);
	printf("[캐릭터의 이름을 설정합니다.]");
	gotoxy(5, 5);
	printf("[이름을 입력하세요] (영문 10자리까지) : ");
	scanf("%s", a->name);
}
void player_default(Player* a)
{
	//기본값 설정
	for (int i = 0; i < 7; i++) {
		a->SPECIAL[i] = 5;
	}
	a->Carry = 80;
	a->Accuracy = 45;
	a->HP = 30;
	a->Talk = 1;
	a->Intel = 1;
	a->AP = 4;
	a->Luck = 10;
	a->EXP = 0;
	a->damage = 8;
	//기본 아이템 지급
	a->inventory.Ammo = 60;
	a->inventory.Stimpack = 3;
}
void player_print_special(Player* a)
{
	draw_interface();
	gotoxy(5, 2);
	printf("%s의 SPECIAL", a->name);
	gotoxy(5, 4);
	printf("1.Strength(힘)		| %.0f", a->SPECIAL[0]);
	gotoxy(5, 5);
	printf("2.Perception(인지력)	| %.0f", a->SPECIAL[1]);
	gotoxy(5, 6);
	printf("3.Endurance(지구력)	| %.0f", a->SPECIAL[2]);
	gotoxy(5, 7);
	printf("4.Charisma(매력)		| %.0f", a->SPECIAL[3]);
	gotoxy(5, 8);
	printf("5.Intelligence(지능)	| %.0f", a->SPECIAL[4]);
	gotoxy(5, 9);
	printf("6.Agility(민첩성)		| %.0f", a->SPECIAL[5]);
	gotoxy(5, 10);
	printf("7.Luck(운)			| %.0f", a->SPECIAL[6]);
}
void player_print_special_info(int choice)
{
	gotoxy(5, 5);
	switch (choice)
	{
	case 1:
		printf("[힘은 무게 제한에 영향을 줍니다.] (최대 10)");
		break;
	case 2:
		printf("[인지력은 명중률에 영향을 줍니다.] (최대 10)");
		break;
	case 3:
		printf("[지구력은 체력에 영향을 줍니다.] (최대 10)");
		break;
	case 4:
		printf("[매력은 화술에 영향을 줍니다.] (최대 10)");
		break;
	case 5:
		printf("[지능은 경험치 획득량에 영향을 줍니다.] (최대 10)");
		break;
	case 6:
		printf("[민첩성은 액션포인트에 영향을 줍니다.] (최대 10)");
		break;
	case 7:
		printf("[운은 전반적인 운에 영향을 줍니다.] (최대 10)");
		break;
	}
	//getch();
}
void player_set_result(Player* a)
{
	gotoxy(5, 10);
	printf("능력치 설정이 완료 되었습니다.");
	gotoxy(5, 13);
	printf("볼트 13 유니폼, 9mm 피스톨, 탄약 60발, 스팀팩 3개 지급"); getch();
	a->Carry += 10 * a->SPECIAL[0];
	a->Accuracy += 5 * a->SPECIAL[1];
	a->HP += 5 * a->SPECIAL[2];
	a->Talk += 1 * a->SPECIAL[3];
	a->Intel += 0.1 * a->SPECIAL[4]; 
	a->AP += a->SPECIAL[5];
	a->Luck += 2 * a->SPECIAL[6];
	a->level = 1;
	draw_interface();
	gotoxy(5, 2); printf("당신은 핵전쟁을 대비한 볼트13의 거주자입니다.");
	gotoxy(5, 4); printf("당신이 소속된 볼트13은 현재 물 정화를 위한 핵심 칩이 고장났습니다.");
	gotoxy(5, 6); printf("볼트 13의 관리자인 오버시어는 당신에게 볼트 15로 가서");
	gotoxy(5, 8); printf("워터칩을 구해올 것을 명했습니다."); getch();
}
void player_set(Player* a)
{
	player_getname(a);
	int point = 10; int choice, dchoice, delta;
	player_default(a);
	while (1)
	{
		gotoxy(5, 4);
		player_print_special(a); //현 상태 출력
		gotoxy(5, 12);
		printf("[사용 가능 포인트 : %d ]", point);
		gotoxy(5, 14);
		printf("[번호 선택] (0 : 종료) : ");
		scanf("%d", &choice);
		draw_interface();
		if (choice == 0 && point != 0) {
			gotoxy(5, 7);
			printf("모든 포인트를 다 사용해주세요.");
			getch();
			continue;
		}
		else if (choice == 0 && point == 0) {
			gotoxy(5, 7);
			printf("[특성 선택을 마치겠습니까?] (0: 확인 1: 아니요) : ");
			scanf("%d", &dchoice);
			if (dchoice == 0)
				break;
			else {
				gotoxy(5, 9);
				printf("[설정을 계속합니다.]");
				getch();
				continue;
			}
		}
		if (choice >= 1 && choice <= 7)
		{
			player_print_special_info(choice);
			gotoxy(5, 3);
			printf("[+/- 값을 입력해주세요] (0 : 뒤로가기) : ");
			scanf("%d", &delta);
			if (delta == 0)
				continue;
			else if (point - delta < 0) //포인트보다 델타가 더 많을 때
			{
				gotoxy(5, 7);
				printf("[포인트가 부족합니다]");
				getch();
			}
			else if ((a->SPECIAL[choice - 1] + delta <= 10) && a->SPECIAL[choice - 1] + delta >= 1)
			{
				a->SPECIAL[choice - 1] += delta;
				point -= delta;
			}
			else if (a->SPECIAL[choice - 1] + delta >= 10)
			{
				gotoxy(5, 7);
				printf("[SPECIAL은 10보다 클 수는 없습니다]");
				getch();
			}
			else if (a->SPECIAL[choice - 1] + delta < 1)
			{
				gotoxy(5, 7);
				printf("[SEPCIAL은 1보다 작을 수 없습니다]");
				getch();
			}
		}
		else {
			gotoxy(5, 7);
			printf("[입력이 올바르지 않음]");
			getch();
		}
	}
	player_set_result(a);
	draw_interface();
}
void player_ingame_info(Player* a)
{
	int maxhp = a->SPECIAL[2] * 5 + 30; //기본 최대 체력
	gotoxy(84, 2);
	printf("나 : %s", a->name);
	gotoxy(84, 4);
	printf("HP : [%d / %d]", maxhp, a->HP);
	gotoxy(84, 5);
	printf("탄약 : [%d]", a->inventory.Ammo);
	gotoxy(84, 6);
	printf("공격력 : [%d]", a->damage);
	gotoxy(84, 7);
	printf("스팀팩 : [%d]", a->inventory.Stimpack);
	gotoxy(84, 8);
	printf("경험치 : [%d EXP]", a->EXP);
	gotoxy(84, 9);
	printf("레벨 : [%d]", a->level);
	gotoxy(84, 10);
	printf("짐 : [%d / %d]", a->Carry, a->inventory.Ammo + a->inventory.Stimpack);
}
void player_move(Player* a, char ch, int MAP[MAPHEIGHT][MAPWIDTH], int LEFTMONSTERS[6], int STAGENUMBER)
{
	static int oldx = 10, oldy = 6, newx = 5, newy = 5;
	int move_flag = 0;
	put_player(oldx, oldy);
	switch (ch) {
	case UP:
		if (oldy > 1)
			newy = oldy - 1;
		//move_flag = 1;
		break;
	case DOWN:
		if (oldy < HEIGHT - 1)
			newy = oldy + 1;
		//move_flag = 1;
		break;
	case LEFT:
		if (oldx > 2)
			newx = oldx - 1;
		//move_flag = 1;
		break;
	case RIGHT:
		if (oldx < WIDTH - 1)
			newx = oldx + 1;
		//move_flag = 1;
		break;
	}
	if (1) {
		remove_player(oldx, oldy); // 마지막 위치의 X 를 지우고
		put_player(newx, newy); // 새로운 위치에서 X 를 표시한다.
		oldx = newx; // 마지막 위치를 기억한다.
		oldy = newy;
		//move_flag = 0; // 1:계속 이동, 0:한칸씩 이동
	}
	if (MAP[oldy - 1][oldx - 2] >= 3 && MAP[oldy - 1][oldx - 2] <= 7)
	{
		gotoxy(84, 14); textcolor(WHITE, BLACK); printf("\a전투");
		Sleep(500); gotoxy(84, 14); printf("     ");
		textcolor(GREEN, BLACK);

		MAP[oldy - 1][oldx - 2] = 0; //스콜피온을 지우고, 0으로 설정
		LEFTMONSTERS[STAGENUMBER]--; //0번 스테이지 스콜피언의 수를 지움
		if (LEFTMONSTERS[STAGENUMBER] == 0)
		{
			oldx = 10; oldy = 6;
		}
	}
}
void player_stimpack(Player* a)
{
	int maxhp = a->SPECIAL[2] * 5 + 30;
	int currentstimpack = a->inventory.Stimpack;
	if (currentstimpack > 0 && a->HP < maxhp) {
		a->inventory.Stimpack--;
		gotoxy(84, 11); textcolor(WHITE, BLACK);
		printf("스팀팩 사용");
		Sleep(500); gotoxy(84, 11);
		printf("           ");
		textcolor(GREEN, BLACK);
		for (int i = 0; i < 10; i++)
		{
			if (a->HP < maxhp)
				a->HP++;
			else
				break;
		}
	}
}
int attack(Player* a)
{
	int damage = a->damage;
	int rate = rand() % 100 + 1;
	a->inventory.Ammo--;
	if (a->SPECIAL[6] >= 10 && (rate <= 100 && rate >= 95) && a->Accuracy >= rate)
	{
		damage *= 99;
		printf("\a");
		for (int i = 0; i < 10; i++)
		{
			gotoxy(40, 7);
			textcolor(RED, WHITE);
			printf("!!!! | X99 damage");
			gotoxy(40, 7);
			Sleep(80);
			textcolor(GREEN, BLACK);
			printf("!!!! | X99 damage");
			Sleep(80);
		}
		Sleep(1500);
		textcolor(GREEN, BLACK);
		gotoxy(40, 7);
		printf("                   ");
		return damage;
	}
	else if (a->Luck >= rate && a->Accuracy >= rate)
	{
		damage = damage * 2;
		gotoxy(40, 7);
		textcolor(WHITE, BLACK);
		printf("Critical! | X2 damage\a");
		Sleep(800);
		textcolor(GREEN, BLACK);
		gotoxy(40, 7);
		printf("                          ");
		return damage;
	}
	else if (a->Accuracy < rate)
	{
		damage = damage / 2;
		gotoxy(40, 7);
		gotoxy(40, 7);
		textcolor(WHITE, BLACK);
		printf("Bad Aim | X0.5 damage\a");
		Sleep(800);
		textcolor(GREEN, BLACK);
		gotoxy(40, 7);
		printf("                         ");
		return damage;
	}
	else if (a->Luck < rate && a->Accuracy >= rate)
	{
		gotoxy(40, 7);
		gotoxy(40, 7);
		textcolor(WHITE, BLACK);
		printf("Hit | X1 damage\a");
		Sleep(800);
		textcolor(GREEN, BLACK);
		gotoxy(40, 7);
		printf("                   ");
		return damage;
	}
}
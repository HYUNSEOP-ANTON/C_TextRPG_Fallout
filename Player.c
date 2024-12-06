#include "Player.h"

void player_getname(Player* a)
{
	draw_interface();
	gotoxy(5, 4);
	printf("[ĳ������ �̸��� �����մϴ�.]");
	gotoxy(5, 5);
	printf("[�̸��� �Է��ϼ���] (���� 10�ڸ�����) : ");
	scanf("%s", a->name);
}
void player_default(Player* a)
{
	//�⺻�� ����
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
	//�⺻ ������ ����
	a->inventory.Ammo = 60;
	a->inventory.Stimpack = 3;
}
void player_print_special(Player* a)
{
	draw_interface();
	gotoxy(5, 2);
	printf("%s�� SPECIAL", a->name);
	gotoxy(5, 4);
	printf("1.Strength(��)		| %.0f", a->SPECIAL[0]);
	gotoxy(5, 5);
	printf("2.Perception(������)	| %.0f", a->SPECIAL[1]);
	gotoxy(5, 6);
	printf("3.Endurance(������)	| %.0f", a->SPECIAL[2]);
	gotoxy(5, 7);
	printf("4.Charisma(�ŷ�)		| %.0f", a->SPECIAL[3]);
	gotoxy(5, 8);
	printf("5.Intelligence(����)	| %.0f", a->SPECIAL[4]);
	gotoxy(5, 9);
	printf("6.Agility(��ø��)		| %.0f", a->SPECIAL[5]);
	gotoxy(5, 10);
	printf("7.Luck(��)			| %.0f", a->SPECIAL[6]);
}
void player_print_special_info(int choice)
{
	gotoxy(5, 5);
	switch (choice)
	{
	case 1:
		printf("[���� ���� ���ѿ� ������ �ݴϴ�.] (�ִ� 10)");
		break;
	case 2:
		printf("[�������� ���߷��� ������ �ݴϴ�.] (�ִ� 10)");
		break;
	case 3:
		printf("[�������� ü�¿� ������ �ݴϴ�.] (�ִ� 10)");
		break;
	case 4:
		printf("[�ŷ��� ȭ���� ������ �ݴϴ�.] (�ִ� 10)");
		break;
	case 5:
		printf("[������ ����ġ ȹ�淮�� ������ �ݴϴ�.] (�ִ� 10)");
		break;
	case 6:
		printf("[��ø���� �׼�����Ʈ�� ������ �ݴϴ�.] (�ִ� 10)");
		break;
	case 7:
		printf("[���� �������� � ������ �ݴϴ�.] (�ִ� 10)");
		break;
	}
	//getch();
}
void player_set_result(Player* a)
{
	gotoxy(5, 10);
	printf("�ɷ�ġ ������ �Ϸ� �Ǿ����ϴ�.");
	gotoxy(5, 13);
	printf("��Ʈ 13 ������, 9mm �ǽ���, ź�� 60��, ������ 3�� ����"); getch();
	a->Carry += 10 * a->SPECIAL[0];
	a->Accuracy += 5 * a->SPECIAL[1];
	a->HP += 5 * a->SPECIAL[2];
	a->Talk += 1 * a->SPECIAL[3];
	a->Intel += 0.1 * a->SPECIAL[4]; 
	a->AP += a->SPECIAL[5];
	a->Luck += 2 * a->SPECIAL[6];
	a->level = 1;
	draw_interface();
	gotoxy(5, 2); printf("����� �������� ����� ��Ʈ13�� �������Դϴ�.");
	gotoxy(5, 4); printf("����� �Ҽӵ� ��Ʈ13�� ���� �� ��ȭ�� ���� �ٽ� Ĩ�� ���峵���ϴ�.");
	gotoxy(5, 6); printf("��Ʈ 13�� �������� �����þ�� ��ſ��� ��Ʈ 15�� ����");
	gotoxy(5, 8); printf("����Ĩ�� ���ؿ� ���� ���߽��ϴ�."); getch();
}
void player_set(Player* a)
{
	player_getname(a);
	int point = 10; int choice, dchoice, delta;
	player_default(a);
	while (1)
	{
		gotoxy(5, 4);
		player_print_special(a); //�� ���� ���
		gotoxy(5, 12);
		printf("[��� ���� ����Ʈ : %d ]", point);
		gotoxy(5, 14);
		printf("[��ȣ ����] (0 : ����) : ");
		scanf("%d", &choice);
		draw_interface();
		if (choice == 0 && point != 0) {
			gotoxy(5, 7);
			printf("��� ����Ʈ�� �� ������ּ���.");
			getch();
			continue;
		}
		else if (choice == 0 && point == 0) {
			gotoxy(5, 7);
			printf("[Ư�� ������ ��ġ�ڽ��ϱ�?] (0: Ȯ�� 1: �ƴϿ�) : ");
			scanf("%d", &dchoice);
			if (dchoice == 0)
				break;
			else {
				gotoxy(5, 9);
				printf("[������ ����մϴ�.]");
				getch();
				continue;
			}
		}
		if (choice >= 1 && choice <= 7)
		{
			player_print_special_info(choice);
			gotoxy(5, 3);
			printf("[+/- ���� �Է����ּ���] (0 : �ڷΰ���) : ");
			scanf("%d", &delta);
			if (delta == 0)
				continue;
			else if (point - delta < 0) //����Ʈ���� ��Ÿ�� �� ���� ��
			{
				gotoxy(5, 7);
				printf("[����Ʈ�� �����մϴ�]");
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
				printf("[SPECIAL�� 10���� Ŭ ���� �����ϴ�]");
				getch();
			}
			else if (a->SPECIAL[choice - 1] + delta < 1)
			{
				gotoxy(5, 7);
				printf("[SEPCIAL�� 1���� ���� �� �����ϴ�]");
				getch();
			}
		}
		else {
			gotoxy(5, 7);
			printf("[�Է��� �ùٸ��� ����]");
			getch();
		}
	}
	player_set_result(a);
	draw_interface();
}
void player_ingame_info(Player* a)
{
	int maxhp = a->SPECIAL[2] * 5 + 30; //�⺻ �ִ� ü��
	gotoxy(84, 2);
	printf("�� : %s", a->name);
	gotoxy(84, 4);
	printf("HP : [%d / %d]", maxhp, a->HP);
	gotoxy(84, 5);
	printf("ź�� : [%d]", a->inventory.Ammo);
	gotoxy(84, 6);
	printf("���ݷ� : [%d]", a->damage);
	gotoxy(84, 7);
	printf("������ : [%d]", a->inventory.Stimpack);
	gotoxy(84, 8);
	printf("����ġ : [%d EXP]", a->EXP);
	gotoxy(84, 9);
	printf("���� : [%d]", a->level);
	gotoxy(84, 10);
	printf("�� : [%d / %d]", a->Carry, a->inventory.Ammo + a->inventory.Stimpack);
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
		remove_player(oldx, oldy); // ������ ��ġ�� X �� �����
		put_player(newx, newy); // ���ο� ��ġ���� X �� ǥ���Ѵ�.
		oldx = newx; // ������ ��ġ�� ����Ѵ�.
		oldy = newy;
		//move_flag = 0; // 1:��� �̵�, 0:��ĭ�� �̵�
	}
	if (MAP[oldy - 1][oldx - 2] >= 3 && MAP[oldy - 1][oldx - 2] <= 7)
	{
		gotoxy(84, 14); textcolor(WHITE, BLACK); printf("\a����");
		Sleep(500); gotoxy(84, 14); printf("     ");
		textcolor(GREEN, BLACK);

		MAP[oldy - 1][oldx - 2] = 0; //�����ǿ��� �����, 0���� ����
		LEFTMONSTERS[STAGENUMBER]--; //0�� �������� �����Ǿ��� ���� ����
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
		printf("������ ���");
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
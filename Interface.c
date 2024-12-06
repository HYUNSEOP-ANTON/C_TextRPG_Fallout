#include "Interface.h"
//106 x 25 ũ��
void cls(int bg_color, int text_color)
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}
void gotoxy(int x, int y) //���� ���ϴ� ��ġ�� Ŀ�� �̵�
{
	COORD pos; // Windows.h �� ����
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void removeCursor(void) 
{ // Ŀ���� �Ⱥ��̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void draw_box(int x1, int y1, int x2, int y2, const char* ch)
{
	int x, y;
	for (x = x1; x <= x2; x += 2) {
		gotoxy(x, y1);
		printf(ch);
		gotoxy(x, y2);
		printf(ch);
	}
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y);
		printf(ch);
		gotoxy(x2, y);
		printf(ch);
	}
}
void draw_interface(void)
{
	cls(BLACK, GREEN);
	removeCursor();
	draw_box(0, 0, 78, 24, "��");
	draw_box(80, 0, 104, 24, "��");
}
void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}
void intro(void)
{
	draw_interface();
	gotoxy(35, 7);
	printf("VAULT 13");
	gotoxy(25, 10);
	printf("�����Ϸ��� �ƹ�Ű�� ��������.");
	getch();
}
void put_player(int x, int y)
{
	gotoxy(x, y);
	printf("A");
}
void remove_player(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}
//ó�� ���� ����
void firststage()
{
	gotoxy(10, 5);
	printf("������ ���� �� ���� �Ŵ��� ��Ʈ13�� ���� ���Ƚ��ϴ�.");
	gotoxy(10, 7);
	printf("����� ������ ���� ������ �������մϴ�.");
	getch();
	gotoxy(10, 9);
	printf("�������� ������ Ŀ�� �������� ������ �ֽ��ϴ�.");
	gotoxy(10, 11);
	printf("��� ������ �� ��ƾ� ������ �� ���� �� �����ϴ�.");
	getch();
}
void stage(int MAP[MAPHEIGHT][MAPWIDTH]) //���� �� �׸��� �Լ�
{
	//#define MAPWIDTH 40
	//#define MAPHEIGHT 25
	int x, y, i; //[21][72] ���� �������̽� ������ �Ѱ�
	i = 1;
	gotoxy(2, i);
	for (y = 0; y < MAPHEIGHT; y++) { //��������.
		for (x = 0; x < MAPWIDTH; x++) {
			if (MAP[y][x] == 0) //������ �Ѿ��
			{
				printf(" ");
			}
			else if (MAP[y][x] == 3)
				printf("S");
			else if (MAP[y][x] == 4)
				printf("R");
			else if (MAP[y][x] == 5)
				printf("G");
			else if (MAP[y][x] == 6)
				printf("M");
			else if (MAP[y][x] == 7)
				printf("B");
			else
				continue;
		}
		i++;
		gotoxy(2, i);
	}
}
//���� ������ �Ѿ�� �Լ�
void nextstage(int i)
{
	switch (i)
	{
	case 0:
		draw_interface();
		gotoxy(10, 5);
		printf("����� ������ �������� ��Ʈ 15�� ���մϴ�.");
		gotoxy(10, 7);
		printf("ó�� ���� �޺��� ��� ���� �־����ϴ�.");
		gotoxy(10, 9);
		printf("�� �ָ� Ȳ�������� ��Ż�� �ϻ�� ���̴��� �������ϴ�.");
		getch();
		break;
	case 1:
		draw_interface();
		gotoxy(10, 5);
		printf("�� �ָ� ��Ʈ 15�� ǥ������ ���Դϴ�.");
		gotoxy(10, 7);
		printf("���� �������� ����� �߻� ������ �������ϴ�.");
		getch();
		break;
	case 2:
		draw_interface();
		gotoxy(10, 5);
		printf("��Ʈ 15�Ա��� �����߽��ϴ�. ���η� �����߽��ϴ�.");
		gotoxy(10, 7);
		printf("�๰�� ���� �����ϰ� ���� ���� ���� ����Ʈ���� �����մϴ�");
		gotoxy(10, 9);
		printf("�̵��� ����� ������ ����ȭ �Ǿ��ֽ��ϴ�.");
		getch();
		break;
	case 3:
		draw_interface();
		gotoxy(10, 5);
		printf("����Ĩ�� �����ϴ� ��Ʈ 15�� ��ȭ �ü��� �����߽��ϴ�.");
		gotoxy(10, 7);
		printf("�Ŵ��� ����Ʈ �Ѹ����� ��ȭ�ü��� ��Ű�� �ֽ��ϴ�.");
		gotoxy(10, 9);
		printf("������ ���̴� �� ����Ʈ�� ������ ���ƺ��Դϴ�.");
		getch();
		break;
	case 4:
		draw_interface();
		gotoxy(10, 5);
		printf("����Ʈ�� ����ġ�� ��ȭ �ü� ���η� ���Խ��ϴ�.");
		gotoxy(10, 7);
		getch();
		printf("����Ĩ�� �տ� �־����ϴ�.");
		getch();
		break;
	default:
		break;
	}
}
//���� �Լ�
void ending()
{
	draw_interface();
	gotoxy(10, 5);
	printf("��Ʈ 13���� ���ƿ� ��ȭ �ü��� ����Ĩ�� ��ü�߽��ϴ�.");
	gotoxy(10, 7);
	printf("��ȭ �ü��� �ٽ� �۵��մϴ�.");
	gotoxy(10, 9);
	printf("����� ��Ʈ13�� ����� ���� ���߽��ϴ�.\a");
	getch();

	draw_interface();
	gotoxy(10, 10);
	printf("END");
	gotoxy(0, 27);
}
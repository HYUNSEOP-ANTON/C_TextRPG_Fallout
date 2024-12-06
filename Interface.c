#include "Interface.h"
//106 x 25 크기
void cls(int bg_color, int text_color)
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);
}
void gotoxy(int x, int y) //내가 원하는 위치로 커서 이동
{
	COORD pos; // Windows.h 에 정의
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void removeCursor(void) 
{ // 커서를 안보이게 한다
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
	draw_box(0, 0, 78, 24, "□");
	draw_box(80, 0, 104, 24, "□");
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
	printf("시작하려면 아무키나 누르세요.");
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
//처음 게임 서사
void firststage()
{
	gotoxy(10, 5);
	printf("열리지 않을 것 같던 거대한 볼트13의 문이 열렸습니다.");
	gotoxy(10, 7);
	printf("당신은 동굴을 지나 밖으로 나가야합니다.");
	getch();
	gotoxy(10, 9);
	printf("방사능으로 몸집이 커진 전갈들이 동굴에 있습니다.");
	gotoxy(10, 11);
	printf("모든 전갈을 다 잡아야 움직일 수 있을 것 같습니다.");
	getch();
}
void stage(int MAP[MAPHEIGHT][MAPWIDTH]) //게임 맵 그리는 함수
{
	//#define MAPWIDTH 40
	//#define MAPHEIGHT 25
	int x, y, i; //[21][72] 기존 인터페이스 있을떄 한거
	i = 1;
	gotoxy(2, i);
	for (y = 0; y < MAPHEIGHT; y++) { //문제없음.
		for (x = 0; x < MAPWIDTH; x++) {
			if (MAP[y][x] == 0) //다음맵 넘어가는
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
//다음 맵으로 넘어가는 함수
void nextstage(int i)
{
	switch (i)
	{
	case 0:
		draw_interface();
		gotoxy(10, 5);
		printf("당신은 동굴을 빠져나와 볼트 15로 향합니다.");
		gotoxy(10, 7);
		printf("처음 보는 햇빛에 잠시 눈이 멀었습니다.");
		gotoxy(10, 9);
		printf("저 멀리 황무지에서 약탈을 일삼는 레이더를 만났습니다.");
		getch();
		break;
	case 1:
		draw_interface();
		gotoxy(10, 5);
		printf("저 멀리 볼트 15의 표지판이 보입니다.");
		gotoxy(10, 7);
		printf("방사능 피폭으로 부폐된 야생 구울을 만났습니다.");
		getch();
		break;
	case 2:
		draw_interface();
		gotoxy(10, 5);
		printf("볼트 15입구에 도착했습니다. 내부로 진입했습니다.");
		gotoxy(10, 7);
		printf("약물로 인해 끔찍하게 변한 지능 낮은 뮤턴트들이 존재합니다");
		gotoxy(10, 9);
		printf("이들은 계급을 가지고 군대화 되어있습니다.");
		getch();
		break;
	case 3:
		draw_interface();
		gotoxy(10, 5);
		printf("워터칩이 존재하는 볼트 15의 정화 시설에 도착했습니다.");
		gotoxy(10, 7);
		printf("거대한 뮤턴트 한마리가 정화시설을 지키고 있습니다.");
		gotoxy(10, 9);
		printf("리더로 보이는 이 뮤턴트는 지능이 높아보입니다.");
		getch();
		break;
	case 4:
		draw_interface();
		gotoxy(10, 5);
		printf("뮤턴트를 물리치고 정화 시설 내부로 들어왔습니다.");
		gotoxy(10, 7);
		getch();
		printf("워터칩을 손에 넣었습니다.");
		getch();
		break;
	default:
		break;
	}
}
//엔딩 함수
void ending()
{
	draw_interface();
	gotoxy(10, 5);
	printf("볼트 13으로 돌아와 정화 시설의 워터칩을 교체했습니다.");
	gotoxy(10, 7);
	printf("정화 시설이 다시 작동합니다.");
	gotoxy(10, 9);
	printf("당신은 볼트13을 위기로 부터 구했습니다.\a");
	getch();

	draw_interface();
	gotoxy(10, 10);
	printf("END");
	gotoxy(0, 27);
}
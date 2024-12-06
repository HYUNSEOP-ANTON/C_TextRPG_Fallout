#ifndef Interface_h
#define Interface_h
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 78 
#define HEIGHT 24

#define MAPWIDTH 76
#define MAPHEIGHT 23

#define BLACK 0
#define GREEN 10
#define WHITE 15
#define RED 4

#define ME 'A'
#define SCORPION 'S'
#define BLANK	'  '

#define UP		'w'
#define DOWN	's'
#define LEFT	'a'
#define RIGHT	'd'
#define STIMPACK 't'

//시스템
void cls(int bg_color, int text_color);
void gotoxy(int x, int y);
void removeCursor(void);
void draw_box(int x1, int y1, int x2, int y2, const char* ch);
void draw_interface(void);
void textcolor(int fg_color, int bg_color);
//인트로
void intro(void);
//사용자 관련
void put_player(int x, int y);
void remove_player(int x, int y);
//처음 게임 서사
void firststage();
void stage(int MAP[MAPHEIGHT][MAPWIDTH]);
//다음 맵으로 넘어가는 함수
void nextstage(int i);
//엔딩 함수
void ending();
#endif
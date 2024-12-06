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

//�ý���
void cls(int bg_color, int text_color);
void gotoxy(int x, int y);
void removeCursor(void);
void draw_box(int x1, int y1, int x2, int y2, const char* ch);
void draw_interface(void);
void textcolor(int fg_color, int bg_color);
//��Ʈ��
void intro(void);
//����� ����
void put_player(int x, int y);
void remove_player(int x, int y);
//ó�� ���� ����
void firststage();
void stage(int MAP[MAPHEIGHT][MAPWIDTH]);
//���� ������ �Ѿ�� �Լ�
void nextstage(int i);
//���� �Լ�
void ending();
#endif
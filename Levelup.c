#include "Levelup.h"

int PERKLIST[9] = { 1,1,3,2,1,3,1,1,1 };

void selete_perk(Player* a, int b) {
    switch (b) {
    case 1:
        if (PERKLIST[0] > 0) {
            a->SPECIAL[2] += 2;
            PERKLIST[0]--;
        }
        break;
    case 2:
        if (PERKLIST[1] > 0) {
            a->damage += 1;
            PERKLIST[1]--;
        }
        break;
    case 3:
        if (PERKLIST[2] > 0) {
            a->Accuracy += 3;
            PERKLIST[2]--;
        }
        break;
    case 4:
        if (PERKLIST[3] > 0) {
            a->inventory.Ammo += 20;
            PERKLIST[3]--;
        }
        break;
    case 5:
        if (PERKLIST[4] > 0) {
            a->SPECIAL[6]++;
            a->Luck += 2;
            PERKLIST[4]--;
        }
        break;
    case 6:
        if (PERKLIST[5] > 0) {
            a->inventory.Stimpack += 10;
            PERKLIST[5]--;
        }
        break;
    case 7:
        if (PERKLIST[6] > 0) {
            a->SPECIAL[5]++;
            a->AP += 3;
            PERKLIST[6]--;
        }
        break;
    case 8:
        if (PERKLIST[7] > 0) {
            a->Accuracy = 100;
            PERKLIST[7]--;
        }
        break;
    case 9:
        if (PERKLIST[8] > 0) {
            a->damage += 7;
            PERKLIST[8]--;
        }
        break;
    default:
        break;
    }
}

void levelup_print(int a, Player* b) {
    int selete;
    if (a < 6) {
        if (PERKLIST[0] > 0) {
            gotoxy(5, 8);
            printf("1. 체력은 국력 - 체력이 10만큼 늘어납니다.");
        }
        if (PERKLIST[1] > 0) {
            gotoxy(5, 9);
            printf("2. 철갑탄 사용 - 탄약의 교체로 대미지 + 1");
        }
        if (PERKLIST[2] > 0) {
            gotoxy(5, 10);
            printf("3. 사격술 연습 - 명중률 3%% 증가");
        }
        if (PERKLIST[3] > 0) {
            gotoxy(5, 11);
            printf("4. 보급 - 탄약 20발 획득");
        }
    }
    if (a >= 2) {
        if (PERKLIST[4] > 0) {
            gotoxy(5, 12);
            printf("5. 네잎 클로버 - LUCK +1 증가");
        }
        if (PERKLIST[5] > 0) {
            gotoxy(5, 13);
            printf("6. 의무병이 필요해 - 스팀팩 10개가 추가됩니다");
        }
        if (PERKLIST[6] > 0) {
            gotoxy(5, 14);
            printf("7. 닌자 - 민첩 + 1 (AP +3) 증가합니다.");
        }
    }
    if (a >= 3) {
        if (PERKLIST[7] > 0) {
            gotoxy(5, 15);
            printf("8. Bull's EYE - 모든 공격이 명중합니다.");
        }
        if (PERKLIST[8] > 0) {
            gotoxy(5, 16);
            printf("9. 총기 개조 - 총몸 개조로 더욱 강해집니다.");
        }
    }
    gotoxy(5, 22);
    printf("번호 선택 : ");
    scanf("%d", &selete);
    selete_perk(b, selete);
}

void islevelup(Player* a) {
    int isit = a->EXP;
    int playerlevel = a->level;
    if (isit >= 1500) {
        draw_interface();
        gotoxy(5, 3);
        printf("레벨업");
        Sleep(500);
        gotoxy(5, 5);
        printf("지속적인 전투로 노하우를 습득 했습니다.");
        gotoxy(5, 6);
        printf("레벨업 특성을 선택해주세요.");
        getch();
        levelup_print(playerlevel, a);
        a->EXP -= 1500;
        a->level += 1;
        a->HP = a->SPECIAL[2] * 5 + 30;
    }
    else
        return;
}
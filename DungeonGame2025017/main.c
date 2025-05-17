//
//  main.c
//  DungeonGame2025017
//
//  Created by 박준하 on 5/17/25.
//
//▪ 실습: 던전 게임
//▪ 던전 게임은 간단한 콘솔 기반 게임으로, 사용자가 던전을 탐험하면서 몬
//스터를 만나고 보물을 찾는 내용을 담고 있다.
//▪ 게임은 3×3 크기의 던전 맵을 사용하여 구현되었다. 던전 맵은 공백으로
//표시된 빈 공간(' '), 몬스터('M'), 그리고 보물('T')로 구성되어 있다. 플레
//이어는 캐릭터를 나타내는 'P'로 표시된다.
//- 2차원 배열 활용 예제

#include <stdio.h>
#include <stdlib.h>
// 던전 크기 상수
#define DUNGEON_SIZE 3
// 게임 메인 함수
int main(void) {
    // 던전 맵 배열 초기화
    char dungeon[DUNGEON_SIZE][DUNGEON_SIZE] = {
        {' ',' ','M'},
        {' ',' ',' '},
        {' ',' ','T'}
    };
    // 캐릭터 초기 위치
    int playerX = 0;
    int playerY = 0;
    
    // 게임 루프
    while (1) {
        system("cls");
        // 던전 맵 출력
        for (int i = 0; i < DUNGEON_SIZE; i++) {
            for (int j = 0; j < DUNGEON_SIZE; j++) {
                if (i == playerY && j == playerX) {
                    printf("P ");
                }
                else {
                    printf("%c "
                           , dungeon[i][j]);
                }
            }
            printf("\n");
        }
        // 몬스터가 있는지 확인
        int monsters = 0;
        if (playerX > 0 && dungeon[playerY][playerX - 1] == 'M')
            monsters++; // 왼쪽
        if (playerX < DUNGEON_SIZE - 1 && dungeon[playerY][playerX + 1] == 'M')
            monsters++; // 오른쪽
        if (playerY > 0 && dungeon[playerY - 1][playerX] == 'M')
            monsters++; // 위
        if (playerY < DUNGEON_SIZE - 1 && dungeon[playerY + 1][playerX] == 'M')
            monsters++; // 아래
        if (monsters > 0) {
            printf("주변에 %d마리의 몬스터가 있습니다!\n", monsters);
        }
        // 보물 발견 여부 확인
        if (dungeon[playerY][playerX] == 'T') {
            printf("보물을 발견했습니다! 게임을 종료합니다.\n");
            break;
        }
        // 이동 입력 받기
        char move;
        printf("이동할 방향을 선택하세요 (w: 위, s: 아래, a: 왼쪽, d: 오른쪽): ");
        scanf(" %c", &move);
        // 캐릭터 이동
        switch (move) {
            case 'w':
                if (playerY > 0) playerY--; case 's':
                if (playerY < DUNGEON_SIZE - 1) playerY++; case 'a':
                if (playerX > 0) playerX--; case 'd':
                if (playerX < DUNGEON_SIZE - 1) playerX++; default:
                break;
                break;
                break;
                break;
                printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}

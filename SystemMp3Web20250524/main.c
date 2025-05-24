//
//  main.c
//  SystemMp3Web20250524
//
//  Created by 박준하 on 5/24/25.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    while (1) {
        printf("\n메뉴를 선택하세요:\n");
        printf("1. MP3 파일 재생\n");
        printf("2. 구글 열기\n");
        printf("입력: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // 최성이형 미안.. 교수가 mp3 받아오래
                system("open /Users/junha/Desktop/jjunhaa/C학습/CVA/SystemMp3Web20250524/RainbowRanger.mp3");
                break;
            case 2:
                system("open https://www.google.com");
                break;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}

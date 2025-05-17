//
//  main.c
//  ThrowingTheDice2025017
//
//  Created by 박준하 on 5/17/25.
//
//
//▪ 예제: 주사위 던지기
//▪ 주사위를 던져서 각 면이 나오는 횟수를 출력하여 보자.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

int main(void) {
    int freq[SIZE] = { 0 };
    int i;
    
    srand(time(NULL)); // 난수처리
    
    for(i=0; i < 1000; i++) {
        ++freq[rand() % 6];
    }
    
    printf("====================\n");
    printf("면 빈도\n");
    printf("====================\n");
    
    for(i = 0; i< SIZE; i++) {
        printf("%3d   %3d \n", i+1, freq[i]);
    }
    
    return 0;
}

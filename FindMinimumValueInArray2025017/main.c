//
//  main.c
//  FindMinimumValueInArray2025017
//
//  Created by 박준하 on 5/17/25.
//

//▪ 실습: 배열에서 최소값 찾기
//▪ 배열에 저장된 값들의 최댓값이나 최솟값을 어떻게 계산하는지를 생각해
//보자.
//▪ 인터넷에서 특정한 상품(예를 들어서 TV)을 구입하고자 한다. 여러 인터
//넷 사이트에서 판매되는 가격이 1차원 배열 prices[]에 저장되어 있다고
//가정하자. 어떻게 하면 최소 가격으로 상품을 구입할 수 있을까?

#include <stdio.h>
#define SIZE 10

int main(void) {
    int s[SIZE] = { 12, 3, 19, 6, 18, 8, 12, 4, 1, 19 };
    int i, minimum;
    minimum = s[0];
    for (i = 1; i < SIZE; i++) {
        if (s[i] < minimum) {
            minimum = s[i];
        }
    }
    printf("최소값은 %d입니다.\n", minimum);
    return 0;
}

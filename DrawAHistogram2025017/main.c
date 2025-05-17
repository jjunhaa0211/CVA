//
//  main.c
//  DrawAHistogram2025017
//
//  Created by 박준하 on 5/17/25.
//

//▪ 예제: 히스토그램 그리기
//▪ 배열에 데이터가 들어 있다고 가정하고 데이터의 값에 따라서 막대그래
//프를 그려보자. 막대 그래프는 그래픽을 사용하는 것은 아니고 별표(*)를
//값에 비례하여 그려준다.

#include <stdio.h>
#define SIZE 10
int main(void)
{
    int n[SIZE] = { 12, 3, 19, 6, 18, 8, 12, 4, 1, 19 };
    int i, j;
    printf("요소 값 히스토그램 \n");
    for (i = 0; i < SIZE; ++i)
    {
        printf("%d %d "
               , i, n[i]);
        for (j = 1; j <= n[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

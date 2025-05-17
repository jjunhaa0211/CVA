//
//  main.c
//  GetPopularVoteResults20250172025017
//
//  Created by 박준하 on 5/17/25.
//

//실습: 인기 투표 결과 구하기
//▪ 0명의 연예인에 대하여 인기투표를 하고 투표 결과를 컴퓨터를 이용하여
//서 집계한다고 가정하자.
//▪ 이것은 데이터의 빈도(frequency)를 계산하는 것과 동일하다.

#include <stdio.h>
#define SIZE 11
int main(void)
{
    int freq[SIZE] = { 0 }; int i, candidate;
    while(1)
    {
        // 빈도를 나타내는 배열
        printf("몇 번 연예인을 선택하시겠습니까?(종료-1): ");
        scanf("%d", &candidate);
        if (candidate < 0) break; //음수이면 반복 종료
        freq[candidate]++;
    }
    printf("값 득표결과\n");
    for(i = 1; i < SIZE; i++)
        printf("%3d %3d \n", i, freq[i]);
    return 0;
}

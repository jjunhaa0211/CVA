//
//  main.c
//  TheaterReservationSystem2025017
//
//  Created by 박준하 on 5/17/25.
//

//실습: 극장 예약 시스템
//▪ 배열을 이용하여 간단한 극장 예약 시스템을 작성
//▪ 좌석은 10개
//▪ 먼저 좌석 배치표를 보여준다.
//▪ 예약이 끝난 좌석은 1로, 예약이 안 된 좌석은 0으로 나타낸다.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6
int main(void) {
    int seat_number, i;
    int seats[SIZE] = { 0 };
    
    while(1) {
        printf("-------------------------------\n");
        printf(" 1 2 3 4 5 6 7 8 9 10\n");
        printf("-------------------------------\n");
        for(i = 0; i < SIZE; i++) {
            printf(" %d",seats[i]);
        }
        printf("\n");
        printf("원하시는 좌석번호를 입력하세요(종료는 -1): ");
        scanf("%d", &seat_number);
        
        if(seat_number < 0) {
            break;
        }
        
        if(seat_number <= 0 || seat_number > SIZE) {
            printf("1부터 10사이의 숫자를 입력하세요\n");
        }
        
        if(seats[seat_number-1]==0) {
            seats[seat_number-1] = 1;
            printf("예약되었습니다.\n\n");
        } else {
            printf("이미 예약되었습니다.");
        }
    }
    return 0;
}

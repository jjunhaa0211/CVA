//
//  main.c
//  pointer202505311
//
//  Created by 박준하 on 5/31/25.
//

#include <stdio.h>

int main() {
    int x = 5;          // 정수 변수
    int *p = &x;        // x의 주소를 담는 int형 포인터
    char *c = (char *)&x; // x의 주소를 char 포인터로 캐스팅

    printf("x = %d\n", x);            // x 값 출력
    printf("*p = %d\n", *p);          // 포인터 p가 가리키는 값
    printf("p = %p\n", (void *)p);    // 포인터 p 주소 출력
    printf("c = %p\n", (void *)c);    // 포인터 c 주소 출력
    printf("*c = %d\n", *c);          // x의 가장 낮은 바이트 값 (char로 해석한 값)

    return 0;
}

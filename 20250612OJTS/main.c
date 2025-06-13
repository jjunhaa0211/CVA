//
//  main.c
//  20250612OJTS
//
//  Created by 박준하 on 6/12/25.
//

#include <stdio.h>

int main() {
    int x,y,d = 10; // 10으로 시작함
    int *pd = &d; // pd는 d의 주소를 가리킴
    
    x = (int)(*pd); // x가 d의 10 값를 가지고 있음
    y = (int)++(*pd); // 전위로 y가 가지고 있는 d의 값에 +1이 붙음
    
    printf("(x-y) = %d \n", (y - x)); // x-y는 11 - 10과 동일함
    
    return 0;
}

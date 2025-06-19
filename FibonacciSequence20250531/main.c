//
//  main.c
//  FibonacciSequence20250531
//
//  Created by 박준하 on 5/31/25.
//

#include <stdio.h>

int fibonacci(int n) {
    static int memo[100] = {0};

    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;

    printf("피보나치 수열의 위치를 입력하세요: ");
    scanf("%d", &n);

    printf("%d번째 피보나치 수는 %d입니다.\n", n, fibonacci(n));
    return 0;
}

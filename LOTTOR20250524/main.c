//
//  main.c
//  LOTTOR20250524
//
//  Created by 박준하 on 5/24/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 45
#define COUNT 6

int main() {
    int lotto[COUNT];
    int i, j, num;
    srand(time(NULL));

    for (i = 0; i < COUNT; ) {
        num = rand() % MAX + 1;
        int dup = 0;
        for (j = 0; j < i; ++j) {
            if (lotto[j] == num) {
                dup = 1;
                break;
            }
        }
        if (!dup) {
            lotto[i] = num;
            ++i;
        }
    }

    
    for (i = 0; i < COUNT - 1; ++i) {
        for (j = 0; j < COUNT - i - 1; ++j) {
            if (lotto[j] > lotto[j + 1]) {
                int temp = lotto[j];
                lotto[j] = lotto[j + 1];
                lotto[j + 1] = temp;
            }
        }
    }

    
    printf("🎰 이번 주 로또 번호: ");
    for (i = 0; i < COUNT; ++i) {
        printf("%2d ", lotto[i]);
    }
    printf("\n");

    return 0;
}

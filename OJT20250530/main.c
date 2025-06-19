//
//  main.c
//  OJT20250530
//
//  Created by 박준하 on 5/30/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    if ((fp = fopen("test.txt", "w")) == NULL) {
        fprintf(stderr, "test.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    fprintf(fp, "나는 한국공학대학교학교 일학습병행학과 정보통신기술공학과 박준하입니다!");

    fclose(fp);
    return 0;
}

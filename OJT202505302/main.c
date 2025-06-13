//
//  main.c
//  OJT202505302
//
//  Created by 박준하 on 5/30/25.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;

    if ((fp = fopen("test.txt", "a")) == NULL) {
        fprintf(stderr, "test.txt 파일을 열 수 없습니다.\n");
        return 1;
    }

    fprintf(fp, "\n나는 하이지노의 제조DX팀에서 일하고 있습니다.");

    fclose(fp);
    return 0;
}

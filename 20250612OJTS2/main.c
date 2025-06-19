//
//  main.c
//  20250612OJTS2
//
//  Created by 박준하 on 6/12/25.
//

#include <stdio.h>

#define STUDENTS 4
#define NAME_LEN 20

typedef struct {
    int  s_id;              // 학번
    char s_name[NAME_LEN];  // 성명
    int  s_age;             // 나이
} Student;

int main(void)
{
    Student st[STUDENTS];

    /* 정보 입력 */
    for (int i = 0; i < STUDENTS; ++i) {
        printf("[%d번째 학생]\n", i + 1);
        printf("  학번 : ");  scanf("%d", &st[i].s_id);
        printf("  성명 : ");  scanf("%19s", st[i].s_name);   // 공백 없는 이름 가정
        printf("  나이 : ");  scanf("%d", &st[i].s_age);
    }

    /* 정보 출력 */
    puts("\n=== 학생 정보 ===");
    printf("%-10s %-20s %-5s\n", "학번", "성명", "나이");
    for (int i = 0; i < STUDENTS; ++i)
        printf("%-10d %-20s %-5d\n",
               st[i].s_id, st[i].s_name, st[i].s_age);

    return 0;
}

////
////  main.c
////  20250613OJTHomeWork1
////
////  Created by 박준하 on 6/13/25.
////
//
//#include <stdio.h>
//
//void get_data(int score[], int size);
//void sorting_order(int score[], int size);
//
//int main() {
//    int score[10];
//    get_data(score, 10);
//    sorting_order(score, 10);
//
//    printf("정렬된 성적: ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", score[i]);
//    }
//    printf("\n");
//    return 0;
//}
//
//void get_data(int score[], int size) {
//    for (int i = 0; i < size; i++) {
//        do {
//            printf("%d번 학생 성적 입력 (0~100): ", i + 1);
//            scanf("%d", &score[i]);
//        } while (score[i] < 0 || score[i] > 100);
//    }
//}
//
//void sorting_order(int score[], int size) {
//    int temp;
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = i + 1; j < size; j++) {
//            if (score[i] > score[j]) {
//                temp = score[i];
//                score[i] = score[j];
//                score[j] = temp;
//            }
//        }
//    }
//}
#include <stdio.h>
#define PI 3.141592

double area_circle();
double area_triangle();
double area_rectangle();

int main() {
    int choice;
    double (*area_func)();

    do {
        printf("메뉴: 원(1), 삼각형(2), 사각형(3), 종료(0): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                area_func = area_circle;
                printf("도형의 종류: 원, 넓이: %.2f\n", area_func());
                break;
            case 2:
                area_func = area_triangle;
                printf("도형의 종류: 삼각형, 넓이: %.2f\n", area_func());
                break;
            case 3:
                area_func = area_rectangle;
                printf("도형의 종류: 사각형, 넓이: %.2f\n", area_func());
                break;
            case 0:
                printf("프로그램 종료\n");
                break;
            default:
                printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    } while (choice != 0);

    return 0;
}

double area_circle() {
    double radius;
    printf("반지름 입력: "); scanf("%lf", &radius);
    return PI * radius * radius;
}

double area_triangle() {
    double base, height;
    printf("밑변 입력: "); scanf("%lf", &base);
    printf("높이 입력: "); scanf("%lf", &height);
    return (base * height) / 2;
}

double area_rectangle() {
    double width, height;
    printf("가로 입력: "); scanf("%lf", &width);
    printf("세로 입력: "); scanf("%lf", &height);
    return width * height;
}

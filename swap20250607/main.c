//
//  main.c
//  swap20250607
//
//  Created by 박준하 on 6/7/25.
//

#include <stdio.h>
void move(int xpos, int ypos);

int main(int argc, const char * argv[]) {
    int x = 10;
    int y = 20;
    
    printf("현재의 위치 (%d, %d)\n",x,y);
    move(x,y);
    printf("현재의 위치 (%d, %d)\n",x,y);
    return 0;
}

void move(int xpos, int ypos) {
    xpos = xpos + 1;
    ypos = ypos + 1;
}

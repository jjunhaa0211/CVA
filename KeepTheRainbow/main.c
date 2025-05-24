#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>
#include <time.h>

/* ── 전역 설정 ────────────────────────────────────────── */
#define WIDTH   80
#define HEIGHT  30
#define FRAME_US            50000   // 0.05 s / frame
#define SPAWN_INTERVAL_FR   300     // 15 s
#define MONSTER_STEP_FR     18      // 몬스터 1칸 이동
#define MONSTER_MAX         200
#define PUSH_DISTANCE       2       // 피격 시 플레이어 밀림

/* ── ANSI 색 ─────────────────────────────────────────── */
#define C_RESET   "\033[0m"
#define C_PLAYER  "\033[1;33m"
#define C_SWORD   "\033[1;37m"
#define C_MONSTER "\033[1;31m"
#define C_ROCK    "\033[0;37m"

/* ── 전역 상태 ───────────────────────────────────────── */
char world[HEIGHT][WIDTH];          // '.' 또는 'R'
int  px = WIDTH / 2, py = HEIGHT / 2;   // 플레이어 위치
int  dir = 0;                           // 0→ 1← 2↑ 3↓
int  hpSeg = 6;                         // ♥♥♥ = 6 세그
int  killCount = 0;                     // 처치 수
char swordChar = '|';                   // 칼 문자

typedef struct { int x, y, alive; } Monster;
Monster mons[MONSTER_MAX];
int     monsCnt = 0;

/* ── 터미널 비정규 입력 ─────────────────────────────── */
void termInit(struct termios *o){ struct termios t; tcgetattr(0,o); t=*o; t.c_lflag&=~(ICANON|ECHO); tcsetattr(0,TCSANOW,&t);}
void termReset(struct termios *o){ tcsetattr(0,TCSANOW,o);}
int  kbhit(void){ struct timeval tv={0,0}; fd_set f; FD_ZERO(&f); FD_SET(0,&f); return select(1,&f,NULL,NULL,&tv);}
char getch_nb(void){ char c; read(0,&c,1); return c; }

/* ── 맵 ─────────────────────────────────────────────── */
void worldInit(void){ for(int r=0;r<HEIGHT;++r) for(int c=0;c<WIDTH;++c) world[r][c]='.'; }
void placeRocks(int cnt){
    while(cnt){ int x=rand()%WIDTH, y=rand()%HEIGHT;
        if(world[y][x]=='.' && !(x==px&&y==py) && !(x==px+1&&y==py)){ world[y][x]='R'; --cnt; }}}

/* ── 몬스터 ─────────────────────────────────────────── */
void addMonster(int x,int y){ if(monsCnt<MONSTER_MAX) mons[monsCnt++] = (Monster){x,y,1}; }
void spawnEdgeMonsters(void){
    for(int i=0;i<3;++i){
        int y=rand()%HEIGHT; if(world[y][WIDTH-2]=='.') addMonster(WIDTH-2,y);
        y=rand()%HEIGHT;     if(world[y][1]=='.')       addMonster(1,y); }}
void moveMonsters(void){
    for(int i=0;i<monsCnt;++i){
        if(!mons[i].alive) continue;
        int dx=px-mons[i].x, dy=py-mons[i].y;
        int nx=mons[i].x+(dx? (dx>0?1:-1):0);
        int ny=mons[i].y+(dy? (dy>0?1:-1):0);
        int tx=mons[i].x, ty=mons[i].y;
        if(abs(dx)>=abs(dy)){ if(world[mons[i].y][nx]=='.') tx=nx; else if(world[ny][mons[i].x]=='.') ty=ny; }
        else                { if(world[ny][mons[i].x]=='.') ty=ny; else if(world[mons[i].y][nx]=='.') tx=nx; }
        int clash=0;
        for(int j=0;j<monsCnt;++j) if(j!=i&&mons[j].alive&&mons[j].x==tx&&mons[j].y==ty){ clash=1; break; }
        if(!clash){ mons[i].x=tx; mons[i].y=ty; }}}

/* ── 전투 / 충돌 ───────────────────────────────────── */
int swordX(void){ return px + (dir==0?1:dir==1?-1:0);}
int swordY(void){ return py + (dir==3?1:dir==2?-1:0);}
int swordHits(int m)
{
    if (!mons[m].alive) return 0;

    int sx1 = swordX();          // 칼이 있는 칸
    int sy1 = swordY();
    int sx2 = sx1,  sy2 = sy1;   // 칼 앞 1칸

    /* 방향별로 2칸째 좌표 계산 */
    if (dir == 0)  sx2++;        // →
    else if (dir == 1) sx2--;    // ←
    else if (dir == 2) sy2--;    // ↑
    else if (dir == 3) sy2++;    // ↓

    return (mons[m].x == sx1 && mons[m].y == sy1) ||
           (mons[m].x == sx2 && mons[m].y == sy2);
}
int isAdjacent(int m){ int dx=abs(px-mons[m].x), dy=abs(py-mons[m].y); return mons[m].alive && (dx+dy==1 || (!dx&&!dy)); }
void killMonster(int m){ mons[m].alive=0; ++killCount; }
/* 2칸까지 밀림 */
void pushPlayer(int dx,int dy){
    for(int n=0;n<PUSH_DISTANCE;++n){
        int nx=px+(dx>0?1:dx<0?-1:0);
        int ny=py+(dy>0?1:dy<0?-1:0);
        if(nx<0||nx>=WIDTH||ny<0||ny>=HEIGHT||world[ny][nx]!='.') break;
        px=nx; py=ny; }}
void damagePlayer(int dx,int dy){
    if(--hpSeg<=0){ printf("\nGAME OVER | 처치 %d\n",killCount); exit(0);}
    pushPlayer(dx,dy); }

/* ── 출력 ─────────────────────────────────────────── */
void cls(void){ printf("\033[2J\033[1;1H"); }
void printHearts(void){
    for(int h=0;h<3;++h){ int s=hpSeg-h*2;
        printf("%s ", (s>=2)?"♥":(s==1)?"♡":"·"); }}
char frameSym(int i){
    static const char R[3]={'/','-','|'},
                      L[3]={'\\','-','|'},
                      U[3]={'|','|','|'},
                      D[3]={'|','|','|'};
    return (dir==0)?R[i]:(dir==1)?L[i]:(dir==2)?U[i]:D[i];}
void draw(void){
    cls(); printHearts(); printf("        잡은 몬스터: %d\n",killCount);
    int sx=swordX(), sy=swordY();
    for(int r=0;r<HEIGHT;++r){
        for(int c=0;c<WIDTH;++c){
            if(world[r][c]=='R'){ printf(C_ROCK "■" C_RESET); continue; }
            int done=0;
            for(int m=0;m<monsCnt;++m)
                if(mons[m].alive && mons[m].x==c && mons[m].y==r){ printf(C_MONSTER "M" C_RESET); done=1; break;}
            if(done) continue;
            if(c==px && r==py){ printf(C_PLAYER "@"); continue; }
            if(c==sx && r==sy){ printf(C_SWORD "%c" C_RESET,swordChar); continue; }
            putchar('.'); }
        putchar('\n'); }
    fflush(stdout);
    puts("WASD 이동 | J 공격 | Q 종료");
}

/* ── 메인 ───────────────────────────────────────────── */
int main(void){
    struct termios old; termInit(&old); srand(time(NULL));
    worldInit(); placeRocks(40); spawnEdgeMonsters();
    int moveT=0, spawnT=0; draw();

    while(1){
        if(kbhit()){
            char ch=getch_nb(); if(ch=='q'||ch=='Q') break;
            int nx=px, ny=py;
            if(ch=='w'||ch=='W'){ ny=(py>0)?py-1:py; dir=2; }
            if(ch=='s'||ch=='S'){ ny=(py<HEIGHT-1)?py+1:py; dir=3; }
            if(ch=='a'||ch=='A'){ nx=(px>0)?px-1:px; dir=1; }
            if(ch=='d'||ch=='D'){ nx=(px<WIDTH-2)?px+1:px; dir=0; }
            if(world[ny][nx]=='.'){ px=nx; py=ny; }

            /* ── 3-프레임 칼 애니메이션 & 즉시 타격 ── */
            if(ch=='j'||ch=='J'){
                for(int f=0; f<3; ++f){
                    swordChar = frameSym(f);
                    for(int m=0;m<monsCnt;++m)
                        if(swordHits(m)) killMonster(m);
                    draw(); usleep(100000);
                }
                swordChar = (dir<=1)?'|' : '-';
            }
            draw();
        }

        if(++moveT>=MONSTER_STEP_FR){
            moveT=0; moveMonsters();
            for(int m=0;m<monsCnt;++m)
                if(isAdjacent(m)) damagePlayer(px-mons[m].x, py-mons[m].y);
            draw();
        }
        if(++spawnT>=SPAWN_INTERVAL_FR){ spawnT=0; spawnEdgeMonsters(); draw();}
        usleep(FRAME_US);
    }
    termReset(&old);
    return 0;
}

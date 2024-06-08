//2048 using C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

int a[4][4];
int score=0;

int add(int x,int y){
    score=score+x+y;
    return x+y;
}

void start(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            a[i][j]=0;
        }
    }
}

void display(){
    printf("\nScore = %d\n",score);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}


int hasEmptySpace() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}


void insert(){
    if (!hasEmptySpace()) {
        return;
    }
    int r, s, ins;
    do {
        r = rand() % 4;
        s = rand() % 4;
        ins = rand() % 2;
    } while (a[r][s] != 0);
    a[r][s] = (ins == 0) ? 2 : 4;
    score=(ins==0)?score+2:score+4;
}


void slideLeft() {
    for (int i = 0; i < 4; i++) {
        int nextEmpty = 0;
        for (int j = 0; j < 4; j++) {
            if (a[i][j] != 0) {
                if (nextEmpty != j) {
                    a[i][nextEmpty] = a[i][j];
                    a[i][j] = 0;
                }
                nextEmpty++;
            }
        }
    }
}

void mergeLeft() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != 0 && a[i][j] == a[i][j + 1]) {
                a[i][j] = add(a[i][j], a[i][j + 1]);
                a[i][j + 1] = 0;
                j++;
            }
        }
    }
}

void left() {
    slideLeft();
    mergeLeft();
    slideLeft();
}


void slideRight() {
    for (int i = 0; i < 4; i++) {
        int nextEmpty = 3;
        for (int j = 3; j >= 0; j--) {
            if (a[i][j] != 0) {
                if (nextEmpty != j) {
                    a[i][nextEmpty] = a[i][j];
                    a[i][j] = 0;
                }
                nextEmpty--;
            }
        }
    }
}

void mergeRight() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (a[i][j] != 0 && a[i][j] == a[i][j - 1]) {
                a[i][j] = add(a[i][j], a[i][j - 1]);
                a[i][j - 1] = 0;
            }
        }
    }
}

void right() {
    slideRight();
    mergeRight();
    slideRight();
}

void slideUp() {
    for (int j = 0; j < 4; j++) {
        int nextEmpty = 0;
        for (int i = 0; i < 4; i++) {
            if (a[i][j] != 0) {
                if (nextEmpty != i) {
                    a[nextEmpty][j] = a[i][j];
                    a[i][j] = 0;
                }
                nextEmpty++;
            }
        }
    }
}

void mergeUp() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (a[i][j] != 0 && a[i][j] == a[i + 1][j]) {
                a[i][j] = add(a[i][j], a[i + 1][j]);
                a[i + 1][j] = 0;
            }
        }
    }
}

void up() {
    slideUp();
    mergeUp();
    slideUp();
}

void slideDown() {
    for (int j = 0; j < 4; j++) {
        int nextEmpty = 3;
        for (int i = 3; i >= 0; i--) {
            if (a[i][j] != 0) {
                if (nextEmpty != i) {
                    a[nextEmpty][j] = a[i][j];
                    a[i][j] = 0;
                }
                nextEmpty--;
            }
        }
    }
}

void mergeDown() {
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
            if (a[i][j] != 0 && a[i][j] == a[i - 1][j]) {
                a[i][j] = add(a[i][j], a[i - 1][j]);
                a[i - 1][j] = 0;
            }
        }
    }
}

void down() {
    slideDown();
    mergeDown();
    slideDown();
}

int canMove() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i][j] == 0) 
                return 1;
            if (j < 3 && a[i][j] == a[i][j + 1]) 
                return 1;
            if (i < 3 && a[i][j] == a[i + 1][j]) 
                return 1;
        }
    }
    return 0;
}




main(){
    char move,c;
    int cont=1;
    printf("Welcome to 2048\n");
    start();
    display();
    printf("Press any key to start: \n");
    getch();
   while(cont) {
            insert();
            display();
            printf("\n\nUse a,s,d,w to move\n");
            move = getch();
        switch(move){
            case 'a':
                left();
                break;
            case 'd':
                right();
                break;
            case 's':
                down();

                break;
            case 'w':
                up();
                break;
            case 'o':
                printf("Do you want to end: (y/n)");
                c=getch();
                if(c=='y'||c=='Y'){
                    printf("EXIT!!!");
                    cont=0;
                }else{
                    cont=1;
                }
                break;
            case 'A':
                left();
                break;
            case 'D':
                right();
                break;
            case 'S':
                down();

                break;
            case 'W':
                up();
                break;
            case 'O':
                printf("\nDo you want to end: (y/n)\n");
                c=getch();
                if(c=='y'||c=='Y'){
                    printf("\nEXIT!!!\n");
                    cont=0;
                }else{
                    cont=1;
                }
                break;
            default:
                printf("\nInvalid!\n");
                break;
        }
    
   }
    
}

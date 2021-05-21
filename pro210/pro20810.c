#include <stdio.h>
#include <string.h>

int input_int2(int max);
void star(int n);
void star2(int n);

int main (void){
    int i;
    int n;

    i = input_int2(10);
    star(i);

    for ( n = 0; n < i; n++){
        star2(i -2);
    }

    star(i);
    return 0;
}

int input_int2(int max){
    int n = max + 1;

    while (n > max){
        printf("%d以下の整数：", max);
        scanf("%d", &n);
    }
    return n;
}

void star(int n){
    int i;

    for ( i = 0; i < n; i++){
        printf("*");
    }
    printf("\n");
}

void star2(int n){
    int i;

    printf("*");

    for ( i = 0; i < n; i++){
        printf(" ");
    }
    printf("*");

    printf("\n");
}
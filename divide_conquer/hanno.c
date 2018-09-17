#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

// n blocks from x to z through y
void move(int n, char x, char y, char z) {
    if (n == 1) {
        cnt++;
        printf("[%d]: %c --> %c\n", cnt, x, z);
    } else {
        move(n - 1, x, z, y);
        cnt++;
        printf("[%d]: %c --> %c\n", cnt, x, z);
        move(n - 1, y, x, z);
    }
}

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Input format: ./hanno n\n");
        return -1;
    }
    int n = atoi(argv[1]);
    move(n, 'X', 'Y', 'Z');
    printf("Totally %d movements\n", cnt);
    return 0;
}

#include <stdio.h>

int factorial(int i) {
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Input format: ./factorial n\n");
        return -1;
    }
    int cnt = atoi(argv[1]);
    printf("%d\n", factorial(cnt));
    return 0;
}

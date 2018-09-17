#include <stdio.h>
#include <stdlib.h>

// this function should return the #i value in the fibonacci array
// don't need to consider every result of the recursion
// first think how we can get n, not the second from the first
// Recursion:
// 1. return conditon;
// 2. expression
int fibonacci(int i) {
    if (i < 2) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Input format: ./fibonacci n\n");
        return -1;
    }

    int cnt = atoi(argv[1]);

    for (int i = 0; i < cnt; i++) {
        printf("[%d] | %d\n", i + 1, fibonacci(i));
    }
    return 0;
}

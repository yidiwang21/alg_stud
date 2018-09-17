#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// pStr: pattern string
void getNext(char *pStr, int *next, int pLen) {
    int j = 0;
    int k = -1;
    *next = -1;
    while (j < pLen - 1) {
        if (k == -1 || *(pStr + j) == *(pStr + k)) {
            k++;
            j++;
            *(next + j) = k;
        }else
            k = *(next + k);
    }
}

void kmpSearch(char *tStr, char *pStr, int tLen, int pLen, int *next) {
    int i, j = 0;
    // i iters in the text string and j iters int the [next]
    while (i < tLen && j < pLen) {
        if (j == -1 || *(tStr + i) == *(pStr + j)) {
            i++;
            j++;
        }else
            j = *(next + j);
    }
    if (j == pLen) {
        printf("---------------------------------\n");
        printf("The sub string is at position: %d\n", i - j + 1);
        printf("---------------------------------\n");
    }else {
        printf("-------------\n");
        printf("Non-existing!\n");
        printf("-------------\n");
    }
}

int main(int argc, char const *argv[]) {
    if (argc <= 2) {
        printf("Input format: ./kmp [text string] [pattern string]\n");
        return -1;
    }
    int tLen = strlen(argv[1]);
    int pLen = strlen(argv[2]);
    char *tStr = (char *)malloc(sizeof(char) * tLen);
    char *pStr = (char *)malloc(sizeof(char) * pLen);
    strcpy(tStr, argv[1]);
    strcpy(pStr, argv[2]);

    int *next = (int *)malloc(sizeof(int) * pLen);
    memset(next, 0, sizeof(int) * pLen);

    getNext(pStr, next, pLen);
    kmpSearch(tStr, pStr, tLen, pLen, next);

    return 0;
}

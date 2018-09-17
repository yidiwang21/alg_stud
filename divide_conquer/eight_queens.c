#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define QUEEN_NUM   8
#define TRUE        1
#define FALSE       0

int cnt = 0;
int *chessboard = NULL;

void Init() {
    chessboard = (int *)malloc(sizeof(int) * QUEEN_NUM);
    memset(chessboard, 0, sizeof(int) * QUEEN_NUM);
}

void placeQueen(int row, int col) {
    *(chessboard + row) = col;
}

bool isValid(int row, int col) {
    for (int i = 0; i < QUEEN_NUM; i++) {
        if (*(chessboard + i) == col || abs(i - row) == abs(*(chessboard + i) - col))
            return FALSE;
    }
    return TRUE;
}

void printChessboard() {
    int k = 0;
    printf("[%d]: \n", cnt++);
    for (int i = 0; i < QUEEN_NUM; i++) {   // scan rows
        for (k = 0; k < *(chessboard + i); k++) {
            printf("0 ");
        }
        printf("1 ");
        for (k = *(chessboard + i) + 1; k < QUEEN_NUM; k++) {
            printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}

void NQueens(int row) {
    if (row  == QUEEN_NUM - 1) {
        printChessboard();
    }else {
        for (int j = 0; j < QUEEN_NUM; j++) {    // every col at #row
            if (isValid(row, j)) {
                placeQueen(row, j);
                NQueens(row + 1);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    Init();
    NQueens(0);
    return 0;
}

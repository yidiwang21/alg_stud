#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

#define TRUE        1
#define FALSE       0

int cnt = 0;
int *chessboard = NULL;

// row start from 0, col start from 1

void Init(int QUEEN_NUM) {
    chessboard = (int *)malloc(sizeof(int) * QUEEN_NUM);
    memset(chessboard, 0, sizeof(int) * QUEEN_NUM);
}

void placeQueen(int row, int col) {
    *(chessboard + row) = col;
}

bool isValid(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (*(chessboard + i) == col || abs(i - row) == abs(*(chessboard + i) - col))
            return FALSE;
    }
    return TRUE;
}

void printChessboard(const int QUEEN_NUM) {
    int k = 0;
    printf("[%d]: \n", cnt++);
    for (int i = 0; i < QUEEN_NUM; i++) {   // scan rows
        for (k = 1; k <= QUEEN_NUM; k++) {
            if (k == *(chessboard + i))
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    // for (int i = 0; i < QUEEN_NUM; i++) {
    //     printf("%d, %d\n", i, *(chessboard + i));
    // }
    printf("\n");
}

void NQueens(int row, const int QUEEN_NUM) {
    if (row  == QUEEN_NUM) {
        printChessboard(QUEEN_NUM);
    }else {
        for (int j = 1; j <= QUEEN_NUM; j++) {    // every col at #row
            if (isValid(row, j)) {
                placeQueen(row, j);
                // printf("place at: (%d, %d) | %d\n", row, j, *(chessboard + row));
                NQueens(row + 1, QUEEN_NUM);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    if (argc <= 1) {
        printf("Input format: ./eight_queens QUEEN_NUM\n");
        return -1;
    }
    const int QUEEN_NUM = atoi(argv[1]);
    if (QUEEN_NUM > 20 || QUEEN_NUM <= 1) {
        printf("ERROR: QUEEN_NUM must be in range from 2 to 19!\n");
    }

    Init(QUEEN_NUM);
    NQueens(1, QUEEN_NUM);
    return 0;
}

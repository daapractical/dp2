#include <iostream>

#define N 4

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int row) {
    if (row == N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            res = solveNQueensUtil(board, row + 1) || res;
            board[row][col] = 0; // backtrack
        }
    }

    return res;
}

void solveNQueens() {
    int board[N][N] = {0};
    if (!solveNQueensUtil(board, 0)) {
        std::cout << "No solution exists for N = " << N << std::endl;
    }
}

int main() {
    solveNQueens();
    return 0;
}

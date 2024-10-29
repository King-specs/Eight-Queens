# Eight Queens Problem

The Eight Queens Problem is a classic combinatorial puzzle that involves placing eight queens on an 8x8 chessboard such that no two queens threaten each other. This project implements a solution in C++ using a backtracking algorithm.

## Features

- Uses a recursive backtracking algorithm to find all possible solutions for placing eight queens on a chessboard.
- Prints the chessboard configuration with queens represented as `1` and empty squares as `0`.

## Requirements

- A C++ compiler (e.g., g++, clang++)
- Standard C++ library

## Compilation and Execution

1. Clone the repository or download the source code.
2. Open a terminal and navigate to the project directory.
3. Compile the code using:
   ```bash
   g++ -o eight_queens eight_queens.cpp


// Skeleton Code


#include  iostream

#include  vector

using namespace std;

// Function to print the board in the required format
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the problem
bool placeQueens(vector<vector<int>>& board, int row) {
    if (row == 8) {
        return true;  // All queens are placed successfully
    }

    for (int col = 0; col < 8; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place the queen

            if (placeQueens(board, row + 1))
                return true;  // Recur to place queens in the next row

            board[row][col] = 0;  // Backtrack
        }
    }

    return false;  // No place is safe for the queen in this row
}

int main() {
    vector<vector<int>> board(8, vector<int>(8, 0));  // Initialize an 8x8 board with all 0s

    if (placeQueens(board, 0)) {
        printBoard(board);  // Print the solution if found
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}


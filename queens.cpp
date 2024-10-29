
#include <iostream>
#include <vector>
//Write a program that places eight queens on a chessboard (8 x 8 board) such that no queen is 
//“attacking” another. Queens in chess can move vertically, horizontally, or diagonally. 

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
        // All queens are placed successfully
        return true;
    }

    for (int col = 0; col < 8; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place the queen

            // Recur to place queens in the next row
            if (placeQueens(board, row + 1))
                return true;

            // If placing queen in board[row][col] doesn't lead to a solution,
            // then remove the queen (backtrack)
            board[row][col] = 0;
        }
    }

    return false;  // No place is safe for the queen in this row
}

int main() {
    vector<vector<int>> board(8, vector<int>(8, 0));  // Initialize an 8x8 board with all 0s

    // Call placeQueens starting from the first row
    if (placeQueens(board, 0)) {
        printBoard(board);  // Print the solution if found
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}


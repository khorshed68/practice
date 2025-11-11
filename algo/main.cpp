#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> board;
int solutionCount = 0;
void printBoard() {
    cout << "Solution " << ++solutionCount << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == -1) cout << "X ";  // bad square
            else if (board[i][j] == 1) cout << "Q ";  // queen
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}
//for checking Q safe or not
bool isSafe(int row, int col) {
    if (board[row][col] == -1) return false; // cannot place on bad square
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1) return false;
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1) return false;
    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1) return false;
    return true;
}
// Backtracking function
void solveNQueen(int row) {
    // Base case: all queens are placed
    if (row == n) {
        printBoard();
        return;
    }
    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;    // place queen
            solveNQueen(row + 1);   // recursive call for next row
            board[row][col] = 0;    // backtrack
        }
    }
}
int main() {
    cout << "Enter number of queens (n): ";
    cin >> n;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    cout << "Enter bad squares (mark as 1). Example: for 4x4 board, enter 16 numbers (0 or 1):\n";
    cout << "(1 means BAD, 0 means ALLOWED)\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 1) board[i][j] = -1;  // mark bad square
        }
    }
    solveNQueen(0);
    if (solutionCount == 0)
        cout << "No solution exists for n = " << n << "\n";
    else
        cout << "Total valid solutions found: " << solutionCount << "\n";
    return 0;
}

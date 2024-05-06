#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NQueens {
private:
    vector<int> board; // To represent the placement of queens on the board
    int size; // Size of the chessboard (N x N)
    int solutions; // Number of solutions found

    bool isSafe(int row, int col) {
        // Check if no two queens threaten each other
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(board[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }

    void backtracking(int row) {
        if (row == size) { // All queens are placed successfully
            solutions++;
            // Print the solution
            cout << "Solution " << solutions << ":\n";
            printBoard();
            cout << endl;
            return;
        }

        for (int col = 0; col < size; col++) {
            if (isSafe(row, col)) {
                board[row] = col; // Place queen on this position
                backtracking(row + 1); // Try placing the next queen
            }
        }
    }

    void branchAndBound(int row) {
        if (row == size) { // All queens are placed successfully
            solutions++;
            // Print the solution
            cout << "Solution " << solutions << ":\n";
            printBoard();
            cout << endl;
            return;
        }

        for (int col = 0; col < size; col++) {
            if (isSafe(row, col)) {
                board[row] = col; // Place queen on this position
                branchAndBound(row + 1); // Try placing the next queen

                // If no solution is found by placing a queen in this column, backtrack
                board[row] = -1;
            }
        }
    }

    void printBoard() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }

public:
    NQueens(int n) : size(n), solutions(0) {
        board.resize(size, -1); // Initialize board with no queens placed
    }

    void solveWithBacktracking() {
        backtracking(0);
    }

    void solveWithBranchAndBound() {
        branchAndBound(0);
    }
};

int main() {
    int n;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> n;

    NQueens nQueens(n);
    cout << "\nSolving N-Queens problem using Backtracking:\n";
    nQueens.solveWithBacktracking();

    nQueens = NQueens(n); // Resetting the board for branch and bound
    cout << "\nSolving N-Queens problem using Branch and Bound:\n";
    nQueens.solveWithBranchAndBound();

    return 0;
}

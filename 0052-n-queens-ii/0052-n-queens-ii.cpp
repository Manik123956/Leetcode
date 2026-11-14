class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Horizontal
        for(int i = 0; i < n; i++) {
            if(board[row][i] == 'Q') {
                return false;
            }
        }

        // Vertical
        for(int i = 0; i < n; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // Left Diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        // Right Diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string>& board, int row, int n, int &count) {

        // Base Case
        if(row == n) {
            count++;
            return;
        }

        // Try every column
        for(int i = 0; i < n; i++) {

            if(isSafe(board, row, i, n)) {

                // Place Queen
                board[row][i] = 'Q';

                // Recursive Call
                nQueens(board, row + 1, n, count);

                // Backtracking
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        int count = 0;

        nQueens(board, 0, n, count);

        return count;
    }
};
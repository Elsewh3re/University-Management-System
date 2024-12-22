#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3]; // Game board
    char currentPlayer; // Current player ('X' or 'O')

    // Initialize the board
    void initializeBoard() {
        char pos = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = pos++;
            }
        }
    }

    // Display the board
    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << board[i][j] << " ";
                if (j < 2) cout << "|";
            }
            if (i < 2) cout << "\n---|---|---\n";
        }
        cout << "\n";
    }

    // Check for a winner
    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Row
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Column
        }
        // Check diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    // Check if the board is full (draw)
    bool isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
            }
        }
        return true;
    }

public:
    // Constructor to initialize the game
    TicTacToe() : currentPlayer('X') {
        initializeBoard();
    }

    // Play the game
    void playGame() {
        int choice;
        bool gameRunning = true;

        while (gameRunning) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your position (1-9): ";
            cin >> choice;

            // Map input to board coordinates
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Check if the position is valid
            if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            // Make the move
            board[row][col] = currentPlayer;

            // Check for a winner
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameRunning = false;
                break;
            }

            // Check for a draw
            if (isDraw()) {
                displayBoard();
                cout << "The game is a draw!\n";
                gameRunning = false;
                break;
            }

            // Switch to the next player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}


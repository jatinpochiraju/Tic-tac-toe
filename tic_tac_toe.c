#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(char board[3][3], char player);
bool isBoardFull(char board[3][3]);
bool isValidMove(char board[3][3], int row, int col);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    int row, col;

    initializeBoard(board);

    printf("Welcome to Tic-tac-toe!\n");
    printf("Player 1: X, Player 2: O\n");
    printf("Enter row (1-3) and column (1-3) to make your move.\n\n");

    while (!gameWon && !isBoardFull(board)) {
        displayBoard(board);
        printf("\nPlayer %c's turn.\n", currentPlayer);
        
        do {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            
            // Adjust input to array indices
            row--;
            col--;
            
            if (!isValidMove(board, row, col)) {
                printf("Invalid move! Try again.\n");
            }
        } while (!isValidMove(board, row, col));

        makeMove(board, row, col, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("\nPlayer %c wins!\n", currentPlayer);
            gameWon = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    if (!gameWon) {
        displayBoard(board);
        printf("\nGame Over! It's a draw!\n");
    }

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n");
}

bool makeMove(char board[3][3], int row, int col, char player) {
    if (isValidMove(board, row, col)) {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

bool checkWin(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
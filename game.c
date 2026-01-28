#include <stdio.h>

// Function to display the board
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---+---+---\n");
    }
    printf("\n");
}

// Function to check win
int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return 1;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return 1;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return 1;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return 1;

    return 0;
}

// Function to check draw
int checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    char currentPlayer = 'X';

    printf("===== Tic Tac Toe Game =====\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while (1) {
        displayBoard(board);

        printf("Player %c, enter row and column (1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("🎉 Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
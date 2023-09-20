#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7
#define PLAYER_RED 1
#define PLAYER_YELLOW 2
#define TIE 3
#define MAX_MOVES 42
#define NUM_COLUMNS 7

int BOARD[ROWS][COLS];
int colors[2];

// Function to print the current game board
void printBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            if (BOARD[i][j] == 0)
            {
                printf(" |");
            }
            else if (BOARD[i][j] == PLAYER_RED)
            {
                printf("R|");
            }
            else
            {
                printf("Y|");
            }
        }
        printf("\n");
    }
    printf("---------------\n");
}

// Function to assign colors to players, ensuring Red goes first
void assignColors()
{
    printf("Red Player goes first!\n");
    colors[0] = PLAYER_RED;
    colors[1] = PLAYER_YELLOW;
}

// Function to check if a player has won the game
int checkWin()
{
    // Check for win in the horizontal direction
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (BOARD[i][j] == PLAYER_RED && BOARD[i][j + 1] == PLAYER_RED && BOARD[i][j + 2] == PLAYER_RED && BOARD[i][j + 3] == PLAYER_RED)
            {
                return PLAYER_RED;
            }
            else if (BOARD[i][j] == PLAYER_YELLOW && BOARD[i][j + 1] == PLAYER_YELLOW && BOARD[i][j + 2] == PLAYER_YELLOW && BOARD[i][j + 3] == PLAYER_YELLOW)
            {
                return PLAYER_YELLOW;
            }
        }
    }
    // Check for win in the vertical direction
    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (BOARD[i][j] == PLAYER_RED && BOARD[i + 1][j] == PLAYER_RED && BOARD[i + 2][j] == PLAYER_RED && BOARD[i + 3][j] == PLAYER_RED)
            {
                return PLAYER_RED;
            }
            else if (BOARD[i][j] == PLAYER_YELLOW && BOARD[i + 1][j] == PLAYER_YELLOW && BOARD[i + 2][j] == PLAYER_YELLOW && BOARD[i + 3][j] == PLAYER_YELLOW)
            {
                return PLAYER_YELLOW;
            }
        }
    }
    // Check for win in the diagonal direction
    for (int i = 0; i < ROWS - 3; i++)
    {
        for (int j = 0; j < COLS - 3; j++)
        {
            if (BOARD[i][j] == PLAYER_RED && BOARD[i + 1][j + 1] == PLAYER_RED && BOARD[i + 2][j + 2] == PLAYER_RED && BOARD[i + 3][j + 3] == PLAYER_RED)
            {
                return PLAYER_RED;
            }
            else if (BOARD[i][j] == PLAYER_YELLOW && BOARD[i + 1][j + 1] == PLAYER_YELLOW && BOARD[i + 2][j + 2] == PLAYER_YELLOW && BOARD[i + 3][j + 3] == PLAYER_YELLOW)
            {
                return PLAYER_YELLOW;
            }
        }
    }
    // Check for a tie
    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (BOARD[i][j] != 0)
            {
                count++;
            }
        }
    }
    if (count == MAX_MOVES)
    {
        return TIE;
    }

    return 0;
}

// Function for a player to make a move
void makeMove(int player)
{
    printf("Player %s, enter a column number between 1-%d: ", (player == PLAYER_RED) ? "Red" : "Yellow", NUM_COLUMNS);
    int column;
    scanf("%d", &column);
    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (BOARD[i][column - 1] == 0)
        {
            BOARD[i][column - 1] = player;
            break;
        }
    }
}

// Function to play the game
void playGame(char player1[], char player2[])
{
    int winner = checkWin();
    while (winner == 0)
    {
        makeMove(PLAYER_RED);
        printBoard();
        winner = checkWin();
        if (winner != 0)
            break;
        makeMove(PLAYER_YELLOW);
        printBoard();
        winner = checkWin();
    }
    if (winner == TIE)
    {
        printf("It's a tie!\n");
    }
    else
    {
        printf("Congratulations Player %s! You won!\n", (winner == PLAYER_RED) ? player1 : player2);
    }

    int playAgain;
    printf("Do you want to play again? (1 for yes, 0 for no): ");
    scanf("%d", &playAgain);
    if (playAgain == 0)
    {
        printf("Thanks for playing!\n");
        exit(0);
    }
}

int main()
{
    printf("Welcome to Connect 4!\n");
    char player1[20];
    char player2[20];

    printf("Enter the name for Red Player: ");
    scanf("%s", player1);

    printf("Enter the name for Yellow Player: ");
    scanf("%s", player2);

    printf("Let's Play!\n");

    while (1)
    { // Infinite loop to play multiple games
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                BOARD[i][j] = 0;
            }
        }
        assignColors();
        printBoard();
        playGame(player1, player2);
    }
    return 0;
}

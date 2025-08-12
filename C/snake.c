#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>  // Yeah, Windows-specific — cross-platform later maybe

#define SCREEN_W 40
#define SCREEN_H 20

// Game state globals (yeah, globals — I’ll clean later... maybe)
int isGameOver;
int headX, headY;
int fruitX, fruitY;
int points;
int tailPosX[100], tailPosY[100];
int tailLength;   // grows over time obviously

// Direction enum (STOP is initial idle state)
enum MoveDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum MoveDir snakeDir;

void InitGame()
{
    isGameOver = 0;
    snakeDir = STOP;
    
    // Start roughly in middle
    headX = SCREEN_W / 2;
    headY = SCREEN_H / 2;
    
    // First fruit — random but could spawn on snake's head sometimes
    fruitX = rand() % SCREEN_W;
    fruitY = rand() % SCREEN_H;
    
    points = 0;
    tailLength = 0;
    
    // Debug note: Might need srand(time(NULL)) somewhere for less predictable fruit
}

void Render()
{
    system("cls"); // Clear console (yep, flickers — deal with it for now)

    // Draw top boundary
    for (int i = 0; i < SCREEN_W + 2; i++)
        printf("#");
    printf("\n");

    // The main playing field
    for (int row = 0; row < SCREEN_H; row++)
    {
        for (int col = 0; col < SCREEN_W; col++)
        {
            if (col == 0)
                printf("#"); // Left wall

            if (row == headY && col == headX)
                printf("O"); // Snake head
            else if (row == fruitY && col == fruitX)
                printf("F"); // Fruit
            else
            {
                int isTailPart = 0;
                for (int t = 0; t < tailLength; t++)
                {
                    if (tailPosX[t] == col && tailPosY[t] == row)
                    {
                        printf("o");
                        isTailPart = 1;
                        break; // stop searching tail
                    }
                }
                if (!isTailPart)
                    printf(" "); // empty space
            }

            if (col == SCREEN_W - 1)
                printf("#"); // Right wall
        }
        printf("\n");
    }

    // Bottom wall
    for (int i = 0; i < SCREEN_W + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", points);
    // Maybe add high score tracking later
}

void HandleInput()
{
    if (_kbhit()) // if a key is pressed
    {
        char ch ==getch();
        // Could add arrow keys support but sticking to WASD for now
        switch (ch)
        {
        case 'a':
            snakeDir = LEFT;
            break;
        case 'd':
            snakeDir = RIGHT;
            break;
        case 'w':
            snakeDir = UP;
            break;
        case 's':
            snakeDir = DOWN;
            break;
        case 'x':  // quit
            isGameOver = 1;
            break;
        default:
            // ignoring unknown keys
            break;
        }
    }
}

void UpdateGame()
{
    // Move tail segments (could be optimized, but readability > micro-speed here)
    int prevX = tailPosX[0];
    int prevY = tailPosY[0];
    int tempX, tempY;

    tailPosX[0] = headX;
    tailPosY[0] = headY;

    for (int i = 1; i < tailLength; i++)
    {
        tempX = tailPosX[i];
        tempY = tailPosY[i];
        tailPosX[i] = prevX;
        tailPosY[i] = prevY;
        prevX = tempX;
        prevY = tempY;
    }

    // Move head depending on direction
    switch (snakeDir)
    {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    default:
        break; // STOP does nothing
    }

    // Collision with walls
    if (headX >= SCREEN_W || headX < 0 || headY >= SCREEN_H || headY < 0)
        isGameOver = 1;

    // Collision with tail
    for (int i = 0; i < tailLength; i++)
    {
        if (tailPosX[i] == headX && tailPosY[i] == headY)
        {
            isGameOver = 1;
            break;
        }
    }

    // Eating fruit
    if (headX == fruitX && headY == fruitY)
    {
        points += 10;
        fruitX = rand() % SCREEN_W;
        fruitY = rand() % SCREEN_H;
        tailLength++;
    }
}

int main()
{
    InitGame();
    while (!isGameOver)
    {
        Render();
        HandleInput();
        UpdateGame();
        Sleep(100); // could adjust for difficulty
    }
    printf("Game Over! Final Score: %d\n", points);

    return 0;
}

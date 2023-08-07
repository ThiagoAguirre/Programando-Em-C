// Projeto das 8-rainhas
// Nome: Joao Pedro de Paula Oliveira do Amaral
//  Tia: 32049390

// Nome: Nicolas de Barros
//  Tia: 32070837

// Nome: Thiago de Oliveira Aguirre - 32089589
//  Tia: 32089589

#include <stdio.h>
#define FALSE 0
#define TRUE 1

void solution(int board[8][8])
{
    int i, j, White = TRUE;
    for (i = 0; i < 8; i = i + 1)
    {
        for (j = 0; j < 8; j = j + 1)
        {
            if (board[i][j])
                printf("  R");
            else if (White)
                printf("  #");
            else
                printf("  #");
            White = !White;
        }
        White = !White;
        printf("\n\n");
    }
}

int ThreatenedQueen(int board[8][8], int Line, int Column)
{
    int i, j, Position = TRUE;
    i = Line - 1;

    while (i >= 0 && Position)
    {
        Position = !board[i][Column];
        i = i - 1;
    }
    i = Line - 1;
    j = Column + 1;

    while (i >= 0 && j < 8 && Position)
    {
        Position = !board[i][j];
        i = i - 1;
        j = j + 1;
    }
    i = Line - 1;
    j = Column - 1;

    while (i >= 0 && j >= 0 && Position)
    {
        Position = !board[i][j];
        i = i - 1;
        j = j - 1;
    }
    return Position;
}

int PutQueen(int board[8][8], int line)
{
    int Column = 0, Position = FALSE;
    if (line >= 8)
        return TRUE;

    else
    {
        while (Column < 8 && !Position)
        {
            board[line][Column] = TRUE;
            if (ThreatenedQueen(board, line, Column))
                Position = PutQueen(board, line + 1);
            if (!Position)
            {
                board[line][Column] = FALSE;
                Column = Column + 1;
            }
        }
        return Position;
    }
}

int main(void)
{
    int i, j, board[8][8];
    for (i = 0; i < 8; i = i + 1)
        for (j = 0; j < 8; j = j + 1)
            board[i][j] = FALSE;
    if (PutQueen(board, 0))
        solution(board);
}
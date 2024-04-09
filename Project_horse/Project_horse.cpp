#include <iostream>
#define N 8

int solution[N][N];

// Массивы для 8 возможных движений коня
int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// Проверка, что i,j находятся на доске
bool isValid(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N && solution[x][y] == -1);
}

// Вывод решения
void printSolution()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            std::cout << solution[x][y] << " ";
        std::cout << "\n";
    }
}

// Рекурсивная функция для решения задачи
bool solveKTUtil(int x, int y, int moveI)
{
    int next_x, next_y;
    if (moveI == N * N)
        return true;

    for (int k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isValid(next_x, next_y))
        {
            solution[next_x][next_y] = moveI;
            if (solveKTUtil(next_x, next_y, moveI + 1) == true)
                return true;
            else
                solution[next_x][next_y] = -1;// Откат, если не получается продолжить
        }
    }
    return false;
}

// Функция для решения задачи
bool solveKT()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            solution[x][y] = -1;

    solution[0][0] = 0; // Начальная позиция

    if (solveKTUtil(0, 0, 1) == false)
    {
        std::cout << "Solution does not exist";
        return false;
    }
    else
        printSolution();

    return true;
}

int main()
{
    solveKT();
    return 0;
}
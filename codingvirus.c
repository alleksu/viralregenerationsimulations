#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define size 20

int grid[size][size];
int temp[size][size];

int countlive(int x, int y) {
    int total = 0;
    if (y - 1 >= 0) total += grid[x][y - 1];
    if (y + 1 < size) total += grid[x][y + 1];
    return total;
}

void step() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int alive = countlive(i, j);
            if (grid[i][j]) {
                temp[i][j] = (alive == 1);
            } else {
                temp[i][j] = (alive == 2);
            }
        }
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = temp[i][j];
}

void show() {
    printf("\033[H");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            putchar(grid[i][j] ? 'X' : '.');
            putchar(' ');
        }
        putchar('\n');
    }
}

void seed() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            grid[i][j] = rand() % 2;
}

int main() {
    seed();
    while (1) {
        show();
        step();
        usleep(200000);
    }
    return 0;
}
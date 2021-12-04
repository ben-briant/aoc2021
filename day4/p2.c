
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int boards[5][5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            printf("%d ", boards[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int make_guess(int board[5][5], int guess) {
    int yee = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == guess) {
                board[r][c] = -1;
                yee = 1;
            }
        }
    }
    return yee;
}

int check_win(int board[5][5]) {
    // cols
    for (int r = 0; r < 5; r++) {
        int count = 0;
        for (int c = 0; c < 5; c++) {
            if (board[r][c] == -1) {
                count++;
            }
        }
        if (count == 5) return 1;
    }
    // rows
    for (int c = 0; c < 5; c++) {
        int count = 0;
        for (int r = 0; r < 5; r++) {
            if (board[r][c] == -1) {
                count++;
            }
        }
        if (count == 5) return 1;
    }
    /*
    // diagonals
    int count = 0;
    for (int r = 0, c = 0; r < 5 && c < 5; c++, r++) {
        if (board[r][c] == -1) count++;
    }
    if (count == 5) return 1;

    count = 0;
    for (int r = 4, c = 0; r >= 0 && c < 5; c++, r--) {
        if (board[r][c] == -1) count++;
    }
    if (count == 5) return 1;
    */
    return 0;
}

int calc_score(int board[5][5], int guess) {
    int total = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (board[r][c] != -1) {
                total += board[r][c];
            }
        }
    }
    return total * guess;
}

int main(void) {
    FILE *f = fopen("input", "r");
    int boards[100][5][5] = {0};
    while (fgetc(f) != '\n');

    int i = 0;
    int num;
    while (fscanf(f, "%d", &((int *)boards)[i++]) == 1);
    int count = i;
    int num_boards = count / 25;

    fseek(f, 0, SEEK_SET);

    int num_left = num_boards;
    int left[num_boards];
    for (int i = 0; i < num_boards; i++) left[i] = 1;
    int guess;
    while (fscanf(f, "%d,", &guess) == 1) {
        printf("guess = %d\n", guess);
        for (int b = 0; b < num_boards; b++) {
            if (left[b] == 0) continue;
            if (make_guess(boards[b], guess)) {
                if (check_win(boards[b])) {
                    num_left--;
                    left[b] = 0;
                    if (num_left == 0) {
                        int score = calc_score(boards[b], guess);
                        printf("%d\n", score);
                        return 0;
                    }
                }
            }
        }

    }
}

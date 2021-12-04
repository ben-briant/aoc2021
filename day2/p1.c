#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *f  = fopen("input", "r");

    int hor = 0;
    int ver = 0;
    char direction[20];
    int dist;

    while (fscanf(f, "%20s %d", direction, &dist) == 2) {
        if (strcmp(direction, "forward") == 0) {
            hor += dist;
        } else if (strcmp(direction, "down") == 0) {
            ver += dist;
        } else if (strcmp(direction, "up") == 0) {
            ver -= dist;
        }
    }

    printf("%d", hor * ver);
}

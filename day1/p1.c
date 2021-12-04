#include <stdio.h>

int main(void) {
    FILE *f = fopen("input", "r");
    int num1, num2;
    int total = 0;
    fscanf(f, "%d", &num1);
    while (fscanf(f, "%d", &num2) == 1) {
        if (num2 > num1) total++;
        num1 = num2;
    }
    printf("%d\n", total);
}

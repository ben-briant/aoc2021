
#include <stdio.h>

int main(void) {
    FILE *f = fopen("input", "r");
    int num1, num2, num3, num4;
    int total = 0;
    fscanf(f, "%d", &num1);
    fscanf(f, "%d", &num2);
    fscanf(f, "%d", &num3);
    while (fscanf(f, "%d", &num4) == 1) {
        if (num2 + num3 + num4 > num1 + num2 + num3) total++;
        num1 = num2;
        num2 = num3;
        num3 = num4;
    }
    printf("%d\n", total);
}

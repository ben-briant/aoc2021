#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {
    FILE *f = fopen("input", "r");
    char str[13];
    int totals[12] = {0};
    int num = 0;
    while (fgets(str, 14, f)) {
        int len = strlen(str) - 1;
        for (int i = 0; i < len; i++) {
            if (str[i] == '1') totals[i]++;
        }
        num++;
    }
    uint64_t gamma = 0, epsilon = 0;
    for (int i = 0; i < 12; i++) {
        if (totals[i] > num / 2) {
            gamma |= 1 << (11 - i);
        } else {
            epsilon |= 1 << (11 - i);
        }
    }
    printf("%ld\n", gamma * epsilon);
}

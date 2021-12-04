#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_BIT_SIZE 14

struct node {
    char bits[MAX_BIT_SIZE];
    struct node *next;
};

struct node *create(char *text) {
    struct node *new = malloc(sizeof *new);
    strcpy(new->bits, text);
    new->next = NULL;
    return new;
}

struct node *filter(struct node *head, int bit_num, int val) {
    struct node *new_head = NULL;
    struct node *new_tail = NULL;
    struct node *curr = head;
    while (curr != NULL) {
        struct node *next = curr->next;
        if (curr->bits[bit_num] == val) {
            if (new_head) {
                new_tail->next = curr;
                new_tail = curr;
            } else {
                new_head = new_tail = curr;
            }
            new_tail->next = NULL;
        }
        curr = next;
    }
    return new_head;
}

char get_most_common(struct node *head, int bit_num) {
    int c0 = 0, c1 = 0;
    while (head) {
        if (head->bits[bit_num] == '1') {
            c1++;
        } else {
            c0++;
        }
        head = head->next;
    }
    if (c0 > c1) return '0';
    else return '1';
}

uint64_t bits_to_int(char *bits) {
    uint64_t val = 0;;
    for (int i = 0; i < MAX_BIT_SIZE - 2; i++) {
        if (bits[i] == '1') val |= 1 << (MAX_BIT_SIZE - 3 - i);
    }

    return val;
}

int thing(int is_least) {

    FILE *f = fopen("input", "r");
    struct node *head = NULL;
    struct node *tail = NULL;
    char str[MAX_BIT_SIZE];
    while (fgets(str, MAX_BIT_SIZE, f)) {
        struct node *new = create(str);
        if (!head) {
            head = tail = new;
        } else {
            tail->next = new;
            tail = new;
        }
    }

    int bit_num = 0;
    while (head->next != NULL) {
        char val = get_most_common(head, bit_num);
        if (is_least) {
            if (val == '0') val = '1';
            else val = '0';
        }
        head = filter(head, bit_num, val);
        bit_num++;
        if (bit_num > MAX_BIT_SIZE - 3) bit_num = 0;
    }
    printf("%lu\n", bits_to_int(head->bits));
    return bits_to_int(head->bits);
}
int main(void) {
    printf("%lu\n", thing(0) * thing(1));
}

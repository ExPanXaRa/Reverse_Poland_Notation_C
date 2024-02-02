#include "stack.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init2(Stack *s, int capacity) {
    s->top = -1;
    s->capacity = capacity;
    s->stack = (double *)malloc(capacity * sizeof(double));
    if (s->stack == NULL) {
        exit(0);
    }
}

int is_full(const Stack *s) { return s->top == s->capacity - 1; }

void push(Stack *s, double value) {
    if (is_full(s)) {
        s->capacity *= 2;
        s->stack = (double *)realloc(s->stack, s->capacity * sizeof(double));
        if (s->stack == NULL) {
            exit(0);
        }
    }
    s->stack[++(s->top)] = value;
}

double pop(Stack *s) { return s->stack[(s->top)--]; }

void destroy(Stack *s) { free(s->stack); }

struct stack *init(const char *take) {  // Создает первый элемент структуры
    struct stack *stakan = (struct stack *)malloc(sizeof(struct stack));
    stakan->data = take[0];
    stakan->back = NULL;
    return stakan;
}

struct stack *add_in_stack(struct stack *now, const char *take,
                           int i) {  // Добавляет элемент в структуру
    struct stack *stakan = (struct stack *)malloc(sizeof(struct stack));
    stakan->data = take[i];
    stakan->back = now;
    return stakan;
}

struct stack *del_stack(struct stack *now) {  // Удаляеь элемент из структуры
    struct stack *new_root = now->back;
    free(now);
    return new_root;
}

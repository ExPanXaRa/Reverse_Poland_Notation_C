#include "calculate.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void process_token(Stack *stack, const char *token, float x) {
    if (token[0] >= '0' && token[0] <= '9') {
        double value = atof(token);
        push(stack, value);
    } else if (strcmp(token, "x") == 0) {
        push(stack, x);
    } else {
        if (strcmp(token, "~") == 0) {
            double operand = pop(stack);
            push(stack, operand * -1);
        } else if (strcmp(token, "+") == 0) {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            push(stack, operand1 + operand2);
        } else if (strcmp(token, "-") == 0) {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            push(stack, operand1 - operand2);
        } else if (strcmp(token, "*") == 0) {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            push(stack, operand1 * operand2);
        } else if (strcmp(token, "/") == 0) {
            double operand2 = pop(stack);
            double operand1 = pop(stack);
            push(stack, operand1 / operand2);
        } else if (strcmp(token, "s") == 0) {
            double operand = pop(stack);
            push(stack, sin(operand));
        } else if (strcmp(token, "c") == 0) {
            double operand = pop(stack);
            push(stack, cos(operand));
        } else if (strcmp(token, "t") == 0) {
            double operand = pop(stack);
            push(stack, tan(operand));
        } else if (strcmp(token, "g") == 0) {
            double operand = pop(stack);
            push(stack, 1.0 / tan(operand));
        } else if (strcmp(token, "q") == 0) {
            double operand = pop(stack);
            push(stack, sqrt(operand));
        } else if (strcmp(token, "l") == 0) {
            double operand = pop(stack);
            push(stack, log(operand));
        }
    }
}

double calculate_expression(const char *expression, float x) {
    int length = strlen(expression);
    char *input_copy = strdup(expression);
    Stack stack;
    init2(&stack, length);

    char *token = strtok(input_copy, " ");
    while (token != NULL) {
        process_token(&stack, token, x);
        token = strtok(NULL, " ");
    }

    if (stack.top != 0) {
        exit(0);
    }

    double result = pop(&stack);
    destroy(&stack);
    free(input_copy);
    return result;
}

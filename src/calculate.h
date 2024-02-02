#ifndef CALCULATE
#define CALCULATE
#include "stack.h"

void process_token(Stack *stack, const char *token, float x);
double calculate_expression(const char *expression, float x);

#endif

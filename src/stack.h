#ifndef STACK
#define STACK

typedef struct {
    double *stack;
    int top;
    int capacity;
} Stack;

struct stack {
    char data;
    struct stack *back;
};

void init2(Stack *s, int capacity);
int is_empty(const Stack *s);
int is_full(const Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);
void destroy(Stack *s);
struct stack *init(const char *take);
struct stack *add_in_stack(struct stack *now, const char *take, int i);
struct stack *del_stack(struct stack *now);

#endif
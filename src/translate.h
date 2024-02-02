#ifndef TRANSLATE
#define TRANSLATE
#include "stack.h"

void zapis(int *flag, char *take, int *n);
int check_ves(char znak);
int proverka(struct stack *now, char *take, int i);
int alphabet_check(const char *take, int *i);
struct stack *dobavka(int check_alph, char *take, int i, struct stack *stakan, char *polka, int *m,
                      int *flag_exit);
struct stack *obrabotka_skobki(struct stack *stakan, char *polka, int *m);

#endif

#include "translate.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void zapis(int *flag, char take[], int *n) {
    while (*flag != 1) {
        scanf("%c", &take[*n]);
        if (take[*n] == '\n') {
            *flag = 1;
        } else {
            (*n)++;
        }
    }
}

int check_ves(char znak) {
    int ves = 0;
    switch (znak) {
        case '+':
        case '-':
            ves = 1;
            break;
        case '*':
        case '/':
            ves = 2;
            break;
        case 'c':
        case 's':
        case 't':
        case 'l':
            ves = 3;
            break;
        case ')':
        case '(':
            ves = 5;
            break;
        case '~':
            ves = 4;
            break;
    }
    return ves;
}

int alphabet_check(const char *take, int *i) {
    int alphabet_check = 0;
    if (take[*i] == '-' && *i == 1) {
        alphabet_check = 9;
    } else if (take[*i] == '+' || take[*i] == '-' || take[*i] == '*' || take[*i] == '/' || take[*i] == '(' ||
               take[*i] == ')') {
        alphabet_check = 1;
    } else if (take[*i] == 'c' && take[*i + 1] == 'o' && take[*i + 2] == 's') {
        alphabet_check = 2;
        (*i) += 2;
    } else if (take[*i] == 's' && take[*i + 1] == 'i' && take[*i + 2] == 'n') {
        alphabet_check = 2;
        (*i) += 2;
    } else if (take[*i] == 't' && take[*i + 1] == 'a' && take[*i + 2] == 'n') {
        alphabet_check = 2;
        (*i) += 2;
    } else if (take[*i] == 'c' && take[*i + 1] == 't' && take[*i + 2] == 'g') {
        alphabet_check = 5;
        (*i) += 2;
    } else if (take[*i] == 's' && take[*i + 1] == 'q' && take[*i + 2] == 'r' && take[*i + 3] == 't') {
        alphabet_check = 2;
        (*i) += 3;
    } else if (take[*i] == 'l' && take[*i + 1] == 'n') {
        alphabet_check = 7;
        (*i) += 1;
    } else if (take[*i] == '0' || take[*i] == '1' || take[*i] == '2' || take[*i] == '3' || take[*i] == '4' ||
               take[*i] == '5' || take[*i] == '6' || take[*i] == '7' || take[*i] == '8' || take[*i] == '9' ||
               take[*i] == 'x' || take[*i] == '.') {
        alphabet_check = 8;
    }
    return alphabet_check;
}

struct stack *dobavka(int check_alph, char *take, int i, struct stack *stakan, char *polka, int *m,
                      int *flag_exit) {
    int ti = i - 1;
    if ((take[i] == '-' && take[i - 1] == '(') || check_alph == 9 ||
        (take[i] == '-' && alphabet_check(take, &ti) == 1 && take[i - 1] != ')')) {
        take[i] = '~';
        check_alph = 1;
    }
    if (check_alph == 1) {  //Если знак из алфавита, добавление в стек
        if (check_ves(take[i]) <= check_ves(stakan->data) && stakan->back != NULL && stakan->data != '(') {
            if (stakan->data != ')') {
                polka[*m] = stakan->data;
                (*m)++;
                if (polka[(*m) - 1] != ' ') {
                    polka[*m] = ' ';
                    (*m)++;
                }
            }
            stakan = del_stack(stakan);
            stakan = add_in_stack(stakan, take, i);
        } else {
            stakan = add_in_stack(stakan, take, i);
        }
    } else if (check_alph == 2) {
        stakan = add_in_stack(stakan, take, i - 2);  // Добавление косинуса,синуса,тангенса,квадрата
    } else if (check_alph == 5) {
        stakan = add_in_stack(stakan, take, i);  // Добавление котангенса
    } else if (check_alph == 7) {
        stakan = add_in_stack(stakan, take, i - 1);  // Добавление ln
    } else if (take[i] != ' ' && check_alph == 8) {  // Добавление цифр точек и икса
        int til = i + 1;
        if (alphabet_check(take, &til) != 8) {
            polka[*m] = take[i];
            (*m)++;
            if (polka[*m - 1] != ' ') {
                polka[*m] = ' ';
                (*m)++;
            }
        } else {
            polka[*m] = take[i];
            (*m)++;
        }
    } else if (take[i] != ' ') {
        printf("n/a");
        *flag_exit = 1;
    }
    return stakan;
}

struct stack *obrabotka_skobki(struct stack *stakan, char *polka, int *m) {
    if (stakan->data == ')') {
        while (stakan->data != '(') {
            if (stakan->data != ')') {
                polka[*m] = stakan->data;
                (*m)++;
                if (polka[(*m) - 1] != ' ') {
                    polka[*m] = ' ';
                    (*m)++;
                }
            }
            stakan = del_stack(stakan);
        }
    }
    return stakan;
}

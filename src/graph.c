#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "print_graph.h"
#include "translate.h"

int main() {
    int n = 1, m = 0;
    char *take = (char *)malloc(sizeof(char) * (n));
    char *polka = (char *)malloc(sizeof(char) * (m));
    int flag = 0;
    zapis(&flag, take, &n);             // запись в массив входящей строки
    struct stack *stakan = init(take);  // инициализация 1го элемента стакана
    int flag_exit = 0;                  // перевод в постфиксную нотацию
    int i = 1;
    while (i < n && flag_exit != 1) {
        int check_alph = 0;
        check_alph = alphabet_check(take, &i);  // Проверка на наличие знака в алфавите
        stakan = dobavka(check_alph, take, i, stakan, polka, &m, &flag_exit);
        stakan = obrabotka_skobki(stakan, polka, &m);
        i++;
    }
    if (m != 0 && polka[(m)-1] != ' ') {
        polka[m] = ' ';
        m++;
    }
    while (stakan->back != NULL) {
        if (stakan->data != ')' && stakan->data != '(') {
            polka[m] = stakan->data;
            m++;
        }
        stakan = del_stack(stakan);
        if ((stakan->data != ')' && stakan->data != '(') && (stakan->back != NULL && polka[(m)-1] != ' ')) {
            polka[m] = ' ';
            m++;
        }
    }
    if (flag_exit == 0) {
        system("clear");
        graphic(polka);
    }
    free(stakan);
    free(take);
    free(polka);
    return 0;
}

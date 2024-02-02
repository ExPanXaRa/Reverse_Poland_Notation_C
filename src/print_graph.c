#include "print_graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculate.h"

#define Y_AXIS 25
#define X_AXIS 80

void graphic(char *expression) {
    double x_min = 0.0;
    double x_max = 4 * M_PI;
    double y_min = -1.0;
    double y_max = 1.0;

    for (int i = 0; i < Y_AXIS; i++) {
        for (int j = 0; j < X_AXIS; j++) {
            double x_normalized = x_min + j * (x_max - x_min) / (X_AXIS - 1);
            double y_normalized = y_min + i * (y_max - y_min) / (Y_AXIS - 1);
            double result = calculate_expression(expression, x_normalized);
            if (fabs(y_normalized - result) <= (y_max - y_min) / (Y_AXIS - 1) / 2.0) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

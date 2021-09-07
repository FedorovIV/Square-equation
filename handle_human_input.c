//
// Created by ilyaf on 29.08.2021.
//
#include <stdio.h>
#include "handle_human_input.h"

void handle_human_input (double* a, double* b, double* c) {
    while (scanf("%lf%lf%lf", a, b, c) != 3) {
        printf("Error. Enter the correct coefficients \n");
        while (getchar() != '\n');
    }
}
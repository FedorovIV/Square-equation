//
// Created by ilyaf on 29.08.2021.
//
#include <stdio.h>
#include "output.h"
#include "constants.h"

void output(int roots, double x1, double x2)
{

    switch (roots) {
        case 0:
            printf("No solutions");
            break;
        case 1:
            printf("%0.4lf", x1);
            break;
        case 2:
            printf("%0.4lf %0.4lf", x1, x2);
            break;
        case INFINITY:
            printf("An infinite number of solutions");
            break;
        default:
            printf("Error\n");
            break;
    }
}
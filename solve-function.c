//
// Created by ilyaf on 29.08.2021.
//
#include <assert.h>
#include <math.h>
#include "solve-function.h"
#include "constants.h"


// res: 0 - a = b; 1 - a > b; 2 - a < b
int compare_double(double a, double b)
{
    if (fabs(a - b) <= PRECISION) return 0;
    if (a - b > PRECISION ) return 1;
    if (a - b <- PRECISION ) return 2;
    return 0;
}

void solve_linear_equation(double a, double b, double* x)
{
    assert(x);
    assert(a != 0);
    *x = -b / a;
}

// returns the number of roots
int solve_square_equation(double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    // compare double !
    if (compare_double(a, 0) == 0 && compare_double(b, 0) == 0 && compare_double(c, 0) == 0)
    {
        return INFINITY;
    }

    if (compare_double(a, 0) == 0 && compare_double(b, 0) != 0)
    {
        solve_linear_equation(b, c, x1);
        return 1;
    }

    if (compare_double(a, 0) == 0 && compare_double(b, 0) == 0)
    {
        return 0;
    }

    double discr = b * b - 4 * a * c;
    if (compare_double(discr, 0) == 2)
    {
        return 0;
    }

    if (compare_double(discr, 0) == 1)
    {
        *x1 = (-b + sqrt(discr)) / (2 * a);
        *x2 = (-b - sqrt(discr)) / (2 * a);
        return 2;
    }

    *x1 = -b / (2 * a);
    return 1;
}

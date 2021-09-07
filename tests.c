//
// Created by ilyaf on 29.08.2021.
//

#include <assert.h>
#include <math.h>
#include "solve-function.h"
#include "tests.h"

void test_square_equation_all_coeffs_zero() {
    double x1 = NAN;
    double x2 = NAN;

    assert(compare_double(solve_square_equation(0, 0, 0, &x1, &x2), 3) == 0);
}

void test_square_equation_a_zero_b_not_zero() {
    double x1 = NAN;
    double x2 = NAN;

    assert(compare_double(solve_square_equation(0, 1, 2, &x1, &x2), 1) == 0 && compare_double(x1, -2) == 0);
}

void test_square_equation_a_zero_b_zero_c_not_zero() {
    double x1 = NAN;
    double x2 = NAN;

    assert(compare_double(solve_square_equation(0, 0, 2, &x1, &x2), 0) == 0);
}

void test_square_equation_a_not_zero_D_zero() {
    double x1 = NAN;
    double x2 = NAN;

    assert(compare_double(solve_square_equation(1, 2, 1, &x1, &x2), 1) == 0 &&
    compare_double(x1, -1) == 0);
}

void test_square_equation_a_not_zero_D_more_zero() {
    double x1 = NAN;
    double x2 = NAN;

    assert(compare_double(solve_square_equation(1, -3, 2, &x1, &x2), 2) ==0 &&
    compare_double(x1, 2) == 0 && compare_double(x2, 1) == 0);
}

void test_square_equation_a_not_zero_D_less_zero() {
    double x1 = NAN;
    double x2 = NAN;

    assert(compare_double(solve_square_equation(1, 0, 12, &x1, &x2), 0) == 0);
}

void tester() {
    test_square_equation_all_coeffs_zero();
    test_square_equation_a_zero_b_not_zero();
    test_square_equation_a_zero_b_zero_c_not_zero();
    test_square_equation_a_not_zero_D_zero();
    test_square_equation_a_not_zero_D_more_zero();
    test_square_equation_a_not_zero_D_less_zero();
}
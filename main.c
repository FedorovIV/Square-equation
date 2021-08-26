#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double PRECISION = 0.00000001;

int solve_square_equation(double a, double b, double c, double* x1, double* x2);
void solve_linear_equation(double a, double b, double* x);
void test_square_equation_all_coeffs_zero();
void test_square_equation_a_zero_b_not_zero();
void test_square_equation_a_zero_b_zero_c_not_zero();
void test_square_equation_a_and_b_and_c_not_zero();
void test_square_equation_a_not_zero_D_zero();
void test_square_equation_a_not_zero_D_more_zero();
void test_square_equation_a_not_zero_D_less_zero();

int main()
{
    double a = 0; //Coefficient before x^2
    double b = 0; //Coefficient before x
    double c = 0; //Free term

    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0;
    double x2 = 0;

    int ans = solve_square_equation(a, b, c, &x1, &x2);
    switch (ans) {
    case 0:
        printf("No solutions");
        break;
    case 1:
        printf("%0.4lf", x1);
        break;
    case 2:
        printf("%0.4lf %0.4lf", x1, x2);
        break;
    case 3:
        printf("An infinite number of solutions");
        break;
    }
    test_square_equation_all_coeffs_zero();
    test_square_equation_a_zero_b_not_zero();
    test_square_equation_a_zero_b_zero_c_not_zero();
    test_square_equation_a_not_zero_D_zero();
    test_square_equation_a_not_zero_D_more_zero();
    test_square_equation_a_not_zero_D_less_zero();
    return 0;
}

void solve_linear_equation(double a, double b, double* x)
{
    assert(x);
    assert(a != 0);
    *x = -b / a;
}
// 0 - no solutions; 1 -  one solution; 2 - two solutions; 3 - infinite solutions;
int solve_square_equation(double a, double b, double c, double* x1, double* x2) // 0 - no solutions; 1 -  one solution; 2 - two solutions; 3 - infinite solutions;
{
    assert(x1);
    assert(x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (abs(a) < PRECISION && abs(b) < PRECISION && abs(c) < PRECISION)
    {
        return 3;
    }

    if (abs(a) < PRECISION && abs(b) > PRECISION)
    {
        solve_linear_equation(b, c, x1);
        return 1;
    }

    if (abs(a) < PRECISION && abs(b) < PRECISION)
    {
        return 0;
    }

    double discr = b * b - 4 * a * c;
    if (discr < -PRECISION)
    {
        return 0;
    }

    if (discr > PRECISION)
    {
        *x1 = (-b + sqrt(discr)) / (2 * a);
        *x2 = (-b - sqrt(discr)) / (2 * a);
        return 2;
    }

    *x1 = -b / (2 * a);
    return 1;
}

void test_square_equation_all_coeffs_zero() {
    double x1 = 0;
    double x2 = 0;

    assert(solve_square_equation(0, 0, 0, &x1, &x2) == 3);
}

void test_square_equation_a_zero_b_not_zero() {
    double x1 = 0;
    double x2 = 0;

    assert(solve_square_equation(0, 1, 2, &x1, &x2) == 1 && x1 == -2);
}

void test_square_equation_a_zero_b_zero_c_not_zero() {
    double x1 = 0;
    double x2 = 0;

    assert(solve_square_equation(0, 0, 2, &x1, &x2) == 0);
}

void test_square_equation_a_not_zero_D_zero() {
    double x1 = 0;
    double x2 = 0;

    assert(solve_square_equation(1, 2, 1, &x1, &x2) == 1 && x1 == -1);
}

void test_square_equation_a_not_zero_D_more_zero() {
    double x1 = 0;
    double x2 = 0;

    assert(solve_square_equation(1, -3, 2, &x1, &x2) == 2 && x1 == 2 && x2 == 1);
}

void test_square_equation_a_not_zero_D_less_zero() {
    double x1 = 0;
    double x2 = 0;

    assert(solve_square_equation(1, 0, 12, &x1, &x2) == 0);
}

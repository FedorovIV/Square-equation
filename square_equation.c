#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const double PRECISION = 0.00000001;

int solve_square_equation(double a, double b, double c, double* x1, double* x2); 
int solve_line_equation(double a, double b, double* x);

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
    return 0;
}

int solve_line_equation(double a, double b, double* x)
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
    
    if (abs(a)<PRECISION && abs(b)<PRECISION && abs(c)<PRECISION)
    {
        return 3;
    }
    
    if (abs(a)<PRECISION && abs(b)>PRECISION)
    {
        solve_line_equation(b, c, x1);
        return 1;
    }
    
    if (abs(a)<PRECISION && abs(b)<PRECISION)
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

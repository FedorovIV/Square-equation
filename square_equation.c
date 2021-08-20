#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define tv  0.00000001 // threshold value

int solve_square_equation(double a, double b, double c, double* x1, double* x2) // 0 - no solutions; 1 -  one solution; 2 - two solutions; 3 - infinite solutions;
{
    if (a == 0 && b == 0 && c == 0)
    {
        return 3;
    }
    else if (a == 0 && b != 0)
    {
        *x1 = -c / b;
        return 1;
    }
    else if (a == 0 && b == 0)
    {
        return 0;
    }
    else
    {
        double discr = 0; // Discriminant
        discr = b * b - 4 * a * c; //Calculate the discriminant
        if (discr < -tv)
        {
            return 0;
        } else if (discr > tv)
        {
            *x1 = (-b + sqrt(discr)) / (2 * a);
            *x2 = (-b - sqrt(discr)) / (2 * a);
            return 2;
        } else
        {
            *x1 = -b / (2 * a);
            return 1;
        }
    }
}

main()
{
    double a = 0; //Coefficient before x^2
    double b = 0; //Coefficient before x
    double c = 0; //Free term
    double x1 = 0;
    double x2 = 0;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a !=a || b != b || c != c) assert(0);
    int ans = solve_square_equation(a, b, c, &x1, &x2);
    if (ans == 0)
    {
        printf("No solutions");
    }
    else if (ans == 1)
    {
        printf("%0.4lf", x1);
    }
    else if (ans == 2)
    {
        printf("%0.4lf %0.4lf", x1, x2);
    }
    else if (ans == 3)
    {
        printf("An infinite number of solutions");
    }
}



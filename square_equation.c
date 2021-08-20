#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void square_equation(double a, double b, double c)
{
    if (a == 0 && b == 0 && c == 0)
    {
        printf("An infinite number of solutions");
    }
    else if (a == 0 && b != 0)
    {
        double x1;
        x1 = -c / b;
        printf("%0.4lf", x1);

    }
    else if (a == 0 && b == 0)
    {
        printf("No solutions");
    }
    else
    {
        double discr = 0; // discriminant
        discr = b * b - 4 * a * c; //Calculate the discriminant
        if (discr < 0) printf("No solutions");
        if (discr == 0)
        {
            double x1 = -b / (2 * a);
            printf("%0.4lf", x1);
        }
        if (discr > 0)
        {
            double x1, x2;
            x1 = (-b + sqrt(discr)) / (2 * a);
            x2 = (-b - sqrt(discr)) / (2 * a);
            printf("%0.4lf %0.4lf", x1, x2);
        }
    }
}

int main()
{
    double a = 0; //Coefficient before x^2
    double b = 0; //Coefficient before x
    double c = 0; //Free member
    scanf("%lf %lf %lf", &a, &b, &c);
    square_equation(a, b, c);
}

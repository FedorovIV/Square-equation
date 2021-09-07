#include <math.h>
#include "solve-function.h"
#include "tests.h"
#include "handle_human_input.h"
#include "output.h"

int main()
{
    tester();

    double a = NAN; //Coefficient before x^2
    double b = NAN; //Coefficient before x
    double c = NAN; //Free term

    handle_human_input(&a, &b, &c);

    double x1 = NAN;
    double x2 = NAN;
    int roots = solve_square_equation(a, b, c, &x1, &x2);

    output(roots, x1, x2);

    return 0;
}

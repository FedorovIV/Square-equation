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

#pragma once

/**
    \brief Function for computing roots of quadratic equation

    Computes roots of quardratic equation <CODE>a*x^2 + b*x + c</CODE> and
    returns the number of them or <CODE>-1</CODE> in case of incorrect parameters. Roots are
    written at <CODE>root1</CODE> and <CODE>root2</CODE> addresses. If there are
    less than 2 roots, the rest are replaced with 0 starting with <CODE>root2</CODE>.
    If both roots are found, <CODE>root2</CODE> will be the greater one.
    \param a quadratic coefficient
    \param b linear coefficient
    \param c free member
    \param root1 address for first root
    \param root2 address for second root
    \returns Number of roots or <CODE>-1</CODE> in case of incorrect coefficients
*/
int solve_square_equation(double a, double b, double c, double* root1, double* root2);
#include "mytest.h"
#include "squareEq.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
    \brief Checks if two doubles are equal with <CODE>PRECISION</CODE> from tested file
    \param left First double
    \param right Second double
    \returns Result of comparison
*/
bool checkDoubleEqual(double left, double right)
{
    return fabs(left - right) < PRECISION;
}

/**
    \brief Test for equation with 2 roots
*/
bool test_2_roots()
{
    double root1, root2;
    int rootCount = solve_square_equation(1, 0, -1, &root1, &root2);
    return rootCount == 2
        && checkDoubleEqual(root1, -1)
        && checkDoubleEqual(root2, 1);
}

/**
    \brief Test for equation with 1 root
*/
bool test_1_root()
{
    double root1, root2;
    int rootCount = solve_square_equation(1, -2, 1, &root1, &root2);
    return rootCount == 1
        && checkDoubleEqual(root1, 1)
        && checkDoubleEqual(root2, 0);
}

/**
    \brief Test for equation with no real roots
*/
bool test_no_roots()
{
    double root1, root2;
    int rootCount = solve_square_equation(1, 0, 1, &root1, &root2);
    return rootCount == 0
        && checkDoubleEqual(root1, 0)
        && checkDoubleEqual(root2, 0);
}

/**
    \brief Test for non-equation (quadratic coefficient is zero).
*/
bool test_quadratic_null()
{
    double root1, root2;
    int rootCount = solve_square_equation(0, 2, 1, &root1, &root2);
    return rootCount == -1
        && checkDoubleEqual(root1, 0)
        && checkDoubleEqual(root2, 0);
}

int main()
{
    initializeTests(3);
    registerTest("2 roots", test_2_roots);
    registerTest("1 root", test_1_root);
    registerTest("no roots", test_no_roots);
    runTests();
    clearTests();
    return 0;
}
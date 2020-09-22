#include "mytest.h"
#include "squareEq.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

/**
    \brief Test for equation with 2 roots
*/
bool test_2_roots()
{
    double root1, root2;
    int rootCount = solve_square_equation(1, 0, -1, &root1, &root2);
    return ASSERT_EQUAL(rootCount, 2)
        && ASSERT_FLOAT_EQUAL(root1, -1)
        && ASSERT_FLOAT_EQUAL(root2, 1);
}

/**
    \brief Test for equation with 1 root
*/
bool test_1_root()
{
    double root1, root2;
    int rootCount = solve_square_equation(1, -2, 1, &root1, &root2);
    return ASSERT_EQUAL(rootCount, 1)
        && ASSERT_FLOAT_EQUAL(root1, 1)
        && ASSERT_FLOAT_EQUAL(root2, 0);
}

/**
    \brief Test for equation with no real roots
*/
bool test_no_roots()
{
    double root1, root2;
    int rootCount = solve_square_equation(1, 0, 1, &root1, &root2);
    return ASSERT_EQUAL(rootCount, 0)
        && ASSERT_FLOAT_EQUAL(root1, 0)
        && ASSERT_FLOAT_EQUAL(root2, 0);
}

/**
    \brief Test for non-equation (quadratic coefficient is zero).
*/
bool test_quadratic_zero()
{
    double root1, root2;
    int rootCount = solve_square_equation(0, 2, 1, &root1, &root2);
    bool result = ASSERT_EQUAL(rootCount, -1)
               && ASSERT_FLOAT_EQUAL(root1, 0)
               && ASSERT_FLOAT_EQUAL(root2, 0)
               && ASSERT_ERROR(EINVAL);
    errno = 0;
    return result;
}

bool test_root_null()
{
    double root2;
    int rootCount = solve_square_equation(0, 2, 1, NULL, &root2);
    bool result = ASSERT_EQUAL(rootCount, -1)
               && ASSERT_ERROR(EINVAL);
    errno = 0;
    return result;
}

bool test_argument_NaN()
{
    double root1, root2;
    int rootCount = solve_square_equation(0, NAN, 1, &root1, &root2);
    bool result = ASSERT_EQUAL(rootCount, -1)
        && ASSERT_FLOAT_EQUAL(root1, 0)
        && ASSERT_FLOAT_EQUAL(root2, 0)
        && ASSERT_ERROR(EDOM);
    errno = 0;
    return result;
}

bool test_infinite_argument()
{
    double root1, root2;
    int rootCount = solve_square_equation(0, INFINITY, 1, &root1, &root2);
    bool result = ASSERT_EQUAL(rootCount, -1)
        && ASSERT_FLOAT_EQUAL(root1, 0)
        && ASSERT_FLOAT_EQUAL(root2, 0)
        && ASSERT_ERROR(EDOM);
    errno = 0;
    return result;
}

int main()
{
    initializeTests(7);
    registerTest("2 roots", test_2_roots);
    registerTest("1 root", test_1_root);
    registerTest("no roots", test_no_roots);
    registerTest("non-quardratic", test_quadratic_zero);
    registerTest("Null root", test_root_null);
    registerTest("NaN argument", test_argument_NaN);
    registerTest("Infinite argument", test_infinite_argument);
    runTests();
    clearTests();
    system("pause");
    return 0;
}
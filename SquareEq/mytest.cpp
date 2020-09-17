#include "mytest.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/**
    Structure for test
*/
typedef struct
{
    const char* name;               /**< Test's name */
    TEST_FUNCTION testFunction;     /**< Test's function */
} Test;

Test* tests = nullptr;  /**< Array of tests */
int testCount = 0;      /**< Number of registered tests */
int testsLength = 0;    /**< Size of tests array */

void initializeTests(int maxTestCount)
{
    testCount = 0;
    testsLength = maxTestCount;
    tests = (Test*)calloc(maxTestCount, sizeof(Test));
#if defined(_WIN32) || defined(WIN32)
    system("color");    // For some reason, colors do not work in Visual Studio without this
#endif
}

void registerTest(const char* name, TEST_FUNCTION testFunction)
{
    if (testCount == testsLength)
    {
        puts("\x1b[31mWarning: adding more tests than expected");
        printf("\x1b[37m");
    }
    tests[testCount].name = name;
    tests[testCount].testFunction = testFunction;
    ++testCount;
}

void runTests()
{
    printf("Running all tests\n");
    int passCount = 0;
    for (int i = 0; i < testCount; ++i)
    {
        bool result = tests[i].testFunction();
        if (result)
        {
            printf("\x1b[32m\"%s\" passed\n", tests[i].name);
        }
        else
        {
            printf("\x1b[31m\"%s\" failed\n", tests[i].name);
        }
        passCount += result;
    }
    printf("\x1b[37mTotal\t%d tests\nPassed\t%d tests\nFailed\t%d tests\n", testCount, passCount, testCount - passCount);
}

void clearTests()
{
    free(tests);
}

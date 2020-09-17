#pragma once

typedef bool(*TEST_FUNCTION)(void); /**< Simplified name for test function */

/**
    \brief Initialize tests
*/
void initializeTests(int maxTestCount = 256 /**< Maximum allowed number of tests */);

/**
    \brief Register a test

    Registers function <CODE>testFunction</CODE> as test named <CODE>name</CODE>.
    The function shall return <CODE>true</CODE> if test was passed and <CODE>false</CODE>
    otherwise.
    \param name Test's name
    \param testFunction Test's function
*/
void registerTest(const char* name, TEST_FUNCTION testFunction);

/**
    \brief Run tests

    Runs all registered tests
*/
void runTests();

/**
    \brief Clear tests

    Clear tests in order to free memory
*/
void clearTests();
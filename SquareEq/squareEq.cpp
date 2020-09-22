#include "squareEq.h"
#undef __cplusplus      // Visual Studio won't let use isfinite() otherwise
#include <math.h>
#include <errno.h>

#define PRECISION 1e-7 /**< Precision of comparing float-point numbers */

int solve_square_equation(double a, double b, double c, double* root1, double* root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        errno = EINVAL;
        return -1;
    }
    if (!isfinite(a) || !isfinite(b) || !isfinite(c))
    {
        *root1 = 0;
        *root2 = 0;
        errno = EDOM;
        return -1;
    }
    if (a == 0)
    {
        // This is not a quadratic equation (quadratic coefficient is zero)
        *root1 = 0;
        *root2 = 0;
        errno = EINVAL;
        return -1;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        *root1 = 0;
        *root2 = 0;
        return 0;
    }
    if (fabs(discriminant) < PRECISION)
    {
        *root1 = -b / (2 * a);
        *root2 = 0;
        return 1;
    }
    double discriminant_root = sqrt(discriminant);
    *root1 = (-b - discriminant_root) / (2 * a);
    *root2 = (-b + discriminant_root) / (2 * a);
    return 2;
}
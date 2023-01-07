#include "logistic_map.h"

double_t log_map(double_t r, double_t x)
{
    return r*x*(1-x);
}

void logistic(double_t x0, double_t r0, double_t rf, double_t delta_r, u_int32_t pts, FILE* f)
{
    double_t r, x;
    u_int32_t i, j;
    r = r0;

    while (r < rf)
    {
        x = x0;
        for (j = 0; j < pts; ++j)
            x = log_map(r, x);

        for (i = 0; i < pts; ++i)
        {
            x = log_map(r, x);
            fprintf(f, "%lf, %lf\n", r, x);
        }
        r+=delta_r;
    }
}

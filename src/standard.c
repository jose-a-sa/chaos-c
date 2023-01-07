#include "standard.h"
#define D_PI (2.0 * M_PI)

void standard_map(double_t K, phase_point_t *ph)
{
    double_t x0, p0;
    x0 = ph->x;
    p0 = ph->p;

    ph->p = fmod(p0 + K / D_PI * sin(D_PI * x0), 1);
    ph->x = fmod(x0 + ph->p, 1);

    if (ph->x < 0)
        ph->x += 1.0;
    if (ph->p < 0)
        ph->p += 1.0;
}

void standard(double_t K, u_int32_t n, phase_point_t *ph, FILE *fx, FILE *fp)
{
    u_int32_t i, j, k;

    for (k = 0; k < n - 1; ++k)
    {
        standard_map(K, ph);
        fprintf(fx, "%lf, ", ph->x);
        fprintf(fp, "%lf, ", ph->p);
    }

    standard_map(K, ph);
    fprintf(fx, "%lf\n", ph->x);
    fprintf(fp, "%lf\n", ph->p);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "logistic_map.h"
#include "standard.h"

u_int32_t logistic_map_out()
{
	FILE *f;
	clock_t start, diff;

	start = clock();
	f = fopen("logistic.csv", "w");
	logistic(0.25, 2.8, 4.0, 0.001, 256, f);
	diff = clock() - start;
	fclose(f);

	return diff * 1000 / CLOCKS_PER_SEC;
}

u_int32_t standard_map_out()
{
	FILE *f_x, *f_p;
	clock_t start, diff;
	u_int32_t i, j, n_x, n_p;
	phase_point_t *delta, *p0;

	start = clock();
	delta = malloc(sizeof(phase_point_t));
	p0 = malloc(sizeof(phase_point_t));
	delta->x = delta->p = 0.020;
	n_x = (u_int32_t)(1 / delta->x);
	n_p = (u_int32_t)(1 / delta->p);

	f_x = fopen("standard_x.csv", "w");
	f_p = fopen("standard_p.csv", "w");

	for (i = 1; i < n_x; ++i)
		for (j = 1; j < n_p; ++j)
		{
			p0->x = delta->x * i;
			p0->p = delta->p * j;
			standard(0.6, 50, p0, f_x, f_p);
		}
	diff = clock() - start;

	fclose(f_x);
	fclose(f_p);
	free(delta);
	free(p0);

	return diff * 1000 / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[])
{
	printf("Logistic map: %u ms\n", logistic_map_out());
	printf("Standard map: %u ms\n", standard_map_out());

	return EXIT_SUCCESS;
}

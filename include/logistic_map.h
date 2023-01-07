#ifndef CHAOS_MAP_LOGISTIC_MAP_H
#define CHAOS_MAP_LOGISTIC_MAP_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double_t log_map(double_t r, double_t a);
void logistic(double_t x0, double_t r0, double_t rf, double_t delta_r, u_int32_t pts, FILE* f);

#endif //CHAOS_MAP_LOGISTIC_MAP_H

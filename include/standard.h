//
// Created by jose on 02-06-2015.
//

#ifndef CHAOS_MAP_STANDARD_H
#define CHAOS_MAP_STANDARD_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct phase_point {
    double_t x;
    double_t p;
} phase_point_t;

void standard_map(double_t k, phase_point_t* ph0);
void standard(double_t K, u_int32_t n, phase_point_t *ph0, FILE *fx, FILE *fp);

#endif //CHAOS_MAP_STANDARD_H

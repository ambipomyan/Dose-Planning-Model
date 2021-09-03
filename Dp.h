#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

typedef struct DP_DOMAIN_ {
    // size
    int nrows;
    int ncols;
    // data
    int *data; // size of nrows*ncols
    int *ndoses; // size of max_time
    // constrains
    int tol;
    int ntime;
    int max_time;
}DP_DOMAIN;

// init
int dp_init_domain();

int dp_init_dose_plan();

// util
int ad_print_domain();

// cell
int dp_classification();

int dp_apply_dose();

int dp_simulation();

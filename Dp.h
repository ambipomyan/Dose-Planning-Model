#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

typedef struct DP_DOMAIN_ {
    // size
    int nrows;
    int ncols;
    // data
    int *data; // size = nrows*ncols
    int *old_data;
    // dose
    int *ndoses; // size = max_time
    // constrains
    double resid;
    double tol;
    int ntime;
    int max_time;
}DP_DOMAIN;

// init
int dp_init_dose_plan(int *ndoses, int max_time);

int dp_init_domain(DP_DOMAIN *domain, int nrows, int ncols, int *data, int *ndoses, double tol, int max_time);

// util
int dp_print_domain(DP_DOMAIN *domain);

int dp_print_dose_plan(DP_DOMAIN *domain);

// cell
int dp_classification(DP_DOMAIN *domain);

int dp_apply_dose(DP_DOMAIN *domain);

int dp_simulation(DP_DOMAIN *domain);

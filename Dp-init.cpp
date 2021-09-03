#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

#include "Dp.h"

int dp_init_domain(DP_DOMAIN *domain, int nrows, int ncols, int *data, int *ndoses, double tol, int max_time) {
    domain->nrows = nrows;
    domain->ncols = ncols;
    domain->data = data;
    domain->old_data = data;
    domain->ndoses = ndoses;
    domain->resid = 1.0;
    domain->tol = tol;
    domain->ntime = 0;
    domain->max_time = max_time;
    
    return 0;
}

int dp_init_dose_plan(int *ndoses, int max_time) {
    // dummy dose
    for (int i = 0; i < max_time; i++) {
        ndoses[i] = -1;
    }
    
    return 0;
}

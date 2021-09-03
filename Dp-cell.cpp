#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

#include "Dp.h"

int dp_classification(DP_DOMAIN *domain) {
    // dummy classification
    for (int i = 0; i < domain->nrows; i++) {
        for (int j = 0; j < domain->ncols; j++) {
            if (domain->data[i*domain->ncols+j] >= 200) {
                domain->data[i*domain->ncols+j] = 200;
            } else if (domain->data[i*domain->ncols+j] >= 100) {
                domain->data[i*domain->ncols+j] = 100;
            } else {
                domain->data[i*domain->ncols+j] = 0;
            }
        }
    }
    
    return 0;
}

int dp_apply_dose(DP_DOMAIN *domain) {
    // dummy dose
    for (int i = 1; i < domain->nrows-1; i++) {
        for (int j = 1; j < domain->ncols-1; j++) {
            // stencil
            domain->data[i*domain->ncols+j] = (domain->old_data[(i-1)*domain->ncols+j] + \
                                               domain->old_data[i*domain->ncols+(j-1)] + \
                                               domain->old_data[i*domain->ncols+(j+1)] + \
                                               domain->old_data[(i+1)*domain->ncols+j]) / 4;
            
            if (i%2==0 && j%2==0) {
                if (domain->data[i*domain->ncols+j] == 200) {
                    domain->data[i*domain->ncols+j] = abs(4*domain->ndoses[domain->ntime] + domain->old_data[i*domain->ncols+j]);
                } else if (domain->data[i*domain->ncols+j] == 100) {
                    domain->data[i*domain->ncols+j] = abs(3*domain->ndoses[domain->ntime] + domain->old_data[i*domain->ncols+j]);
                } else {
                    domain->data[i*domain->ncols+j] = abs(5*domain->ndoses[domain->ntime] + domain->old_data[i*domain->ncols+j]);
                }
            }
        }
    }
    
    return 0;
}

int dp_simulation(DP_DOMAIN *domain) {
    // apply dose
    dp_apply_dose(domain);
    
    // resid update
    domain->resid = 0.0;
    for (int i = 0; i < domain->nrows; i++) {
        for (int j = 0; j < domain->ncols; j++) {
            domain->resid += (double)(domain->data[i*domain->ncols+j]*domain->data[i*domain->ncols+j])/(domain->nrows*domain->ncols);
        }
    }
    
    // switch pointers
    int *tmp;
    tmp = domain->old_data;
    domain->old_data = domain->data;
    domain->data = tmp;
    
    // iteration update
    domain->ntime++;
    
    return 0;
}

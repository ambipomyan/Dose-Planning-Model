#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

#include "Dp.h"

int dp_print_domain(DP_DOMAIN *domain) {
    for (int i = 0; i < domain->nrows; i++) {
        for (int j = 0; j < domain->ncols; j++) {
            printf("%*d ",4 ,domain->data[i*domain->ncols+j]);
        }
        printf("\n");
    }
    
    return 0;
}

int dp_print_dose_plan(DP_DOMAIN *domain) {
    for (int i = 0; i < domain->max_time; i++) {
        printf("%*d ",4 ,domain->ndoses[i]);
    }
    printf("\n");
    
    return 0;
}

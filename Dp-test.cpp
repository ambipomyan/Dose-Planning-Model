#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

// Add OpenCV support
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

// Add timing support
#include <sys/timeb.h>

#include "Dp.h"

using namespace cv;

int main () {
// inputs
    Mat img0 = imread("input.jpg", IMREAD_GRAYSCALE);
    if (img0.empty()) printf("Could not get image.\n");
    
    Mat img1 = img0.clone();
    
// init prediction
    int m, n;
    m = img0.cols;
    n = img0.rows;
    printf("img size: %d rows x %d cols\n", n, m);
    
    int max_time;
    double tol;
    max_time = 10;
    tol = 0.1;
    
    // get data from openCV Mat
    int *data;
    data = (int *)malloc(m*n*sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            data[i*m+j] = (int)img0.data[i*m+j];
        }
    }
    
    // init dose plan
    int *ndoses;
    ndoses = (int *)malloc(max_time*sizeof(int));
    dp_init_dose_plan(ndoses, max_time);
    
    // init domain
    DP_DOMAIN *domain;
    domain = (DP_DOMAIN *)malloc(sizeof(DP_DOMAIN_));
    dp_init_domain(domain, n, m, data, ndoses, tol, max_time);
    
    printf("dose plan:\n");
    dp_print_dose_plan(domain);
    
    printf("input image:\n");
    dp_print_domain(domain);
    
// classification
    dp_classification(domain);
    printf("classification result:\n");
    dp_print_domain(domain);
    
// simulation
    while (domain->resid > domain->tol && domain->ntime < domain->max_time) {
        // dummy test
        dp_simulation(domain);
    }
    
// outputs
    // pred image
    printf("pred image:\n");
    dp_print_domain(domain);
    
    // save to image
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            img1.data[i*m+j] = (uchar)(domain->data[i*m+j]);
        }
    }
    imwrite("pred.jpg", img1);
    
    free(data);
    free(ndoses);
    free(domain);
    
    return 0;
}

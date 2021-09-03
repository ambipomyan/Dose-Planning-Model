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
    int *arr0, *arr1, *pred;
    arr0 = (int *)malloc(m*n*sizeof(int));
    arr1 = (int *)malloc(m*n*sizeof(int));
    pred = (int *)malloc(m*n*sizeof(int));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr0[i*m+j] = (int)img0.data[i*m+j];
            arr1[i*m+j] = 0;
            pred[i*m+j] = 0;
        }
    }
    
    printf("input image:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%*d ",4 ,arr0[i*m+j]);
        }
        printf("\n");
    }
    
// classification
    // TODO
    printf("classification result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr0[i*m+j] >= 200) {
                arr1[i*m+j] = 200;
            } else if (arr0[i*m+j] >= 100) {
                arr1[i*m+j] = 100;
            } else {
                arr1[i*m+j] = 0;
            }
            printf("%*d ",4 ,arr1[i*m+j]);
        }
        printf("\n");
    }
    
// simulation
    int iters;
    double tol, resid;
    iters = 0;
    tol = 0.1;
    resid = 1.0;
    
    while (resid > tol && iters < 10) {
        // dummy-test: pred image update
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i%2==0 && j%2==0) pred[i*m+j] = 255-arr1[i*m+j];
            }
        }
        
        // resid update
        resid = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                resid += (double)(pred[i*m+j]-0)*(pred[i*m+j]-0)/(m*n);
            }
        }
        // # of iters update
        iters++;
    }
    
    //printf("Residue: %lf\n", resid);
    
// outputs
    // pred image
    printf("pred image:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%*d ",4 ,pred[i*m+j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            img1.data[i*m+j] = (uchar)(pred[i*m+j]);
        }
    }
    imwrite("pred.jpg", img1);
    
    free(arr0);
    free(arr1);
    free(pred);
    
    return 0;
}

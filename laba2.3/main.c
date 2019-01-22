#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* createarray(int n)
{
    double *a=(double*)malloc(n*sizeof(double));
    for (int i=0;i<n;i++)
        a[i]=(double)(rand()%100)/13-5;
    return a;
}

void process(double *a,int n)
{
    for (int i=2;i<n;i++)
        if (i%3==0&&a[i-1]*a[i-2]<0)
            a[i]=(a[i-1]+a[i-2])/2;
}

void printarray(double *a,int n)
{
    for (int i=0;i<n;i++)
        printf("%f ",a[i]);
    printf("\n");
}

int main()
{
    srand(time(NULL));
    double *x=NULL;
    int n=10;
    printf("Array X:\n");
    x=createarray(n);
    printarray(x,n);
    process(x,n);
    printarray(x,n);
    free(x);
    n=15;
    printf("Array Y:\n");
    x=createarray(n);
    printarray(x,n);
    process(x,n);
    printarray(x,n);
    free(x);
    n=12;
    printf("Array Z:\n");
    x=createarray(n);
    printarray(x,n);
    process(x,n);
    printarray(x,n);
    free(x);
    return 0;
}



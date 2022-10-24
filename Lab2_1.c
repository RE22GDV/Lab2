#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double uravnenie1(double);
double uravnenie2(double);
double uravnenie3(double);
double uravnenie_default();


double uravnenie1(double x){return -x;}
double uravnenie2(double x){return x;}
double uravnenie3(double x){return log10(x)+1;}
double uravnenie_default(){ return 0.00;}



int main() {
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);
    if (-100 <= x && x < -50)printf("y = %.2lf\n", uravnenie1(x));
    else if (50 <= x && x < 100) { printf("y = %.2lf\n", uravnenie2(x)); }
    else if (200 <= x && x < 1000) { printf("y = %.2lf\n", uravnenie3(x)); }
    else { printf("y = %f\n", uravnenie_default()); }
}

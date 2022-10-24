#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mathematical_expression1(double x){return -x;}
double mathematical_expression2(double x){return x;}
double mathematical_expression3(double x){return log10(x)+1;}
double mathematical_expression_default(){ return 0;}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
int main() {
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);
    if (-100 <= x && x < -50)printf("y = %.2lf\n", mathematical_expression1(x));
    else if (50 <= x && x < 100) { printf("y = %.2lf\n", mathematical_expression2(x)); }
    else if (200 <= x && x < 1000) { printf("y = %.2lf\n", mathematical_expression3(x)); }
    else { printf("y = %d\n", mathematical_expression_default()); }
}


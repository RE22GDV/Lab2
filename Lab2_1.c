#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mathematical_expression1(double x) {printf("y = %.2lf\n", -x);}
void mathematical_expression2(double x) {printf("y = %.2lf\n", x);}
void mathematical_expression3(double x) {printf("y = %.2lf\n", log10(x)+1);}
void mathematical_expression_default() {printf("y = %.2f\n", 0.00);}


int main() {
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);
    if (-100 <= x && x < -50) {mathematical_expression1(x);}
    else if (50 <= x && x < 100) {mathematical_expression2(x);}
    else if (200 <= x && x < 1000) {mathematical_expression3(x);}
    else {mathematical_expression_default();}
}

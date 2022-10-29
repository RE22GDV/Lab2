#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double e = 0.0001;

double integral(double x);
double delta(double a, double b);
double left_rectangle_method(double a, double b, unsigned int n);
double right_rectangle_method(double a, double b, unsigned int n);
double trapezium_method(double a, double b, unsigned int n);
double simps_method( double a, double b, unsigned int n);
void print_output_data(double a, double b, unsigned int n, double I, int N);


int main() {
    unsigned int choice_solution, while_flag=0, flag_text_input=0;
    double a, b, I;
    unsigned int n;

    while(while_flag!=1){
        if (flag_text_input==0){
            printf("\nThe left limit of integration: "); scanf("%lf", &a);
            printf("\nThe right limit of integration: "); scanf("%lf", &b);
            printf("\nThe number of spaces breakdown: "); scanf("%d", &n);
            printf("Methods:\n"
                   "1.Method of left rectangles\n"
                   "2.Method of right rectangles\n"
                   "3.Trapezium method\n"
                   "3.Simps's method\n"
                   "4.Method a parabola\n\n");
        }
        flag_text_input=1;
        printf("Choose a method of solution(1-4): "); scanf("%d", &choice_solution);
        system("cls");
        if(choice_solution==1){
            I=left_rectangle_method(a, b, n);
            printf("\nYou chosen Method of left rectangles");
            while_flag = 1;
        }
        else if (choice_solution==2){
            I=right_rectangle_method(a,b,n);
            printf("\nYou chosen Method of right rectangles");
            while_flag = 1;
        }
        else if (choice_solution==3){
            I=trapezium_method(a,b,n);
            printf("\nYou chosen Trapezium method");
            while_flag = 1;
        }
        else if (choice_solution==4){
            I=simps_method(a,b,n);
            printf("\nYou chosen Simps's method");
            while_flag = 1;
        }
        else {printf("\nIncorrect solution number entered\n\n"); while_flag=0;}
    }
    print_output_data(a, b, n, I, delta(a,b));
}


double integral(double x){
    double y;
    y=(pow(x,4)+(3*x));
    return y;
}

double delta(double a, double b){
    int N = 0;
    double I1, I2;
    while(fabs(I2-I1)>e){
        N = N + 2;
        I1=left_rectangle_method(a, b, N);
        I2=left_rectangle_method(a, b, N+2);
    }
    return N;
}

void print_output_data(double a, double b, unsigned int n, double I, int N){
    printf("\n============================================");
    printf("\n+----------------Input data----------------+");
    printf("\n============================================");
    printf("\n|  a=%.2lf       b=%.2lf       n=%d        |", a, b, n );
    printf("\n============================================");
    printf("\n+----------------Result--------------------+");
    printf("\n============================================");
    printf("\n|            Integral= %.8lf         |", I);
    printf("\n============================================");
    printf("\n|            N=%d                        |", N);
    printf("\n============================================");
}

double left_rectangle_method(double a, double b, unsigned int n){
    double h, x, sum = 0;
    int i = 0;
    h = (b-a)/n;
    x = a;
    for(; i <= n-1; i++){
        sum = sum + integral(x);
        x = x + h;
    }
    return sum * h;
}

double right_rectangle_method(double a, double b, unsigned int n){
    double h, x, sum = 0;
    int i = 1;
    h = (b-a)/n;
    x = a;
    for (; i <= n; i++){
        sum = sum + integral(x);
        x = x + h;
    }
    return sum * h;
}

double trapezium_method(double a, double b, unsigned int n){
    double h, x, sum = 0;
    int i = 1;
    h = (b-a)/n;
    x = a;
    for (; i <= n-1; i++){
        sum = sum+(integral(x)+integral(x+h))/2;
        x=x+h;
    }
    return sum * h;
}

double simps_method( double a, double b, unsigned int n){
    double h, x, sum = 0;
    int i = 1;
    h = (b-a)/n;
    x = a;
    for (; i < n-1; i++){
        sum = sum + (integral(x)+4*integral(x+h/2)+integral(x+h))/6;
        x = x+h;
    }
    return sum * h;
}
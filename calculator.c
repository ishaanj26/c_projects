/*
SIMPLE CALCULATOR
Code improved by Ishaan Jain
You can Copy and Learn
*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char ch;
    double a, b;
    while (1) {
        printf("Enter an operator\n+ ---->Addition\n- ---->Subtraction\n* ---->MultiplicTION\n/ ---->Division\nIf you want to exit press x: ");
        scanf(" %c", &ch);
 
        // to exit
        if (ch == 'x')
            exit(0);
        printf("Enter the first operand: ");
        scanf("%lf", &a);
        printf("Enter two second operand: ");
        scanf("%lf", &b);
 
        switch (ch) {
 
        // For Addition
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
            break;
 
        // For Subtraction
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
            break;
 
        // For Multiplication
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
            break;
 
        // For Division
        case '/':
            printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
            break;

        // If operator doesn't match any case constant
        default:
            printf(
                "Error! please write a valid operator\n");
        }
 
        printf("\n");
    }
}
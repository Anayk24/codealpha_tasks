/*
 * Basic Calculator Program in C
 * Author: Anay
 * Internship Project - CodeAlpha
 *
 * Description:
 * This program performs basic arithmetic operations
 * (Addition, Subtraction, Multiplication, Division)
 * using switch-case statements.
 */
#include <stdio.h>
int main() {
    int choice;
    double n1,n2,result;

    // Display menu
    printf("Basic Calculator\n1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4.Division (/)\nEnter your choice (1-4):");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    // Input numbers
    printf("Enter first number: ");
    scanf("%lf", &n1);
    printf("Enter second number: ");
    scanf("%lf", &n2);

    // Perform operation based on choice
    switch(choice) {
        case 1:
            result=n1+n2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result =n1-n2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result =n1*n2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            if(n2!=0) {
                result=n1/n2;
                printf("Result: %.2lf\n",result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid choice! Please select between 1-4.\n");
    }

    return 0;
}

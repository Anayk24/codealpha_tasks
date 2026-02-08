/*
 *
 * Description:
 * This program performs basic matrix operations:
 *  - Matrix Addition
 *  - Matrix Multiplication
 *  - Matrix Transpose
 *
 * It uses functions, 2D arrays, and a switch-case menu for modularity.
 */

#include <stdio.h>

// Function to add two matrices
void addMatrices(int rows, int cols, int A[50][50], int B[50][50]) {
    int C[50][50];
    printf("\nResult of Addition:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices(int r1, int c1, int A[50][50], int r2, int c2, int B[50][50]) {
    if(c1 != r2) {
        printf("\nError: Matrix dimensions not compatible for multiplication.\n");
        return;
    }
    int C[50][50];
    printf("\nResult of Multiplication:\n");
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            C[i][j] = 0;
            for(int k=0; k<c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int rows, int cols, int A[50][50]) {
    int T[50][50];
    printf("\nTranspose of Matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            T[j][i] = A[i][j];
        }
    }
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Matrix Operations\n"
           "1. Matrix Addition\n"
           "2. Matrix Multiplication\n"
           "3. Matrix Transpose\n"
           "Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int rows, cols;
            int A[50][50], B[50][50];
            printf("Enter rows and columns: ");
            scanf("%d %d", &rows, &cols);
            printf("Enter elements of first matrix:\n");
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                    scanf("%d", &A[i][j]);
            printf("Enter elements of second matrix:\n");
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                    scanf("%d", &B[i][j]);
            addMatrices(rows, cols, A, B);
            break;
        }
        case 2: {
            int r1, c1, r2, c2;
            int A[50][50], B[50][50];
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter elements of first matrix:\n");
            for(int i=0; i<r1; i++)
                for(int j=0; j<c1; j++)
                    scanf("%d", &A[i][j]);

            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);
            printf("Enter elements of second matrix:\n");
            for(int i=0; i<r2; i++)
                for(int j=0; j<c2; j++)
                    scanf("%d", &B[i][j]);

            multiplyMatrices(r1, c1, A, r2, c2, B);
            break;
        }
        case 3: {
            int rows, cols;
            int A[50][50];
            printf("Enter rows and columns: ");
            scanf("%d %d", &rows, &cols);
            printf("Enter elements of matrix:\n");
            for(int i=0; i<rows; i++)
                for(int j=0; j<cols; j++)
                    scanf("%d", &A[i][j]);
            transposeMatrix(rows, cols, A);
            break;
        }
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

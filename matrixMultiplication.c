#include <stdio.h>

#define MAX 10

// Function to input a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int sum[MAX][MAX];
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatrix Addition Result:\n");
    displayMatrix(sum, rows, cols);
}

// Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int r1, int c1, int c2) {

    int product[MAX][MAX];
    int i, j, k;

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            product[i][j] = 0;

            for(k = 0; k < c1; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication Result:\n");
    displayMatrix(product, r1, c2);
}

// Matrix Transpose
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transpose[MAX][MAX];
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of Matrix:\n");
    displayMatrix(transpose, cols, rows);
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("=====================================\n");
    printf("       MATRIX OPERATIONS IN C\n");
    printf("=====================================\n");

    printf("\n1. Matrix Addition");
    printf("\n2. Matrix Multiplication");
    printf("\n3. Matrix Transpose");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("\nEnter rows and columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter Matrix A:\n");
            inputMatrix(A, r1, c1);

            printf("\nEnter rows and columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);

            if(r1 != r2 || c1 != c2) {
                printf("Addition not possible!\n");
                return 0;
            }

            printf("Enter Matrix B:\n");
            inputMatrix(B, r2, c2);

            addMatrix(A, B, r1, c1);
            break;

        case 2:
            printf("\nEnter rows and columns of Matrix A: ");
            scanf("%d%d", &r1, &c1);

            printf("Enter Matrix A:\n");
            inputMatrix(A, r1, c1);

            printf("\nEnter rows and columns of Matrix B: ");
            scanf("%d%d", &r2, &c2);

            if(c1 != r2) {
                printf("Multiplication not possible!\n");
                return 0;
            }

            printf("Enter Matrix B:\n");
            inputMatrix(B, r2, c2);

            multiplyMatrix(A, B, r1, c1, c2);
            break;

        case 3:
            printf("\nEnter rows and columns of Matrix: ");
            scanf("%d%d", &r1, &c1);

            inputMatrix(A, r1, c1);

            transposeMatrix(A, r1, c1);
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}

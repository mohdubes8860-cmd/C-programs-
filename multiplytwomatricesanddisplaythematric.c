#include <stdio.h>

int main() {
    int m1, n1, m2, n2;
    int i, j, k;

    // Input size of first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &m1, &n1);

    // Input size of second matrix
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &m2, &n2);

    // Condition for multiplication: columns of first = rows of second
    if (n1 != m2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int A[m1][n1], B[m2][n2], C[m1][n2];

    // Input elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < m2; i++) {
        for (j = 0; j < n2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Initialize result matrix with 0
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            C[i][j] = 0;
        }
    }

    // Multiply matrices
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            for (k = 0; k < n1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display result
    printf("Resultant Matrix:\n");
    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

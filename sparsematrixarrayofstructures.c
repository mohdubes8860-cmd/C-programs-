#include <stdio.h>

struct Sparse {
    int row;
    int col;
    int val;
};

int main() {
    int m, n, i, j, k = 1, count = 0;

    // Input size of matrix
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int A[m][n];

    // Input matrix
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] != 0)
                count++;
        }
    }

    // Sparse matrix representation
    struct Sparse sp[count + 1];  // +1 for header

    sp[0].row = m;
    sp[0].col = n;
    sp[0].val = count;

    k = 1;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                sp[k].row = i;
                sp[k].col = j;
                sp[k].val = A[i][j];
                k++;
            }
        }
    }

    // Print sparse matrix
    printf("\nSparse Matrix Representation (Row Col Value):\n");
    for (i = 0; i <= count; i++) {
        printf("%d\t%d\t%d\n", sp[i].row, sp[i].col, sp[i].val);
    }

    return 0;
}

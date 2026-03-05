#include <stdio.h>

int main() {
    int n, i, j, k= 1;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int mat[n][n];

    printf("Enter elements of %dx%d matrix:\n", n, n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && mat[i][j] != 1) {
                k = 0;
                break;
            }
            if(i!=j && mat[i][j] != 0) {
                k = 0;
                break;
            }
        }
        if(k == 0) break;
    }

    if(k==1)
        printf("The matrix is an Identity Matrix.\n");
    else
        printf("The matrix is NOT an Identity Matrix.\n");

    return 0;
}

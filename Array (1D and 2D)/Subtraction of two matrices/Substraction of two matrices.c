#include<stdio.h>

int main(){
    int i,j,a[3][3],b[3][3],sub[3][3];
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Enter element for position [%d][%d] of matrix a: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Enter element for position [%d][%d] of matrix b: ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrix A:\n ");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n ");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("Sub of Matrix A and B:\n ");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            sub[i][j]=a[i][j]-b[i][j];
            printf("%d ", sub[i][j]);
        }
        printf("\n");
    }
    return 0;
}
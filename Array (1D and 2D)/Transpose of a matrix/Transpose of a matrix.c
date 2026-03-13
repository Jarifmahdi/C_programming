#include<stdio.h>

int main(){
    int a[3][3], b[3][3];
    int i, j;



    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nOriginal Matrix:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            b[j][i] = a[i][j];
        }
    }
    printf("\nTransposed Matrix:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}


#include<stdio.h>

int main(){
    int a[100],i,n,b;
    printf("How many numbers you want to input: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &a[i]);
    }
    printf("\n");
    printf("Enter the number you want to search: ");
    scanf("%d", &b);
    for(i=0; i<n; i++){
        if(a[i]==b){
            printf("The number %d is found at position %d\n", b, i+1);
            
        }
    }
}
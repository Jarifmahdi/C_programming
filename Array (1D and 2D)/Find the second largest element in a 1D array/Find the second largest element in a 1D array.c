#include<stdio.h>

int main(){
    int n,i,max,max2;
    printf("Enter how many numbers you want to compare: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    if(arr[0]>arr[1]){
        max=arr[0];
        max2=arr[1];
    }
    else{
        max=arr[1];
        max2=arr[0];
    }
    for(i=2; i<n; i++){
        if(arr[i]>max){
            max2=max;
            max=arr[i];
        }
        else if(arr[i]>max2 && arr[i]!=max){
            max2=arr[i];
        }
    }
    printf("The largest element is: %d\n", max);
    printf("The second largest element is: %d\n", max2);
    return 0;
}
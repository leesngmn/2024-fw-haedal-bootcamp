#include <stdio.h>
 
int main(void){
    int N;
    scanf("%d", &N);
 
    int arr[N];
    int max = 0;
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
    }
 
    double sum = 0; 
    for(int j=0; j<N; j++){
        sum = sum + ((double) arr[j]/max)*100; 
    }
    printf("%f\n", (double) sum/N); 
}
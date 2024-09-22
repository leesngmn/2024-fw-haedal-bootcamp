#include <stdio.h>

int main(){
    int A, B;
    -10,000 <= A, B <= 10,000;
    scanf("%d %d", &A, &B);
    if (A>B){
        printf(">");
    }
    if (A<B){
        printf("<");
    }
    if (A==B){
        printf("==");
    }

}
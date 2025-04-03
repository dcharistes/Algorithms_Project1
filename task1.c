#include <stdio.h>
#include <stdlib.h>

int arithm_sequence2(int a, int d, int n);

int main(){
    int a, d, n;

    printf("Enter the first number of arithmetic progression (a): \n");
    scanf("%d", &a);
    printf("Enter the common difference (d): \n");
    scanf("%d", &d);
    printf("Enter the term number (n): \n");
    scanf("%d", &n);

    //printf("The %dth term of the sequence using the recursion is: %d\n", n, arithm_sequence1(n, a, d));
    printf("The %dth term of the sequence using the non-recursion is: %d\n", n, arithm_sequence2( a, d, n));

    return 0; 
}


//non-recursive
int arithm_sequence2(int a, int d, int n){
    return a + (n - 1) * d;
}
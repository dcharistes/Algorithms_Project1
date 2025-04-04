#include <stdio.h>
#include <stdlib.h>

int arithm_sequence1(int a, int d, int n);
int arithm_sequence2(int a, int d, int n);

int main(){
    int a, d, n;

    printf("Enter the first number of arithmetic sequence (a): \n");
    scanf("%d", &a);
    printf("Enter the common difference number (d): \n");
    scanf("%d", &d);
    printf("Enter the term number (n): \n");
    scanf("%d", &n);

    printf("The %dth term of the sequence using the recursion is: %d\n", n, arithm_sequence1(a, d, n));
    printf("The %dth term of the sequence using the non-recursion is: %d\n", n, arithm_sequence2( a, d, n));

    return 0; 
}

//recursive 
int arithm_sequence1(int a, int d, int n) {
    if (n == 1) {
        return a;
    } else {
        return arithm_sequence1( a, d, n-1) + d;
    }
}

//non-recursive
int arithm_sequence2(int a, int d, int n){
    int i;
    int term = a; 
    for (i = 0; i < n-1; i++) {
        term += d; 
    }
    return term;
}
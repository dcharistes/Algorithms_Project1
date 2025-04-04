#include <stdio.h>
#include <math.h>

int check_prime(int num);
int sum_primes1(int n);
void sum_primes2(int n);

// Main function
int main() {
    int a, sum;
    printf("Enter the number: ");
    scanf("%d", &a);
    sum = sum_primes1(a);
    printf("sum = %d _recursive\n", sum);
    sum_primes2(a);
    return 0;
}

// prime check
int check_prime(int num) {
    if (num == 1) 
        return 0; // !prime
    
    for (int i = 2; i <= sqrt(num); i++) { // Check up to sqrt(num). factors come in pairs. if a number has a pair, one of them will be for sure >=sqrt(num). so we do not need to check over sqrt(num).
        if (num % i == 0)
            return 0; // prime
    }
    return 1; // Prime
}

//task objective. print the sum of the primes up to n. recursive
int sum_primes1(int n){
    if (n < 2)
        return 0;
    if (check_prime(n))
        return n + sum_primes1(n - 1); //in case check_prime(n) is true the number will added to the summation. 
    else                               //so in case of true this return is added to the stack waiting for sum_primes1(n-1) to compute. 
        return sum_primes1(n-1);       //when finished all the returns are added producing the sum of all primes [2,n]                                
}

// task objective. print the sum of the primes up to n. non-recursive
void sum_primes2(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (check_prime(i)) {
            sum += i;
            //printf("%d ", i);
        }
    }
    printf("sum = %d _non_recursive\n", sum);
}

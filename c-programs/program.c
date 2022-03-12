#include <stdio.h>
#include <assert.h>

int firstDigitI(int n) {
    
    while(n > 9) {
        n /= 10;
    }
    
    return n;
}

int firstDigitR(int n) {
    
    if(n < 10) return n;
    return firstDigitR(n / 10);
}

int factorialI(int n) {
    
    int fact = n;
    for(int i = n - 1;i > 1;i--) fact *= i;
    return fact;
}

int factorialR(int n) {
    
    if(n == 1) return 1;
    return factorialR(n - 1) * n;
}

int main(void) {
    
    printf("%d: %d %d\n", 1234, firstDigitI(1234), firstDigitR(1234));
    printf("%d: %d %d\n", 5, factorialI(5), factorialR(5));
    return 0;
}
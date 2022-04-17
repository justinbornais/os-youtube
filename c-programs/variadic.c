#include <stdio.h>
#include <stdarg.h> // You must include this to use the methods below.

int add(int n, ...); // Use the three dots to create the variadic function.
int add(int n, ...) {
    
    int sum = 0;
    va_list ptr; // Variable to iterate through the parameters.
    va_start(ptr, n); // Start at the first parameter.
    
    for(int i = 0;i < n;i++)
        sum += va_arg(ptr, int); // Move to the next parameter and get the value.
    
    va_end(ptr); // End the iteration.
    return sum;
}

int main(void) {
    
    // Example calls.
    printf("%d\n", add(5, 1, 2, 3, 4, 5));
    printf("%d\n", add(3, 2, 4, 6));
    return 0;
}
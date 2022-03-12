#include <stdio.h>

void swap_values(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void swap_pointers(int ** a, int ** b) {
    int *temp; // Declares a temporary pointer variable.

    // Swap the pointers.
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    
    int a = 5;
    int b = 10;
    
    int *c = &a;
    int *d = &b;
    
    int **e = &c;
    int **f = &d;
    
    int ***g = &e;
    int ***h = &f;
    
    printf("Before swapping: %d %d\n", a, b);
    swap_values(c, d);
    printf("After swapping: %d %d\n", a, b);
    
    printf("Before swapping: %d %d\n", *c, *d);
    printf("Before swapping: %p %p\n", c, d);
    swap_pointers(e, f);
    printf("After swapping: %d %d\n", *c, *d);
    printf("After swapping: %p %p\n", c, d);
    printf("After all swapping: %d %d\n", a, b);
    
    return 0;
}
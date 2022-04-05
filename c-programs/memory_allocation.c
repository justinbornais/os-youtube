#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int* array = (int*) malloc(10 * sizeof(int)); // Allocate enough memory for 10 indices. O(1)
    int* array2 = (int*) calloc(10, sizeof(int)); // Allocate enough memory for 10 indices, and initialize all to 0. O(n)
    
    int len = 10;
    char* str = (char*) malloc((len + 1) * sizeof(char)); // Allocate enough memory for the length of the string, plus the null terminator.
    
    // Check if the memory allocation failed (likely due to running out of memory).
    if(array == NULL) {
        printf("Error: out of memory.\n");
        exit(0); // This is for now, effectively the same as "return 0".
    }
    if(array2 == NULL) {
        printf("Error: out of memory.\n");
        exit(0);
    }
    if(str == NULL) {
        printf("Error: out of memory.\n");
        exit(0);
    }
    
    // Initialize some values for these arrays (you can do this however you want, including user input).
    for(int i = 0;i < 10;i++) {
        array[i] = 2 * i;
        array2[i] = i * i;
    }
    
    // Print the contents of array.
    for(int i = 0;i < 10;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Print the contents of array2.
    for(int i = 0;i < 10;i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");
    
    int* temp = (int*) realloc(array, 12 * sizeof(int)); // Used to resize array to store 12 indices instead of 10.
    /* Realloc is doing three things:
    1. malloc memory for temp.
    2. copy the contents from array to temp.
    3. free array.
    */
    
    // First check if realloc failed.
    if(temp == NULL) {
        printf("Error: out of memory.\n");
        exit(0);
    }
    
    array = temp; // Since memory allocation worked, array has been freed, so set array to temp.
    
    // Print the contents of array. The last two indices are garbage values for now.
    for(int i = 0;i < 12;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Redeclare the values of array.
    for(int i = 0;i < 12;i++) {
        array[i] = 3 * i;
    }
    
    // Print the new values of array.
    for(int i = 0;i < 12;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    char* tmp = realloc(str, (len + 2) * sizeof(char)); // Sample reallocation for str, allocating memory for 1 more character (plus the null terminator).
    if(tmp == NULL) {
        printf("Error: out of memory.\n");
        exit(0);
    }
    str = tmp;
    
    // Free the memory.
    free(array);
    array = NULL; // Set to NULL to prevent having a dangling pointer.
    
    free(array2);
    array2 = NULL;
    
    free(str);
    str = NULL;
    
    return 0;
}
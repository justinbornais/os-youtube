#include <stdio.h>

int main(void) {
    
    // READ FROM A FILE.
    
    char* str;
    int value;
    FILE* fp = fopen("filereadtest.txt", "r"); // Open file.
    if(!fp) { // Check if there was a problem with reading the file.
        printf("Error: could not open file. Exiting....\n");
        return 1;
    }
    
    fscanf(fp, "%d", &value); // Read from the file. Notice the syntax of fscanf is very similar to scanf.
    fscanf(fp, "%s", str);
    
    // Close the file.
    if(fclose(fp) == -1) {
        printf("Error: could not close the file. Exiting....\n");
        return 1;
    }
    
    // WRITE TO A FILE.
    FILE* fp2 = fopen("filewritetest.txt", "w"); // Open file. Use "a" if you want to append to the file, as "w" will overwrite the file if it already exists.
    if(!fp2) { // Check if there was a problem with reading the file.
        printf("Error: could not open file. Exiting....\n");
        return 1;
    }
    
    fprintf(fp2, "%s:\t%d\n", str, value); // Write to the file. Notice the syntax of fprintf is very similar to printf.
    
    // Close the file.
    if(fclose(fp2) == -1) {
        printf("Error: could not close the file. Exiting....\n");
        return 1;
    }
}
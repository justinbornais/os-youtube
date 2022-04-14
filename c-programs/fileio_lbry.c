#include <stdio.h>

int main(void) {
    
    // Read a file.
    char* str;
    int value;
    FILE* fp = fopen("filereadtest.txt", "r");
    if(!fp) {
        printf("Error: could not open file. Exiting....\n");
        return 1;
    }
    
    fscanf(fp, "%d", &value);
    fscanf(fp, "%s", str);
    if(fclose(fp) == -1) {
        printf("Error: could not close the file. Exiting....\n");
        return 1;
    }
    
    // Write to a file.
    FILE* fp2 = fopen("filewritetest.txt", "w");
    
    fprintf(fp2, "%s:\t%d\n", str, value);
    if(fclose(fp2) == -1) {
        printf("Error: could not close the file. Exiting....\n");
        return 1;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a string to a 2D array.
// Requires:
//     str is an index of a 2D array.
//     value is a string.
void add_node(char ** str, char * value);
void add_node(char ** str, char * value) {
    
    *str = (char *) malloc((strlen(value) + 1) * sizeof(char)); // Allocate enough memory for the string and null terminator.
    strcpy(*str, value); // Copy the string into the 2D array.
}

int main(void) {
    
    // Create jagged 2D array.
    int numStrings = 10;
    char ** str_array = (char **) malloc(numStrings * sizeof(char *)); // Dynamic 2D array of chars (or array of strings).
    
    // Now we add nodes.
    add_node(&str_array[0], "Some String");
    add_node(&str_array[1], "Some Other String");
    add_node(&str_array[2], "Isn't C amazing?");
    add_node(&str_array[3], "This is such an amazing thing to implement!");
    add_node(&str_array[4], "Don't you see the potential in this?");
    add_node(&str_array[5], "Come on! You have to see the potential in this!");
    add_node(&str_array[6], "In a world where life is ten times longer, you can live ten times longer.");
    add_node(&str_array[7], "What great potential this has, really.");
    add_node(&str_array[8], "This really shows that you know your dynamic memory allocation!");
    
    {
    add_node(&str_array[9], "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\
\n\
void add_node(char ** str, char * value);\n\
void add_node(char ** str, char * value) {\n\
    \n\
    *str = (char *) malloc((strlen(value) + 1) * sizeof(char));\n\
    strcpy(*str, value);\n\
}\n\
\n\
int main(void) {\n\
    \n\
    int numStrings = 10;\n\
    char ** str_array = (char **) malloc(numStrings * sizeof(char *)); // Dynamic 2D array of chars (or array of strings).\n\
    \n\
    // Now we add nodes.\n\
    add_node(&str_array[0], \"Some String\");\n\
    add_node(&str_array[1], \"Some Other String\");\n\
    add_node(&str_array[2], \"Isn't C amazing?\");\n\
    add_node(&str_array[3], \"This is such an amazing thing to implement!\");\n\
    add_node(&str_array[4], \"Don't you see the potential in this?\");\n\
    add_node(&str_array[5], \"Come on! You have to see the potential in this!\");\n\
    add_node(&str_array[6], \"In a world where life is ten times longer, you can live ten times longer.\");\n\
    add_node(&str_array[7], \"What great potential this has, really.\");\n\
    add_node(&str_array[8], \"This really shows that you know your dynamic memory allocation!\");\n\
    add_node(&str_array[9], \"Some String\");\n\
    \n\
    for(int i = 0;i < numStrings;i++) printf(\"%d: \\\"%s\\\"\\n\", strlen(str_array[i]), str_array[i]);\n\
}");
    }
    
    // Print contents of jagged 2D array.
    for(int i = 0;i < numStrings;i++) printf("%d: \"%s\"\n", strlen(str_array[i]), str_array[i]); // Loop through each string and print them.
    
    // Free contents of the jagged array.
    for(int i = 0;i < numStrings;i++) free(str_array[i]); // Free each string by itself.
    free(str_array); // Free the 2D array itself.
    str_array = NULL; // Set to NULL to prevent a dangling pointer.
    
    return 0;
}
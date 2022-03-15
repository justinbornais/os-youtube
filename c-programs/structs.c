#include <stdio.h>
#include <string.h>

struct student {
    int id;
    char name[20];
};

union epicunion {
    int count;
    float worth;
    char array[20];
};

int main(void) {
    
    struct student s1;
    s1.id = 5784350;
    strcpy(s1.name, "Johnny");
    
    struct student s2 = {9587345, "Maxwell"};
    //struct student s3 = {"Jack", 45723}; // Bad code - won't work.
    
    printf("%s has an ID of %d.\n", s1.name, s1.id);
    printf("%s has an ID of %d.\n", s2.name, s2.id);
    //printf("%s has an ID of %d.\n", s3.name, s3.id);
    
    struct student * student_ptr = &s1;
    printf("Pointer student %s has an ID of %d.\n", student_ptr->name, student_ptr->id);
    struct student students[5];
    
    
    union epicunion epic;
    epic.worth = 110.3;
    strcpy(epic.array, "C Program");
    epic.count = 55;
    printf("Union data: %d %f %s\n", epic.count, epic.worth, epic.array);
    return 0;
}
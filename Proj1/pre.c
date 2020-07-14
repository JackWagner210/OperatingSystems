#include <stdio.h>

int main() 
{
    struct Student
    {
        char name[20];
        float gpa;
    };

    int used = 0;
    struct Student students[20];
    
    printf("%s", "Enter student name and GPA:\n");

    while(scanf("%s %f", students[used].name, &students[used].gpa) != EOF)
        used++;

    int i;
    for(i = 0; i < used; i++)
        if(students[i].gpa >= 3.0)
            printf("%s\n", students[i].name);
    return 0;
}


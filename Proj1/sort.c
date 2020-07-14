
#include <stdio.h>
#include <string.h>

int main()
{
    
    int used = 0, i, j;
    char students[20][20];
    char temp[20];
    float garbage[20];

    while(scanf("%s %f", students[used], &garbage[used]) != EOF)
        used++;

    for(i = 0; i < used; i++)
    {
        for(j = i + 1; j< used; j++)
        {
	    if(strcmp(students[i], students[j]) >0)
	    {
		strcpy(temp, students[i]);
		strcpy(students[i], students[j]);
		strcpy(students[j], temp);
	    } 	
        }
    }

    printf("%s\n\nSorted:\n\n");
 
    for(i = 0; i < used; i++)
        printf("%s\n", students[i]);
    return 0;
}

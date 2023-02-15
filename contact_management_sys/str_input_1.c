#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter Name: ");
    
    char *answer=NULL;
    int i = 0;
    
    int c;
    
    while((c = getchar()) !='\n'){
        answer = (char *)realloc(answer,i+1);
        answer[i] = (char)c; 
        ++i;    
    }
    
    answer = (char *)realloc(answer,i+1);
    answer[i] = '\0';
    
    printf("%s",answer);
    
    free(answer);
    return 0;
}

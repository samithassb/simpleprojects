#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    char *number;
    char *email;
    char *address;
}contact;

contact add_contact();
char *get_answer(char *prompt);

int main()
{
    contact new_contact;
    new_contact=add_contact();
    
    printf("%s\n",new_contact.name);

    free(new_contact.name);
    free(new_contact.number);
    free(new_contact.email);
    free(new_contact.address);

    return 0;
}

contact add_contact()
{
    contact person = {
        get_answer("Name: "),
        get_answer("Number: "),
        get_answer("Email: "),
        get_answer("Address: ")
    };
    return person;
}

char *get_answer(char *prompt)
{
    char *answer=(char *)malloc(sizeof(char)*50);
    printf("%s\n",prompt);
    scanf("%s", answer);

    return answer;
}

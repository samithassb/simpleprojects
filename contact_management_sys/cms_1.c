#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact
{
	char *name;
	char *number;
	char *email;
	char *address;
	struct contact *next; 
}contact;

int main(int argc, char const *argv[])
{
	printf("//Welcome to Contact Management Stystem//\n");
	
	printf("\t\tMAIN MENU \n");
	
	printf("1.Add new contact\n");
	printf("2.List alla contact\n");
	printf("3.Search for contact\n");
	printf("4.Edit contact\n");
	printf("5.Delete contact\n");
	printf("0.Exit");

	int choice = get_user_choice();
	
	if(choice==0)
		exit(0);
	choice_execute(choice);

	return 0;
}

int get_user_choice()
{
	while(1){
		choice = get_integer("Enter your choice: ");
		if(choice<6 && choice>-1)
			break;
	}

	return choice;
}

int get_integer(char *prompt)
{	
	int integer;
	printf("%s", prompt);
	scanf("%d", &integer);

	return integer;
}

int choice_execute(int choice)
{	
	switch (choice){
		case 1:
			add_new_contact();
			break;
		case 2:
			list_all_contact();
			break;
		case 3:
			search_for_contact();
			break;
		case 4:
			edit_contact();
			break;
		case 5:
			delete_contact();
			break;
	}

	return 0;
}

int add_new_contact()
{
	name = get_answer("Name: ");
    number = get_answer("Number: ");
    email = get_answer("Email: ");
    address = get_answer("Address: ");

	FILE *contact_book = fopen("contact.csv", "a");
	fprintf(contact_book, "%s,%s,%s,%s\n", name,number,email,address);
	fclose(contact_book);

	free(name);free(number);free(email);free(address);

	printf("Successfully added contact");
	return 0;
}

char *get_answer(char *prompt)
{
	char *answer=(char *)malloc(sizeof(char)*50);
	if(answer==NULL){
		printf("Error! can't add contact");
		return NULL;
	}

	printf("%s\n",prompt);
	scanf("%s", answer);

	return answer;
}

int list_all_contact()
{
	printf("Name,Number,Email,Address\n");

	FILE *contact_book = fopen("contact.csv", "r");
	if(contact_book==NULL){
		printf("Error! occured while opening csv file");
		return 1;
	}
	char detail[100];
	while(fgets(detail,100,contact_book)!=EOF){
		detail[strcspn(detail,'\n')]=0;
		printf("%s\n\n",detail);
	}
	fclose(contact_book);
	return 0;
}

int search_for_contact()
{
	char *name;
	name = get_answer("What contact you are looking for: ");


	FILE *contact_book = fopen("contact.csv", "r");
	if(contact_book==NULL){
		printf("Error! occured while opening csv file");
		return 1;
	}
	char detail[100];
	while(fgets(detail,100,contact_book)!=EOF){
		size_t index = strcspn(detail,',');
		char fname[index+1];    

		for(int i=0;i<index;i++){
			fname[i]=detail[i];
		}

		if(strcmp(fname,name) == 0){
			printf("%s\n",detail);
		}else{
			printf("Sorry! couldn't find number")
		}
		fname[0]=0;

	}
	fclose(contact_book);
	return 0;
}

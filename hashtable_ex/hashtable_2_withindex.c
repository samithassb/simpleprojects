#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash_function(char string[]); //hash function declartion

//create node structure
typedef struct node{
    char name[100];
    int index;
    struct node* next;
}node;

//create hash table
node* hashtable[26];

int main(){
    //assign NULL to hashtable elements
    for(int j=0;j<26;j++){        
        hashtable[j]=NULL;
    }
    
    //open file
    FILE* myfile;
    myfile = fopen("name.csv", "r");
    //check file's avalability
    if(myfile==NULL){
        printf("error occured while opening file");
        return 1;
    }
    
    char ch[100];
    int indexnum=1;
    //read file line by line 
    while(fgets(ch, 100, myfile)){ 
      //remove new line character
      ch[strcspn(ch,"\n")]=0;
      //create node for ch in heap
      node* n = malloc(sizeof(node));
      //ckeck malloc avalability
      if(n==NULL){
          printf("error occured creating node");
          return 1;
      }
      strcpy(n->name, ch);  //assign string to node->name
      n->index=indexnum; //assign index number to node index
      n->next=NULL;  //assign NULL to next node's address

      //get hash code
      int key = hash_function(ch);

      //linking node to hashtable
      if(hashtable[key]==NULL){
          hashtable[key]=n;
      }else{
          n->next=hashtable[key];
          hashtable[key]=n;
      }
      indexnum++; //increase index number by one
    }
  
    //close file
    fclose(myfile);
  
    //get user input
    char inname[100];
    printf("Enter name: ");
    scanf("%s", inname);
    int inkey = hash_function(inname);

    //searching user input through linked list
    node* tmp=hashtable[inkey];
    while(tmp!=NULL){
      if(strcmp(tmp->name,inname)==0){ 
        printf("found, index: %d\n", tmp->index);
        return 0;
        }
      tmp=tmp->next;
    }
    printf("not found\n");
    return 1; 

    //free up memory
    for(int k=0;k<26;k++){
        node* temp=hashtable[k];
        hashtable[k]=NULL;
        while(temp!=NULL){
              node* next1 = temp->next;
              free(temp);
              temp=next1;
        }
    }
    return 0;
}

//create hash function
int hash_function(char string[]){
    int sum = 0;
    for(int i=0;string[i]!='\0';i++){
        sum+=string[i];
    }
    return sum%26;
}

/*reverse linked list*/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;               //create node structure  

node *head=NULL;     //head of linked list 

node *createNewNode(int x){
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode==NULL){
        printf("error occured creating new node");
        return NULL;
    }
    newNode->data = x;
    newNode->next = NULL;
    
    return newNode;
}                           //create new node 

int insertNewNode(int x){
    node *newNode = createNewNode(x);
    if(head==NULL){
        head = newNode;
        return 0;
    }
    newNode->next = head;
    head = newNode;
    return 0;
}                           //insert new node to l.list                


int nodeCount(){
    if(head==NULL)
        return 1;
    int i=0;
    node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        i++;
    } 
    return i;
}  
int reverselist(){
    if(head==NULL || head->next==NULL)
        return 1;
    
    node *temp=head;
    int i = nodeCount();
    node *(ptr[i]);
    
    for(int j=0;j<i;j++){
        ptr[j]=temp;
        temp=temp->next;
        ptr[j]->next=NULL;
    }
    
    for(int j=0;j<i-1;j++){
        ptr[i-1-j]->next=ptr[i-2-j];
    }
 
    head=ptr[i-1];
    return 0;
}                           //reverse linked list                

int print(){
    if(head==NULL)
        return 0;
    node *temp=head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp=temp->next;
    }
    printf("\n");
    return 0;
}                           //print linked list

int main(){
    insertNewNode(2);        
    insertNewNode(5);
    insertNewNode(7);
    insertNewNode(8);
    print();
    reverselist();
    print();

    return 0;
}

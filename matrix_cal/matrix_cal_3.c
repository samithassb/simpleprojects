#include <stdio.h>
#include <stdlib.h>

//function declartion
int userChoice();
int choiceExecute(int choice);
int getRowsColumns(int *row,int *column,char ch);
int *getmatrix(int row,int column,char ch);
int addition(int *A,int *B);
int subtract(int *A,int *B);
int multiply(int *A,int *B);
int smultiply(int scalar,int *A);

//global variables
int rA,cA;  //row_A , column_A
int rB,cB;  //row_B , column_B

//main function
int main(void){
    printf("Operation menu\n");
    printf("\t1.Add\n\t2.Subtract\n");
    printf("\t3.Scalar Multiply\n\t4.Multiply two matrices\n");
    
    userChoice();
    return 0;
}

//matrices addition function
int addition(int *A,int *B){
    printf("\nThe Sum of matrix A + matrix B is :\n\n");
    int M[rA][cA];     //because rA==rB & cA==cB
    for(int i=0;i<rA;i++){
        for(int j=0;j<cA;j++){
            M[i][j]=A[i*cA+j]+B[i*cB+j];
            printf("\t%d", M[i][j]);
        }        
        printf("\n");
    }
    printf("\n");
    return 0;
}

//matrices subtraction function
int subtract(int *A,int *B){
    printf("\nThe difference between matrix A - matrix B is :\n\n");
    int M[rA][cA];     //because rA==rB & cA==cB
    for(int i=0;i<rA;i++){
        for(int j=0;j<cA;j++){
            M[i][j]=A[i*cA+j]-B[i*cB+j];
            printf("\t%d", M[i][j]);
        }        
        printf("\n");
    }
    printf("\n");
    return 0;
}

//matrices multiplication function
int multiply(int *A,int *B){
    printf("\nMultiply of matrix A * matrix B is :\n\n");
    int M[rA][cB];                 
    for(int i=0;i<rA;i++){
        for(int j=0;j<cB;j++){
            M[i][j]=0;
            for(int k=0;k<cA;k++){      //cA==rB
                M[i][j]+=A[i*cA+k]*B[j+k*cB];
            }
            printf("\t%d", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

//scalar matrix multiplication function
int smultiply(int scalar,int *A){
    printf("\nThe scalar multiplication between matrixA * 2 is:\n\n");
    int M[rA][cA];    
    for(int i=0;i<rA;i++){
        for(int j=0;j<cA;j++){
            M[i][j]=scalar * A[i*cA+j];
            printf("\t%d", M[i][j]);
        }        
        printf("\n");
    }
    printf("\n");
    return 0;
}

//get user chioce
int userChoice(){
    
    int choice;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if(choice>0 && choice<5){
            choiceExecute(choice);
            return 0;
        }
        printf("Invalid input\n");
    }
}

//user choice execute
int choiceExecute(int choice){
    int *A,*B; 
    
    switch(choice){
        case 1:
        case 2:
            getRowsColumns(&rA,&cA,'A');
            getRowsColumns(&rB,&cB,'B');
            
            if(rA!=rB && cA!=cB){
                printf("Erorr!!! Invalid inputs (different dimention matrices)\n\n");
                choiceExecute(choice);
            }else if(rA!=rB){
                printf("Erorr!! Rows are not equal\n\n");
                choiceExecute(choice);
            }
            else if(cA!=cB){
                printf("Erorr!! Columns are not equal\n\n");
                choiceExecute(choice);
            }else{
                A=getmatrix(rA,cA,'A');
                B=getmatrix(rB,cB,'B');
                if(choice==1)
                    addition(A,B);
                else
                    subtract(A,B);
            }
            
            if(A!=NULL)
                free(A);
            if(B!=NULL)
                free(B);
                
            break;
            
        case 3:
            int scalar;
            printf("\nEnter scalar: ");
            scanf("%d", &scalar);
        
            getRowsColumns(&rA,&cA,'A');
            A=getmatrix(rA,cA,'A');
            
            smultiply(scalar,A);
            
            if(A!=NULL)
                free(A);
            
            break;
            
        case 4:
            getRowsColumns(&rA,&cA,'A');
            getRowsColumns(&rB,&cB,'B');
            
            if(cA!=rB){
                printf("Erorr! Invalid input (must equal columns of A & rows of B)\n\n");
                choiceExecute(4);
            }
            else{
                A=getmatrix(rA,cA,'A');
                B=getmatrix(rB,cB,'B');
                multiply(A,B);
            }
            
            if(A!=NULL)
                free(A);
            if(B!=NULL)
                free(B);
                
            break;
    }
    
    //ask from user to repeat
    int repeat=0;
    printf("Do you want to repeat (if Yes-1/if No-0): ");
    scanf("%d", &repeat);
    if(repeat==1){
        userChoice();
    }else{
        printf("thanks you");
        return 0;
    }
}

//get user input for marix rows and columns
int getRowsColumns(int *row,int *column,char ch){
    while(1){
        printf("\nEnter number #rows and #columns of %c: ", ch);
        scanf("%d %d", row, column);
        if(*row>0 && *column>0)
            return 0;
        printf("Erorr! enter valid inputs(must rows & columns > 0)\n");
    }
}

//create matrix (get inputs from user)
int *getmatrix(int row,int column,char ch){
    
    int elements=row*column;
    int *matrix=(int *)malloc(sizeof(int)*elements);
    if(matrix==NULL){
        printf("Erorr occured (in system) while creating matrix");
        return NULL;
    }
    
    printf("\nEnter elements of matrix %c (%d x %d) :\n", ch,row, column);
    for(int i=0;i<row;i++){
        printf("%d entries of row %d: ",column, i+1);
        for(int j=0;j<column;j++){
            scanf("%d", &matrix[i*column+j]);
        }
    }
    
    printf("\n\tMatrix %c\n\n",ch);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
        printf("\t%d", matrix[i*column+j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return matrix;
}

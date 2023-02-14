#include <stdio.h>
#include <stdlib.h>

//function declartion
int *getmatrix(int row,int column);
int userChoice();
int addition(int *A,int *B);
int smultiply(int scalar,int *A);
int multiply(int *A,int *B);
int subtract(int *A,int *B);
//global variables
int rA,cA;  //row_A , column_A
int rB,cB;  //row_B , column_B

//main function
int main(void){
    printf("Operation menu\n");
    printf("    1.Add\n    2.Subtract\n");
    printf("    3.Scalar Multiply\n    4.Multiply two matrices\n");
    
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
            printf("    %d    ", M[i][j]);
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
            printf("    %d    ", M[i][j]);
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
            printf("    %d", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

//scalar matrix multiplication function
int smultiply(int scalar,int *A){
    printf("\nThe scalar multiplication between matrixA * 2 is:\n\n");
    int M[rA][cA];     //because rA==rB & cA==cB
    for(int i=0;i<rA;i++){
        for(int j=0;j<cA;j++){
            M[i][j]=scalar * A[i*cA+j];
            printf("    %d    ", M[i][j]);
        }        
        printf("\n");
    }
    printf("\n");
    return 0;
}

//get user chioce
int userChoice(){
    
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    
    int *A,*B; 
    printf("Enter number #rows and #columns of A: ");
    scanf("%d %d", &rA, &cA);
    A=getmatrix(rA,cA);
    
    if(choice==1 || choice==2 || choice==4){
        
        printf("Enter number #rows and #columns of B: ");
        scanf("%d %d", &rB, &cB);
        B=getmatrix(rB,cB);
        
        if(choice==1 || choice==2){
            if(rA!=rB && cA!=cB){
                printf("error! Invalid inputs (different dimention matrices)");
                return 1;
            }
            if(choice==1)
                addition(A,B);
            else
                subtract(A,B);
        }else{
            if(cA!=rB){
                printf("error! Invalid input (must equal columns of A & rows of B)");
                return 1;
            }
            multiply(A,B);
        }
        if(B!=NULL)
            free(B);
    }else if(choice==3){
        int scalar;
        printf("Enter scalar: ");
        scanf("%d", &scalar);
        
        smultiply(scalar,A);
    }else{
        printf("error! Invalid input");
        return 1;
    }
    
    if(A!=NULL){
        free(A);
    }
    
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

//create matrix (get inputs from user)
int *getmatrix(int row,int column){
    
    if(row<0 || column<0){
        printf("Error! enter valid inputs");
        return NULL;
    }
    
    int elements=row*column;
    int *matrix=(int *)malloc(sizeof(int)*elements);
    if(matrix==NULL){
        printf("Error occured creating matrix");
        return NULL;
    }
    
    printf("Enter elements of %d x %d matrix\n", row, column);
    for(int i=0;i<row;i++){
        printf("%d entries of row %d: ",column, i+1);
        for(int j=0;j<column;j++){
            scanf("%d", &matrix[i*column+j]);
        }
    }
    
    printf("\n  input matrix \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
        printf("    %d", matrix[i*column+j]);
        }
        printf("\n");
    }
    
    return matrix;
}

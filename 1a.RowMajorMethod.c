#include <stdio.h>
int main(){
    int a[10][10],r,c,i,j;
    printf("\nManikant Kumar - PCEA25CS096\n");

    printf("\nEnter no. of Rows and Columns:\n");
    scanf("%d %d",&r,&c);
    printf("Enter elements of the matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Row Major Array is:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Address of a[%d][%d] is %p \n",i,j,(void*)&a[i][j]);
        }
    }

    return 0;
}
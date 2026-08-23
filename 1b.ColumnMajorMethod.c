#include <stdio.h>
int main(){
    int a[10][10],r,c,i,j;
    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nEnter no. of Rows and Columns:\n");
    scanf("%d %d",&r,&c);
    printf("Enter elements of the matrix:\n");
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            scanf("%d",&a[j][i]);
        }
    }
    printf("Column Major Array is:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            printf("Address of a[%d][%d] is %p \n",j,i,(void*)&a[j][i]);
        }
    }

    return 0;
}
            
#include <stdio.h>
int main() 
{
    printf("\nManikant Kumar - PCEA25CS096\n");
    int a[10][10], b[10][10];
    int sparse1[100][3];
    int sparse2[100][3];
    int sum[200][3];
    int transpose[200][3];
    int r, c;
    int count1, count2;
    int i, j, k;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter first matrix:\n");
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    count1 = 0;
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            if(a[i][j] != 0)
            {
                count1++;
            }
        }
    }
    sparse1[0][0] = r;
    sparse1[0][1] = c;
    sparse1[0][2] = count1;
    k = 1;
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            if(a[i][j] != 0)
            {
                sparse1[k][0] = i;
                sparse1[k][1] = j;
                sparse1[k][2] = a[i][j];
                k++;
            }
        }
    }
    printf("\nEnter second matrix:\n");
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    count2 = 0;
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            if(b[i][j] != 0)
            {
                count2++;
            }
        }
    }
    sparse2[0][0] = r;
    sparse2[0][1] = c;
    sparse2[0][2] = count2;
    k = 1;
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            if(b[i][j] != 0)
            {
                sparse2[k][0] = i;
                sparse2[k][1] = j;
                sparse2[k][2] = b[i][j];
                k++;
            }
        }
    }
    printf("\nSparse Matrix 1:\n");
    for(i = 0; i <= count1; i++)
    {
        printf("%d %d %d\n",
               sparse1[i][0],
               sparse1[i][1],
               sparse1[i][2]);
    }
    printf("\nSparse Matrix 2:\n");
    for(i = 0; i <= count2; i++)
    {
        printf("%d %d %d\n",
               sparse2[i][0],
               sparse2[i][1],
               sparse2[i][2]);
    }
    i = 1;
    j = 1;
    k = 1;
    while(i <= count1 && j <= count2)
    {
        if(sparse1[i][0] == sparse2[j][0] &&
           sparse1[i][1] == sparse2[j][1])
        {
            sum[k][0] = sparse1[i][0];
            sum[k][1] = sparse1[i][1];
            sum[k][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
            k++;
        }
        else if(sparse1[i][0] < sparse2[j][0] ||
               (sparse1[i][0] == sparse2[j][0] &&
                sparse1[i][1] < sparse2[j][1]))
        {
            sum[k][0] = sparse1[i][0];
            sum[k][1] = sparse1[i][1];
            sum[k][2] = sparse1[i][2];
            i++;
            k++;
        }
        else
        {
            sum[k][0] = sparse2[j][0];
            sum[k][1] = sparse2[j][1];
            sum[k][2] = sparse2[j][2];
            j++;
            k++;
        }
    }
    while(i <= count1)
    {
        sum[k][0] = sparse1[i][0];
        sum[k][1] = sparse1[i][1];
        sum[k][2] = sparse1[i][2];
        i++;
        k++;
    }
    while(j <= count2)
    {
        sum[k][0] = sparse2[j][0];
        sum[k][1] = sparse2[j][1];
        sum[k][2] = sparse2[j][2];
        j++;
        k++;
    }
    sum[0][0] = r;
    sum[0][1] = c;
    sum[0][2] = k - 1;
    printf("\nAddition of Sparse Matrices:\n");
    for(i = 0; i <= sum[0][2]; i++)
    {
        printf("%d %d %d\n",
               sum[i][0],
               sum[i][1],
               sum[i][2]);
    }
    transpose[0][0] = sum[0][1];
    transpose[0][1] = sum[0][0];
    transpose[0][2] = sum[0][2];
    k = 1;
    for(j = 1; j <= c; j++)
    {
        for(i = 1; i <= sum[0][2]; i++)
        {
            if(sum[i][1] == j)
            {
                transpose[k][0] = sum[i][1];
                transpose[k][1] = sum[i][0];
                transpose[k][2] = sum[i][2];
                k++;
            }
        }
    }
    printf("\nTranspose of Addition Matrix:\n");
    for(i = 0; i <= transpose[0][2]; i++)
    {
        printf("%d %d %d\n",
               transpose[i][0],
               transpose[i][1],
               transpose[i][2]);
    }
    return 0;
}
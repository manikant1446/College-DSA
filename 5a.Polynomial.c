#include<stdio.h>
int main()
{
    printf("\nManikant Kumar - PCEA25CS096\n");
    int p1[10], p2[10], deg1, deg2, maxDeg, sum[10],i;
    printf("Enter the degree of polynomial 1: ");
    scanf("%d",&deg1);
    printf("Enter the degree of polynomial 2: ");
    scanf("%d",&deg2);
    if(deg1>=deg2)
    {
        maxDeg = deg1;
    }else {
        maxDeg = deg2;
    }
    for (i=0; i<=deg1; i++)
    {
        printf("Value of coeff %d in polynomial 1:",i);
        scanf("%d",&p1[i]); 
    }
    for (i=0; i<=deg2; i++)
    {
        printf("Value of coeff %d in polynomial 2:",i);
        scanf("%d",&p2[i]);
    }
    for(i=0; i<=maxDeg; i++) 
    {
        sum[i] = 0;
        if(i<= deg1) 
        {
            sum[i] = sum[i] + p1[i];
        }
        if(i<= deg2)
        {
            sum[i] = sum[i] + p2[i];
        }
    }
    for(i=maxDeg; i>= 0; i--) 
    {
        if(i!= maxDeg && sum[i] >0) 
        {
            printf("+");
        }
        if(i==0) 
        {
            printf("%d",sum[i]);
        }else if(i==1) {
            printf("%dx",sum[i]);
        }else {
            printf("%dx^%d",sum[i],i);
        }
    }
    return 0;
}
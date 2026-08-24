#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int power;
    struct node *next;
};
struct node* createNode(int coeff, int power)
{
    struct node *NEW;
    NEW = (struct node*)malloc(sizeof(struct node));
    NEW->coeff = coeff;
    NEW->power = power;
    NEW->next = NULL;
    return NEW;
}
struct node* insert(struct node *start, int coeff, int power)
{
    struct node *NEW, *ptr;
    if(coeff == 0)
    {
        return start;
    }
    NEW = createNode(coeff, power);
    if(start == NULL)
    {
        start = NEW;
    }
    else
    {
        ptr = start;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NEW;
    }
    return start;
}
struct node* addPolynomial(struct node *p1, struct node *p2)
{
    struct node *sum = NULL;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->power == p2->power)
        {
            sum = insert(sum, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->power > p2->power)
        {
            sum = insert(sum, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else
        {
            sum = insert(sum, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }
    while(p1 != NULL)
    {
        sum = insert(sum, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while(p2 != NULL)
    {
        sum = insert(sum, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return sum;
}
void display(struct node *start)
{
    struct node *ptr = start;
    int first = 1;
    if(start == NULL)
    {
        printf("0");
        return;
    }
    while(ptr != NULL)
    {
        if(!first && ptr->coeff > 0)
        {
            printf(" + ");
        }
        if(ptr->power == 0)
        {
            printf("%d", ptr->coeff);
        }
        else if(ptr->power == 1)
        {
            printf("%dx", ptr->coeff);
        }
        else
        {
            printf("%dx^%d", ptr->coeff, ptr->power);
        }
        first = 0;
        ptr = ptr->next;
    }
}
int main()
{
    printf("\nManikant Kumar - PCEA25CS096\n");
    struct node *p1 = NULL, *p2 = NULL, *sum = NULL;
    int deg1, deg2, coeff, i;
    printf("\nEnter the degree of polynomial 1: ");
    scanf("%d", &deg1);
    printf("Enter the degree of polynomial 2: ");
    scanf("%d", &deg2);
    printf("\nEnter coefficients of polynomial 1:\n");
    for(i = deg1; i >= 0; i--)
    {
        printf("Value of coeff of x^%d: ", i);
        scanf("%d", &coeff);
        p1 = insert(p1, coeff, i);
    }
    printf("\nEnter coefficients of polynomial 2:\n");
    for(i = deg2; i >= 0; i--)
    {
        printf("Value of coeff of x^%d: ", i);
        scanf("%d", &coeff);
        p2 = insert(p2, coeff, i);
    }
    sum = addPolynomial(p1, p2);
    printf("\nPolynomial 1: ");
    display(p1);
    printf("\nPolynomial 2: ");
    display(p2);
    printf("\nSum of polynomials: ");
    display(sum);
    return 0;
}
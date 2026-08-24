#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
    int value;
    struct node *next;
};
struct node* createNode(int row, int col, int value)
{
    struct node *NEW;
    NEW = (struct node*)malloc(sizeof(struct node));
    NEW->row = row;
    NEW->col = col;
    NEW->value = value;
    NEW->next = NULL;
    return NEW;
}
void insertEnd(struct node **head, int row, int col, int value)
{
    struct node *NEW;
    struct node *ptr;
    NEW = createNode(row, col, value);
    if(*head == NULL)
    {
        *head = NEW;
    }
    else
    {
        ptr = *head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NEW;
    }
}
void createSparse(int matrix[10][10], int r, int c, struct node **head)
{
    int i, j;
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            if(matrix[i][j] != 0)
            {
                insertEnd(head, i, j, matrix[i][j]);
            }
        }
    }
}
void display(struct node *head, int r, int c)
{
    struct node *ptr;
    int count = 0;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d %d %d\n", r, c, count);
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d %d %d\n",
               ptr->row,
               ptr->col,
               ptr->value);

        ptr = ptr->next;
    }
}
struct node* addSparse(struct node *head1, struct node *head2)
{
    struct node *p1 = head1;
    struct node *p2 = head2;
    struct node *sum = NULL;
    int value;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->row == p2->row &&
           p1->col == p2->col)
        {
            value = p1->value + p2->value;
            if(value != 0)
            {
                insertEnd(&sum,
                          p1->row,
                          p1->col,
                          value);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->row < p2->row ||
               (p1->row == p2->row &&
                p1->col < p2->col))
        {
            insertEnd(&sum,
                      p1->row,
                      p1->col,
                      p1->value);

            p1 = p1->next;
        }
        else
        {
            insertEnd(&sum,
                      p2->row,
                      p2->col,
                      p2->value);

            p2 = p2->next;
        }
    }
    while(p1 != NULL)
    {
        insertEnd(&sum,
                  p1->row,
                  p1->col,
                  p1->value);

        p1 = p1->next;
    }
    while(p2 != NULL)
    {
        insertEnd(&sum,
                  p2->row,
                  p2->col,
                  p2->value);

        p2 = p2->next;
    }
    return sum;
}
struct node* transposeSparse(struct node *head, int r, int c)
{
    struct node *ptr;
    struct node *transpose = NULL;
    int j;
    for(j = 1; j <= c; j++)
    {
        ptr = head;
        while(ptr != NULL)
        {
            if(ptr->col == j)
            {
                insertEnd(&transpose,
                          ptr->col,
                          ptr->row,
                          ptr->value);
            }
            ptr = ptr->next;
        }
    }
    return transpose;
}
void freeList(struct node *head)
{
    struct node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    printf("\nManikant Kumar - PCEA25CS096\n");
    int a[10][10], b[10][10];
    int r, c;
    int i, j;
    struct node *sparse1 = NULL;
    struct node *sparse2 = NULL;
    struct node *sum = NULL;
    struct node *transpose = NULL;
    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter first matrix: \n");
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    createSparse(a, r, c, &sparse1);
    printf("\nEnter second matrix: \n");
    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <= c; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    createSparse(b, r, c, &sparse2);
    printf("\nSparse Matrix 1:\n");
    display(sparse1, r, c);
    printf("\nSparse Matrix 2:\n");
    display(sparse2, r, c);
    sum = addSparse(sparse1, sparse2);
    printf("\nAddition of Sparse Matrices:\n");
    display(sum, r, c);
    transpose = transposeSparse(sum, r, c);
    printf("\nTranspose of Addition Matrix:\n");
    display(transpose, c, r);
    freeList(sparse1);
    freeList(sparse2);
    freeList(sum);
    freeList(transpose);
    return 0;
}
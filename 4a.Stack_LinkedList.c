#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *top = NULL, *ptr, *NEW;
    int item, ch;

    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nStack Linked List Operation\n");
    
    while(1)
    {
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.print\n");
        printf("4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            NEW = (struct node*) malloc(sizeof(struct node));
            printf("Enter element to insert: ");
            scanf("%d",&item);
            NEW -> data = item;
            if(top == NULL)
            {
                NEW -> next = NULL;
                top = NEW;
            }else{
                NEW -> next = top;
                top = NEW;
            }
            break;

            case 2:
            if(top == NULL)
            {
                printf("Stack is empty\n");
            }else{
                ptr = top;
                printf("Popped element: %d\n", ptr->data); 
                top = top -> next;
                free(ptr);
            }
            break;

            case 3:
            if(top == NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                ptr = top;
                while(ptr != NULL)
                {
                    printf("%d\n", ptr ->data);
                    ptr = ptr ->next;
                }
            }
            break;

        case 4:
            printf("Exit.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
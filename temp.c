#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *start = NULL, *ptr, *ptr1, *NEW;
    int item, pos,ch;
    while(1)
    {
        printf("\n1.Insertion from beginning\n");
        printf("2.Insertion from last\n");
        printf("3.Insertion at given position\n");
        printf("4.Deletion from beginning\n");
        printf("5.Deletion from last\n");
        printf("6.Deletion from given position\n");
        printf("7.Print\n");
        printf("8.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            NEW = (struct node*) malloc(sizeof(struct node));
            printf("Enter element to insert: ");
            scanf("%d",&item);
            NEW -> data = item;
            if(start == NULL)
            {
                NEW -> next = NULL;
                start = NEW;
            }
            else
            {
                NEW -> next = start;
                start = NEW;
            }
            break;

            case 2:
            NEW = (struct node*) malloc(sizeof(struct node));
            printf("Enter element to insert: ");
            scanf("%d",&item);
            NEW -> data = item;
            NEW -> next = NULL;
            if(start == NULL)
            {
                start = NEW;
            }
            else
            {
                ptr = start;
                while(ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                }
                ptr -> next = NEW;
            }
            break;

            case 3:
            printf("Enter position: ");
            scanf("%d",&pos);
            if(pos <= 0)
            {
                printf("Invalid position\n");
                break;
            }
            NEW = (struct node*) malloc(sizeof(struct node));
            printf("Enter element to insert: ");
            scanf("%d",&item);
            NEW -> data = item;
            if(start == NULL)
            {
                printf("LinkedList is empty and position not available\n");
                free(NEW);
            }
            else
            {
                if(pos==1)
                {
                    NEW -> next = start;
                    start = NEW;
                }else{
                    ptr = start;
                    for(int i = 1; i< pos-1 && ptr !=NULL ;i++)
                    {
                        ptr = ptr -> next;
                    }
                    if(ptr == NULL)
                    {
                        printf("Position not available\n");
                        free(NEW);
                    }
                    else
                    {
                        NEW -> next = ptr -> next;
                        ptr -> next = NEW;
                    }
                }
            }
            break;

            case 4:
            if(start==NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                ptr = start;
                printf("Deleted element: %d\n", ptr->data);
                start = start -> next;
                free(ptr);
            }
            break;

            case 5:
            if(start==NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                ptr = NULL;
                ptr1 = start;
                if(ptr1 -> next == NULL)
                {
                    printf("Deleted element: %d\n", ptr1->data);
                    start = NULL;
                    free(ptr1);
                }
                else
                {
                    while(ptr1 -> next != NULL)
                    {
                        ptr = ptr1;
                        ptr1 = ptr1 -> next;
                    }        
                    printf("Deleted element: %d\n", ptr1->data);
                    ptr -> next = NULL;
                    free(ptr1);
                }
            }
            break;

            case 6:
            if(start == NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                printf("Enter a position: ");
                scanf("%d",&pos);
                if(pos <= 0)
                {
                    printf("Invalid position\n");
                }
                else
                {
                    ptr = NULL;
                    ptr1 = start;
                    for(int i = 1; i<= pos-1; i++)
                    {
                        ptr = ptr1;
                        ptr1 = ptr1 -> next;
                        if(ptr1 == NULL)
                        {
                            printf("Position not available\n");
                            break;
                        }
                    }
                    if(ptr1 == start)
                    {
                        printf("Deleted element: %d\n", ptr1->data);
                        start = start -> next;
                        free(ptr1);
                    }
                    else
                    {
                        printf("Deleted element: %d\n", ptr1->data);
                        ptr -> next = ptr1 -> next;
                        free(ptr1);
                    }
                }
            }
            break;

            case 7:
            if(start == NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                ptr = start;
                while(ptr != NULL)
                {
                    printf("%d\t", ptr ->data);
                    ptr = ptr ->next;
                }
            }
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("Please enter cases from 1 to 8\n");
            break;
        }
    }
    return 0;
}
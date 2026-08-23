#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next, *previous;
};
int main()
{
    struct node *start = NULL, *ptr, *ptr1, *NEW;
    int item, pos,ch;

    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nDoubly LinkedList Operations\n");
    while(1)
    {   
        printf("\n1.Insertion from beginning\n");
        printf("2.Insertion from last\n");
        printf("3.Insertion at given position\n");
        printf("4.Deletion from beginning\n");
        printf("5.Deletion from last\n");
        printf("6.Deletion at given position\n");
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
            NEW -> previous = NULL;
            if(start == NULL)
            {
                NEW -> next = NULL;
                start = NEW;
            }else{
                NEW -> next = start;
                start -> previous = NEW;
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
                NEW -> previous = NULL;
                start = NEW;
            }else{
                ptr = start;
                while(ptr -> next != NULL)
                {
                    ptr = ptr -> next;
                }
                ptr -> next = NEW;
                NEW -> previous = ptr;
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
                printf("Doubly_LinkedList is empty and position not available\n");
                free(NEW);
            }
            else
            {
                if(pos==1)
                {
                    NEW -> previous = NULL;
                    NEW -> next = start;
                    start -> previous = NEW;
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
                        if(ptr -> next != NULL)
                        {
                            ptr -> next -> previous = NEW;
                        }
                        ptr -> next = NEW;
                        NEW -> previous = ptr;
                    }
                }
            }
            break;

            case 4:
            if(start==NULL)
            {
                printf("Doubly_LinkedList is empty\n");
            }
            else
            {
                ptr = start;
                printf("Deleted element: %d\n", ptr->data);
                start = start -> next;
                if(start != NULL)
                {
                    start -> previous = NULL;
                }
                free(ptr);
            }
            break;

            case 5:
            if(start==NULL)
            {
                printf("Doubly_LinkedList is empty\n");
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
                }else{
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
                printf("Doubly_LinkedList is empty\n");
            }
            else
            {
                printf("Enter a position: ");
                scanf("%d",&pos);
                if(pos <= 0)
                {
                    printf("Invalid position\n");
                }else{
                    int invalid = 0;
                    ptr = NULL;
                    ptr1 = start;
                    for(int i = 1; i<= pos-1; i++)
                    {
                        ptr = ptr1;
                        ptr1 = ptr1 -> next;
                        if(ptr1 == NULL)
                        {
                            printf("Position not available\n");
                            invalid = 1;
                            break;
                        }
                    }
                    if(!invalid)
                    {
                        if(ptr1 == start)
                        {
                            printf("Deleted element: %d\n", ptr1->data);
                            start = start -> next;
                            if(start != NULL) start -> previous = NULL;
                            free(ptr1);
                        }else{
                            printf("Deleted element: %d\n", ptr1->data);
                            ptr -> next = ptr1 -> next;
                            if(ptr1 -> next != NULL)
                            {
                                ptr1 -> next -> previous = ptr;
                            }
                            free(ptr1);
                        }
                    }
                }
            }
            break;

            case 7:
            if(start == NULL)
            {
                printf("Doubly_LinkedList is empty\n");
            }
            else
            {
                ptr = start;
                while(ptr != NULL)
                {
                    printf("%d ->", ptr->data);
                    ptr = ptr->next;
                }
                printf("NULL");
            }
            break;

        case 8:
            printf("Exit.\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}        
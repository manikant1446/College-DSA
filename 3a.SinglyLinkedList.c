#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *start = NULL, *NEW, *ptr, *ptr1;
    int item, i, ch, pos;

    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nSingly Linked List Operations\n");
    while (1)
    {
        printf("\n1. Insertion from Beginning\n");
        printf("2. Insertion at Last\n");
        printf("3. Insertion at Position\n");
        printf("4. Deletion from Beginning\n");
        printf("5. Deletion at Last\n");
        printf("6. Deletion at Postion\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            NEW = (struct node *)malloc(sizeof(struct node));
            printf("Enter Item: ");
            scanf("%d", &item);
            NEW->data = item;
            if (start == NULL)
            {
                NEW->next = NULL;
                start = NEW;
            }
            else
            {
                NEW->next = start;
                start = NEW;
            }
            break;

        case 2:
            NEW = (struct node *)malloc(sizeof(struct node));
            printf("Enter Item: ");
            scanf("%d", &item);
            NEW->data = item;
            NEW->next = NULL;
            if (start == NULL)
            {
                start = NEW;
            }
            else
            {
                ptr = start;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = NEW;
            }
            break;

        case 3:
            printf("Enter Item: ");
            scanf("%d", &item);

            printf("Enter Position: ");
            scanf("%d", &pos);

            if (pos <= 0)
            {
                printf("Invalid Position\n");
            }
            else
            {
                NEW = (struct node *)malloc(sizeof(struct node));
                NEW->data = item;

                if (pos == 1)
                {
                    NEW->next = start;
                    start = NEW;
                }
                else
                {
                    ptr = start;
                    for (i = 1; i < pos - 1 && ptr != NULL; i++)
                        ptr = ptr->next;
                    if (ptr == NULL)
                    {
                        printf("Position Not Available\n");
                        free(NEW);
                    }
                    else
                    {
                        NEW->next = ptr->next;
                        ptr->next = NEW;
                    }
                }
            }
            break;
        case 4:
            if (start == NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                ptr = start;
                printf("Deleted element: %d\n", ptr->data);
                start = start->next;
                free(ptr);
            }
            break;

        case 5:
            if (start == NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                ptr = NULL;
                ptr1 = start;
                if (ptr1->next == NULL)
                {
                    printf("Deleted element: %d\n", ptr1->data);
                    start = NULL;
                    free(ptr1);
                }
                else
                {
                    while (ptr1->next != NULL)
                    {
                        ptr = ptr1;
                        ptr1 = ptr1->next;
                    }
                    printf("Deleted element: %d\n", ptr1->data);
                    ptr->next = NULL;
                    free(ptr1);
                }
            }
            break;

        case 6:
            if (start == NULL)
            {
                printf("LinkedList is empty\n");
            }
            else
            {
                printf("Enter a position: ");
                scanf("%d", &pos);
                if (pos <= 0)
                {
                    printf("Invalid position\n");
                }
                else
                {
                    ptr = NULL;
                    ptr1 = start;
                    for (int i = 1; i <= pos - 1; i++)
                    {
                        ptr = ptr1;
                        ptr1 = ptr1->next;
                        if (ptr1 == NULL)
                        {
                            printf("Position not available\n");
                            break;
                        }
                    }
                    if (ptr1 == start)
                    {
                        printf("Deleted element: %d\n", ptr1->data);
                        start = start->next;
                        free(ptr1);
                    }
                    else
                    {
                        printf("Deleted element: %d\n", ptr1->data);
                        ptr->next = ptr1->next;
                        free(ptr1);
                    }
                }
            }
            break;

        case 7:
            ptr = start;
            if (ptr == NULL)
            {
                printf("List Empty");
            }
            else
            {
                while (ptr != NULL)
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
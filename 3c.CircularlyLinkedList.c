#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{   
    struct node *start = NULL, *last = NULL, *NEW, *ptr, *ptr1;
    int item, i, ch, pos;
    
    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\n Cirular Linked List Operations\n");
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
                start = NEW;
                last = NEW;
                last->next = start;
            }
            else
            {
                NEW->next = start;
                start = NEW;
                last->next = start;
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
                last = NEW;
                last->next = start;
            }
            else
            {
                NEW->next = start;
                last->next = NEW;
                last = NEW;
            }
            break;

        case 3:
            printf("Enter Position");
            scanf("%d", &pos);
            if (pos <= 0)
            {
                printf("invalid position: ");
                break;
            }
            NEW = (struct node *)malloc(sizeof(struct node));
            printf("Enter Item to Insert");
            scanf("%d", &item);
            NEW->data = item;
            if (start == NULL)
            {
                if (pos == 1)
                {
                    start = NEW;
                    last = NEW;
                    NEW->next = start;
                    printf("Node inserted at position 1.\n");
                }
                else
                {
                    printf("Position not available.\n");
                    free(NEW);
                }
            }

            else if (pos == 1)
            {
                NEW->next = start;
                start = NEW;
                last->next = start;

                printf("Node inserted at position 1.\n");
            }
            else
            {
                ptr = start;

                for (int i = 1; i < pos - 1; i++)
                {
                    ptr = ptr->next;

                    if (ptr == start)
                    {
                        break;
                    }
                }

                if (ptr == start)
                {
                    printf("Position not available.\n");
                    free(NEW);
                }
                else
                {
                    NEW->next = ptr->next;
                    ptr->next = NEW;

                    if (ptr == last)
                    {
                        last = NEW;
                    }
                    printf("Node inserted at position %d.\n", pos);
                }
            }
            break;

        case 4:
            if (start == NULL)
            {
                printf("Cicular LinkedList is empty\n");
            }
            else
            {
                ptr = start;
                printf("Deleted element: %d\n", ptr->data);
                if (start == start->next)
                {
                    start = NULL;
                    last = NULL;
                }
                else
                {
                    start = start->next;
                    last->next = start;
                }
                free(ptr);
            }
            break;

        case 5:

            if (start == NULL)
            {
                printf("Circular Linked List is Empty.\n");
            }
            else
            {
                if (start == last)
                {
                    printf("Deleted element: %d\n", start->data);

                    free(start);

                    start = NULL;
                    last = NULL;
                }
                else
                {
                    ptr = start;

                    while (ptr->next != last)
                    {
                        ptr = ptr->next;
                    }

                    ptr1 = last;

                    printf("Deleted element: %d\n", ptr1->data);

                    ptr->next = start;
                    last = ptr;

                    free(ptr1);
                }
            }

            break;

        case 6:
            if (start == NULL)
            {
                printf("Circular Linked List is Empty.\n");
                break;
            }
            printf("Enter position: ");
            scanf("%d", &pos);
            if (pos <= 0)
            {
                printf("Invalid position.\n");
                break;
            }

            if (pos == 1)
            {
                ptr = start;
                if (start == last)
                {
                    start = NULL;
                    last = NULL;
                }
                else
                {
                    start = start->next;
                    last->next = start;
                }

                free(ptr);

                printf("Node deleted from position 1.\n");
            }
            else
            {
                ptr = start;
                for (int i = 1; i < pos - 1; i++)
                {
                    ptr = ptr->next;

                    if (ptr == start)
                    {
                        break;
                    }
                }
                if (ptr == start || ptr->next == start)
                {
                    printf("Position not available.\n");
                }
                else
                {
                    ptr1 = ptr->next;
                    if (ptr1 == last)
                    {
                        last = ptr;
                    }
                    ptr->next = ptr1->next;
                    free(ptr1);
                    printf("Node deleted from position %d.\n", pos);
                }
            }
            break;
        case 7:

            if (start == NULL)
            {
                printf("Circular Linked List is Empty.\n");
            }
            else
            {
                ptr = start;
                printf("Circular Linked List: ");

                do
                {
                    printf("%d -> ", ptr->data);
                    ptr = ptr->next;

                } while (ptr != start);

                printf("(START)\n");
            }
            break;

        case 8:
            printf("Exit.\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
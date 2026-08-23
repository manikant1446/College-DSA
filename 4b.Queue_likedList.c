#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *front = NULL, *rear = NULL, *ptr, *NEW;
    int item, ch;

    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nQueue Linked List Operation\n");

    while(1)
    {
        printf("\n1.Insertion\n");
        printf("2.Deletion\n");
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
            NEW -> next = NULL;
            if(rear == NULL)
            {
                front = NEW;
                rear = NEW;
            }else{
                rear -> next = NEW;
                rear = NEW;
            }
            break;

            case 2:
            if(front == NULL)
            {
                printf("queue is empty\n");
            }else{
                if(front == rear)
                {
                    ptr = front;
                    printf("Deleted element: %d\n", ptr->data); 
                    front = NULL;
                    rear = NULL;
                    free(ptr);
                }else{
                    ptr = front;
                    printf("Deleted element: %d\n", ptr->data); 
                    front = front -> next;
                    free(ptr);
                }
            }
            break;

            case 3:
            if(front == NULL)
            {
                printf("queue is empty\n");
            }
            else
            {
                ptr = front;
                while(ptr != NULL)
                {
                    printf("%d ->", ptr->data);
                    ptr = ptr->next;
                }
                printf("NULL");
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
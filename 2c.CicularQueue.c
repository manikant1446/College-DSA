#include <stdio.h>
#define size 5
int main()
{
    int queue[size],front = -1, rear = -1,choice, item, i;
    printf("\nManikant Kumar - PCEA25CS096\n");
    while (1){
        printf("\nCircular Queue Operation\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    switch (choice){
        case 1:
            if ((front == 0 && rear == size- 1) || (front == rear + 1))
            {
                printf("Queue Overflow\n");
            }
            else
            {
                printf("Enter element: ");
                scanf("%d", &item);

                if (front == -1){
                    front = rear = 0;
                }
                else if (rear == size- 1){
                    rear = 0;
                }
                else{
                    rear++;
                }
                queue[rear] = item;
                printf("%d inserted.\n", item);
            }
            break;

        case 2: if (front == -1){
                printf("Queue Underflow\n");
            }
            else{
                printf("Deleted Element = %d\n", queue[front]);

                if (front == rear){
                    front = rear = -1;
                }
                else if (front == size- 1){
                    front = 0;
                }
                else{
                    front++;
                }
            }
            break;

        case 3: if (front == -1){
                printf("Queue is Empty\n");
            }
            else{
                printf("\nQueue Elements:\n");

                i = front;
                while (1)
                {
                    printf("%d ", queue[i]);

                    if (i == rear)
                        break;

                    if (i == size- 1)
                        i = 0;
                    else
                        i++;
                }
            }
            break;

        case 4: printf("Exit\n");
                return 0;
        default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
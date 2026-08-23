#include<stdio.h>
#include<stdlib.h>
#define size 10
int main()
{
    int dequeue[size], front=-1, rear=-1, item, i, choice;
    
    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nDequeue Operation\n");
    while(1)
    {
        printf("1. insertion from rear end\n");
        printf("2. insertion from front end\n");
        printf("3. deletion from front end\n");
        printf("4. deletion from rear end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            if(front==0 && rear==size-1){
                printf("Dequeue is full\n");
            }
            else{
                if(rear==size-1){
                    for(int i=front; i<=rear; i++){
                        dequeue[i-1] = dequeue[i];
                    }
                    front = front-1;
                }
                else{
                    rear = rear+1;
                }
                printf("\nEnter a element: ");
                scanf("%d", &item);
                dequeue[rear] = item;
                printf("%d inserted.\n", item);
                if(front==-1){
                    front = 0;
                }
            }
            break;

            case 2: 
            if(front==0 && rear==size-1){
                printf("Dequeue is full\n");
            }
            else{
                if(front==0){
                    for(int i=rear; i>=front; i--){
                        dequeue[i+1] = dequeue[i];
                    }
                    rear = rear+1;
                }
                else if(front==-1){
                    front=0; rear=0;
                }
                else{
                    front = front-1;
                }
                printf("\nEnter a element:");
                scanf("%d", &item);
                dequeue[front] = item;
                printf("%d inserted.\n", item);
            }
            break;

            case 3: 
            if(front==-1)
            {
                printf("Dequeue is empty\n");
            }
            else
            {
                printf("Deleted Element = %d\n", dequeue[front]);

                if(front==rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front++;
                }
            }
            break;

            case 4:
            if(rear==-1)
            {
                printf("Dequeue is empty\n");
            }
            else
            {
                printf("Deleted Element = %d\n", dequeue[rear]);

                if(front==rear)
                {
                    front = rear = -1;
                }
                else
                {
                    rear--;
                }
            }
            break;

            case 5: 
            if(front== -1){
                printf("Dequeue is empty\n");
            }
            else{
                printf("\nDequeue elements: ");
                for(i=front; i<=rear; i++){
                    printf("%d ", dequeue[i]);
                }
            }
            break;
            
            case 6: 
            printf("\nExit ");
            return 0;

            default: 
            printf("\nInvalid choice");
        }
    }
    return 0;
}
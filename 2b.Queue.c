#include<stdio.h>
#define size 10
int main(){
    int queue[size],front=-1,rear=-1,item,choice;
    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nQueue Operation:\n");
    while(1){
    printf("1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
        if(rear==size-1){
            printf("Queue is Full\n");
        }
        else{
            printf("Enter element to insert: ");
            scanf("%d",&item);
            rear++;
            queue[rear]=item;
            if (front==-1)
            {
                front =0;
            } 
        }
        break;

case 2: if (front==-1){
        printf("Queue is Empty\n");
        }
        else{
            printf("Item deleted is %d\n",queue[front]);
            if(front==rear){
                front=rear=-1;
            }
            else{
                front++;
            }
        }
        break;

case 3: if (front==-1){
                printf("Queue is Empty\n");
            }
        else{
            for(int i=front;i<=rear;i++){
                printf("%d\t",queue[i]);
            }
            printf("\n");
        }
        break;

case 4: printf("Exit.\n");
        return 0;
default: printf("Invalid choice.\n");
    }
}
        return 0;
}

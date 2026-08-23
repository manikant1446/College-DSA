#include <stdio.h>
#define size 10
int main()
{
    int stack[size], top=-1, item, choice;
    printf("\nManikant Kumar - PCEA25CS096\n");
    printf("\nStack Operation:\n");
while(1){
    printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n");
    scanf("%d",&choice);
        switch(choice){
case 1:
        if(top== size-1){
            printf("Stack is Full\n");
        }
        else{
            printf("Enter element to be pushed: ");
            scanf("%d",&item);
            top++;
            stack[top]=item;
        }
        break;

case 2: if (top==-1){
        printf("Stack is Empty\n");
        }
        else{
            printf("Item deleted is %d\n",stack[top]);
            top-=1;
        }
        break;

case 3: if (top==-1){
                printf("Stack is Empty\n");
            }
        else{
            for(int i=top;i>=0;i--){
                printf("%d\n",stack[i]);
            }
        }
        break;

case 4: printf("Exit.\n");
        return 0;
        break;
default: printf("Invalid choice.\n");
       }
    }
        return 0;
}
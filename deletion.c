#include <stdio.h>

int removeItem(int arr[], int n, int item)
{
    int index = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != item){
            arr[index] = arr[i];
            index++;
        }}
    return index;
}
int main()
{
    int arr[]={2,4,7,0,4,5,6,3,2};
    int item;
    printf("Original array: ");
    for (int i=0;i< sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    printf("\n");   
    int n=sizeof(arr) / sizeof(arr[0]);
    printf("Enter the item to be deleted: ");
    scanf("%d", &item);
    int newSize = removeItem(arr, n, item);

    printf("The new array is: ");
    for (int i = 0; i < newSize; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
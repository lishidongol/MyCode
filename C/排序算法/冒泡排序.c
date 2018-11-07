/*
 * Created by lishidongol on 2018/11/7.
 */

#include <stdio.h>

//冒泡排序
void BubbleSort(int arr[],int ArraySize){
    int i,j,temp;
    printf("排序前的数组:\n");
    for(i=0;i<ArraySize;i++){
        printf("%d\t",arr[i]);
    }

    printf("\n");
    for(i=0;i<ArraySize-1;i++){
        for(j=0;j<ArraySize-1-i;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("排序后的数组:\n");
    for(i=0;i<ArraySize;i++){
        printf("%d\t",arr[i]);
    }
}

void main(){
    int arr[]={2,5,8,9,10,3,16,7,1,4};
    int arrayLength = sizeof(arr)/ sizeof(arr[0]);
    BubbleSort(arr,arrayLength);
}


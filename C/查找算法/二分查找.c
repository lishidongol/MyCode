/**
 * Created by lishidongol on 2018/11/7.
 */

#include <stdio.h>

/*
 * 二分查找算法
 */

void SortArray(int[],int);

void main()
{
    int arr[]={2,5,8,9,10,3,16,7,1,4};
    int arrayLength = sizeof(arr)/ sizeof(arr[0]);
    int N=0;
    //printf("要查找的值在%d",BinarySearch(arr,N));

    SortArray(arr,arrayLength);
}

//二分查找
int BinarySearch(int arr[],int N){
    int left,right,mid;
    left = 0;
    right = (sizeof(arr)/ sizeof(arr[0]))-1;

    return -1;
}

//冒泡排序
void SortArray(int arr[],int ArraySize){
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


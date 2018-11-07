/*
 * 三种算法求最大子列和
 */
#include <stdio.h>

void main() {
    int subsequence[] = {2, -1, 4, 5, -3, 2, -4, 3, 5, 6};
    int N=10;
    printf("第一种算法求得结果：%d\n",MaxSubseqSum1(subsequence,N));
    printf("第二种算法求得结果：%d\n",MaxSubseqSum2(subsequence,N));
    printf("第三种算法求得结果：%d\n",MaxSubseqSum3(subsequence,N));
}

//算法时间复杂度为n的3次方
int MaxSubseqSum1(int A[], int N) {
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            ThisSum = 0;
            for (k = i; k <= j; k++) {
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//算法时间复杂度为n的平方
int MaxSubseqSum2(int A[], int N) {
    int ThisSum, MaxSum = 0;
    int i, j;
    for (i = 0; i < N; i++) {
        ThisSum = 0;
        for (j = i; j < N; j++) {
            ThisSum+=A[j];
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

//算法时间复杂度为nlogn
int MaxSubseqSum3(int A[], int N) {
    int ThisSum = 0, MaxSum = 0;
    int i;
    for (i = 0; i < N; i++) {
        ThisSum += A[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        } else if (ThisSum < 0) {
            ThisSum = 0;
        }
    }
    return MaxSum;
}

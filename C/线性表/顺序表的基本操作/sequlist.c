/*
 * Created by lishidongol on 2018/11/24.
 */

#include <stdio.h>
#include "sequlist.h"

//初始化为空表
void init(sequence_list *list) {
    list->size = 0;
}

//在表的最后添加元素
void append(sequence_list *list, dataType x) {
    if (list->size == MAXSIZE) {
        printf("表已满！无法插入新数据！");
        return;
    }
    list->elem[list->size] = x;
    list->size = list->size + 1;
}

//打印顺序表的各节点的值
void display(sequence_list list) {
    int i;
    if (list.size == 0) {
        printf("表是空的！");
        return;
    }
    for (i = 0; i < list.size; i++) {
        printf("%d\t", list.elem[i]);
    }
    printf("\n");
}

//判断顺序表是否为空
int isEmpty(sequence_list list) {
    return list.size == 0 ? 1 : 0;
}

//查找顺序表中值为x的节点位置
int find(sequence_list list, dataType x) {
    int i;
    for (i = 0; i < list.size; i++) {
        if (list.elem[i] == x) {
            return i;
        }
    }
    return -1;
}

//取得顺序表第i个节点的值
dataType get(sequence_list list, int i) {
    if (i < 0 || i > list.size) exit(1);
    return list.elem[i];
}

//在是顺序表的第position个位置插入x
int insert(sequence_list *list, int position, dataType x) {
    int i;
    if(position <0 || position > list->size){
        printf("插入位置不合法！\n");
        return -1;
    }
    if(list->size == MAXSIZE){
        printf("表已满！无法插入新数据！\n");
        return -1;
    }
    for(i=list->size;i>position;i--){
        list->elem[i+1] = list->elem[i];
    }
    list->elem[position] = x;
    list->size++;
}

//删除第position位置的节点
void del(sequence_list *list, int position){
    int i;
    if(position<0 || position>list->size){
        printf("删除位置不合法！\n");
        return;
    }
    if(list->size == 0){
        printf("表是空的！\n");
        return;
    }
    for(i=position;i<list->size-1;i++){
        list->elem[i] = list->elem[i+1];
    }
    list->size--;
}

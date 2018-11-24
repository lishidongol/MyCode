/*
 * Created by lishidongol on 2018/11/24.
 */

#ifndef C_SEQULIST_H
#define C_SEQULIST_H
#define MAXSIZE 10
#endif //C_SEQULIST_H

typedef int dataType;
typedef struct {
    dataType elem[MAXSIZE];
    int size;
} sequence_list;

//初始化为空表
void init(sequence_list *list);

//在表的最后添加元素
void append(sequence_list *list, dataType x);

//打印顺序表的各节点的值
void display(sequence_list list);

//判断顺序表是否为空
int isEmpty(sequence_list list);

//查找顺序表中值为x的节点位置
int find(sequence_list list, dataType x);

//取得顺序表第i个节点的值
dataType get(sequence_list list, int i);

//在是顺序表的第position个位置插入x
int insert(sequence_list *list, int position, dataType x);

//删除第position位置的节点
void del(sequence_list *list, int position);

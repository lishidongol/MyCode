/*
 * Created by lishidongol on 2018/11/24.
 */

#ifndef C_SEQSTACK_H
#define C_SEQSTACK_H
#define MAXSIZE 10
#endif //C_SEQSTACK_H
typedef int dataType;

typedef struct {
    dataType elem[MAXSIZE];
    int top;
} sequence_stack;

//顺序栈初始化
void init(sequence_stack *st);

//判断是否为空
int isEmpty(sequence_stack st);

//读出栈顶元素
dataType read(sequence_stack st);

//将x压入栈中
void push(sequence_stack *st, dataType x);

//弹出栈顶元素
void pop(sequence_stack *st);
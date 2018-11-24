/*
 * Created by lishidongol on 2018/11/24.
 */
#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"

//顺序栈初始化
void init(sequence_stack *st) {
    st->top = 0;
}

//判断是否为空
int isEmpty(sequence_stack st) {
    return st.top ? 0 : 1;
}

//读出栈顶元素
dataType read(sequence_stack st){
    if(st.top==0){
        printf("栈为空！\n");
        exit(1);
    }
    return st.elem[st.top-1];
}

//将x压入栈中
void push(sequence_stack *st, dataType x){
    if(st->top == MAXSIZE){
        printf("栈已满！\n");
        return;
    }
    st->elem[st->top] = x;
    st->top++;
}

//弹出栈顶元素
void pop(sequence_stack *st){
    if(st->top ==0){
        printf("栈为空！\n");
        return;
    }
    st->top--;
}

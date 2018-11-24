#include "顺序栈/seqstack.c"
int match_kuohao(char c[]){
    int i=0;
    sequence_stack s;
    init(&s);
    while (c[i] != '#'){
        switch (c[i]){
            case '{':
            case '[':
            case '(':
                push(&s,c[i]);
                break;
            case '}':
                if(!isEmpty(s) && read(s) == '{'){
                    pop(&s);
                }else{
                	return 0;
                }
                break;
            case ']':
                if(!isEmpty(s) && read(s) == '['){
                    pop(&s);
                }else{
                	return 0;
                }
                break;
            case ')':
                if(!isEmpty(s) && read(s) == '('){
                    pop(&s);
                }else{
                	return 0;
                }
                break;
        }
        i++;
    }

    return isEmpty(s);
}

int main() {
    char a[] = {'{','[','(',')',']',']','#'};
    printf("%d\n",match_kuohao(a));
    return 0;
}
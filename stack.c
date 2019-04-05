#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define TYPE int
typedef struct{
        TYPE* base;
        TYPE* top;
        int size;
}stack;
void init(stack *s){
        s->base=(TYPE *)malloc(sizeof(TYPE)*SIZE);
        if(!s->base)
                printf("ERROR");
        s->top=s->base;
        s->size=SIZE;
        printf("      %p\n",s->base);
}
void push(stack *s,TYPE value){
        if(s->top-s->base>=s->size){
                s->base=(TYPE *)realloc(s->base,sizeof(TYPE)*(s->size+SIZE));
        if(!s->base)
                printf("ERROR");
        s->top=s->base+s->size;
        s->size=s->size+10;
    }
        *s->top=value;
        s->top=s->top+1;
}
void getop(stack *s){
        printf("the value of top is:%d\n",*(s->top-1));
}
void pop(stack *s){
        if(s->top==s->base)
                printf("stack is null");
        s->top=s->top-1;
}
int main(){
        stack s;
        init(&s);
        push(&s,23);
        push(&s,65);
        push(&s,75);
        push(&s,25);
        getop(&s);
        pop(&s);
        getop(&s);
        return 0;
}


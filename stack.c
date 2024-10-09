#include<stdio.h>
#define MAX 5
struct Stack{
    int top;
    int items[MAX];
};

void initStack(struct Stack*s){
    s->top=-1;
};

int isFull(struct Stack*s){
    return s->top== MAX-1;
};

int isEmpty(struct Stack*s){
    return s->top==-1;
};
void push(struct Stack*s,int item){
    if(isFull(s)){
        printf("Stack is overflow");
    }else{
        s->items[++(s->top)]=item;
        printf("Pushed %d to stack /n",item);

    }
};
int pop(struct Stack*s){
    if(isEmpty(s)){
        printf("Stack is underflow");
        return -1;
    }else{
        return s->items[(s->top)--];

    }
};
void Display(struct Stack*s){
    if(isEmpty(s)){
        printf("Stack is Empty");
    }else{
        printf("Stack Contents:");
        for(int i=0;i<=s->top;i++){
            printf("%d",s->items[i]);
        }
    }printf("/n");
};
int main(){
    struct Stack stack;
    initStack(&stack);
    display(&stack);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);
    display(&stack);
    pop(&stack);
    display(&stack);
    
}
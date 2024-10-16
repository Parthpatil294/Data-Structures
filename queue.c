#include<stdio.h>
#define MAX 10

//insert code
void insert(int arr[],int *f, int *r,int x){
    if(*f==-1&& *r==-1){
        (*f)++;
        (*r)++;
        arr[*r]=x;
    }else if(*r==MAX-1){
        printf("It is overflow");
    }else{
       (*r)++;
        arr[*r]=x;
    }
}
void delete(int arr[], int *f, int *r){  
    
    if(*f==-1 && *r==-1){
        printf("the queue is underflow");
    }else if(*f>*r){
        printf("the queue is underflow");
    }else{
       
        (*f)++;
        
    }
}
void display(int arr[], int f, int r) {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("the queue is:\n");
    for (int i = f; i <= r; i++) {
        printf("%d\n", arr[i]);
    }
}
int main(){
    int arr[MAX];
    int f,r;
    f=r=-1;
    insert(arr,&f,&r,3);
    insert(arr,&f,&r,4);
    insert(arr,&f,&r,5);
    insert(arr,&f,&r,6);
    display( arr,f,r);
    delete(arr,&f,&r);s
    display( arr,f,r);
    
    
    
   
    return 0;
}                      
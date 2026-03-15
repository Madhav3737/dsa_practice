//lab 7
#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top=-1;
void push(int x){
    if (top>=max-1){
        printf("The stack is full this element is not pushed");
    }
    else{
        stack[++top]=x;
    }
}
int pop(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("The popped element:%d",stack[top]);
        return stack[top--];
    }
}
void peek(){
    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("The top element is %d",stack[top]);
    }
}
void traverse(){
    if(top==-1){
        printf("statck is empty");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
    }
}
void main(){
    int choice;
    printf("\n1.Push an element on to the stack\n2.pop an element\n3.Peek at the top\n4.Traverse the stack\n5.Exit from the program");
    while(1){
        printf("\nGive your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int x;
                printf("Enter data:");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                int popped=pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                traverse();
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid input");
                break;        
        }
    }
}
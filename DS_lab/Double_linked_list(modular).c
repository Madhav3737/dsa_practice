#include<stdio.h>
#include<stdlib.h>
//--------------------------Node structure-----------------------
struct node {
    struct node *prev;
    int data;
    struct node *next;
};
struct node *start=NULL,*end,*temp,*p,*new;
//--------------------------Function declarations-------------------
struct node* create();
void display(struct node *);
struct node* traverse(struct node *);
//------------------------Functions---------------------------------
struct node* create(){
    //creation
    int x,choice,y=1;
    do{
        new = (struct node *)malloc(sizeof(struct node));
        printf("give the data to be stored in the %dth node:",y++);
        scanf("%d",&x);
        new->prev=NULL;
        new->data =x;
        new->next=NULL;
        if (start==NULL){
            start = new;
            end = new;
        }
        else{
            end->next=new;
            new->prev=end;
            end=new;
        }
        printf("do you want to take another node(1/0):");
        scanf("%d",&choice);
    }while(choice);
    return start;
}
void display(struct node *start){
    if (start==NULL){
        start=create();
        display(start);
    }
    else{
        temp=start;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
struct node * traverse(struct  node*){
    if (start==NULL){
        start=create();
        traverse(start);
    }
    else{
    int a,i;
    temp=start;
    printf("\ngive the position till which to be traversed(-1 for end):-");
    scanf("%d",&a);
    if (a==-1){
        while (temp->next!=NULL){
            temp=temp->next;
        }
    }
    else{
        for(i=1;i<a&&temp->next!=NULL;i++){
            temp=temp->next;
        }
    }
    printf("\ndata at %dth node is %d",a,temp->data);
    }
    return temp;   
}

//---------------------Main Function------------------------
void main(){
    int n;
    printf("1.creation\n2.print the list\n3.traverse\n4.Reverse the list\n5.delete a node \ngive your choice:-");
    scanf("%d",&n);
    switch(n){
        case 1:
            create(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            traverse(start);
            break;
        /*case 4:
            reverse();
        case 5:
            delete();*/
    }
}

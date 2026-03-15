#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start=NULL,*temp,*p;

//-------------Function declarations---------

struct node* create();
void display(struct node*);
struct node* traverse(struct node *);
void reverse();
void delete();//at specified position
void d_beg();
void d_end();
void insertAtBeg();
struct node * new_node();
void insertAtEnd();
void insertAtPos();
void search();

//      -------------------Functions---------------------

struct node* create(){
    //creation
        int x,choice,y=1;//choice is for  repetition and Y is for node counting
        struct node *new ;
        do {
            new =(struct node*)malloc(sizeof(struct node));
            printf("Give the data to be stored in the %d th node:-",y++);
            scanf("%d",&x);
            new->data=x;
            new->next=NULL;
            if (start==NULL){
                start=new;
                temp=new;
            }
            else{
                temp->next = new;
                temp = new;
            }
            printf("do you want to take another node(1/0):");
            scanf("%d",&choice);
        }while(choice);
    return start;
}
struct node * new_node(){
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert:");
    scanf("%d",&new->data);
    new->next=NULL;
    return new;
}
void display(struct node * start){
    //printing
        if (start==NULL){
            printf("list is empty so lets create\n");
            start=create();
            display(start);
       }
    else{
        temp=start;
        int i=1;
        while (temp!=NULL){
            printf("data in %dth node id %d\n",i++,temp->data);
            temp=temp->next;
        }
    }
}
struct node* traverse(struct node *start){
    //traversing
    if (start==NULL){
            printf("list is empty so lets create\n");
            start=create();
            traverse(start);
       }
    else{ 
    int a,i;
    temp=start;
    printf("\ngive the position till which to be traversed(-1 for end):-");
    scanf("%d",&a);
    if (a=-1){
        while (temp->next!=NULL){
            temp=temp->next;
        }
    }
    else{
        for(i=0;i<a&&temp->next!=NULL;i++){
            temp=temp->next;
        }
    }
    }
    return temp;   
}
void reverse(){
    struct node *p1,*p2 ,*p3;
    start=create();
    if (start==NULL){
        printf("the give list is empty");
    }
    else{
        p1=start;
        p2=p1->next;
        p3=p2->next;
        p2->next=p1;
        p1->next=NULL;
        while(p3!=NULL){
            p1=p2;
            p2=p3;
            p3 =p2->next;
            p2->next=p1;
        }
        p2=start;
        printf("the reversed list is \n");
        display(start);
    }
}
void d_beg(){
    if(start==NULL){
        printf("THe single linked list is empty");
        start = create();
        d_beg();
    }
    else{
    temp = start;
    printf("%d\n",temp->data);
    start=start->next;
    free(temp);
    printf("updated list is\n");
    display(start);
    }
}

void d_end(){
    if(start==NULL){
        printf("THe single linked list is empty");
        start = create();
        d_end();
    }
    else{
        p=start;
        while(p->next->next!=NULL){
            p=p->next;
        }
        temp=p->next;
        p->next=NULL;
        printf("%d\n",temp->data);
        free(temp);
        printf("updated list is\n");
        display(start);
    }
}

void delete(){
    if(start==NULL){
        printf("the single linked list is empty");
        start = create();
        delete();
    }
    else if(start->next==NULL){
        temp=start;struct node *new,*temp;
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&new->data);
    new->next=NULL;
        start=NULL;
        printf("%d",temp->data);
        free(temp);
    }
    else{
        int pos,i,count=0;
        p=start;
        while(p!=NULL){
            count=count+1;
            p=p->next;
        }
        printf("\ngive the position of the node to be deleted:");
        scanf("%d",&pos);
        if(pos==1){
            d_beg();
        }
        else if (pos==count){
            d_end();
        }
        else if (pos>1&&pos<count){
            p=start;
            for(i=1;i<pos-1;i++){
                p=p->next;
            }
            temp=p->next;
            p->next=temp->next;
            temp->next=NULL;
            printf("%d\n",temp->data);
            free(temp);
        }
        else{
            printf("give valid position\n");
        }
    }
}

void insertAtBeg(){
    struct node *new,*temp;
    new = new_node();
    if(start==NULL){
        start = new;
        start->next= NULL;
    }
    else{
        new->next=start;
        start = new;
    }
}

void insertAtEnd(){
    struct node  *new, *temp,*p;
    new = new_node();
    if (start ==NULL){
        start=new;
    }
    else{
        p = start ;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new;
    }
}

void insertAtPos(){
    int pos,c=0;
    printf("give the position where you want to insert:");
    scanf("%d",&pos);
    p= start;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    if(pos=1){
        insertAtBeg();
    }
    else if (pos=c+1){
        insertAtEnd();
    }
    else if (pos>1&&pos<c+1){
        struct node *new;
        new = new_node();
        p=start;
        int i;
        for(i=0;i<pos-1;i++){
            p=p->next;
        }
        new->next=p->next;
        p->next= new;
    }
}
void search(){
    if(start==NULL){
        printf("LInked list is emptly");
    }
    else{
    int data,flag=0;
    printf("enter data to be searched :");
    scanf("%d",&data);
    for(p=start;p!=NULL;p=p->next){
        if(p->data==data){
            flag++;
            break;
        }
    }
    if(flag==0){
        printf("The searchd data is not found ");
    }
    else{
        printf("the searched data is found");
    }
    }
}

void concatenate(){
    struct node *start1,*start2;
    printf("create the first linked list\n");
    start1 = create();
    printf("create the second linked list\n");
    start2 = create();
    temp= start1;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=start2;
    display(start1);
}
 void sorting(){
    if (start==NULL){
        printf("Linked list is empty");
    }
    else if (start->next ==NULL){
        printf("Linked list contains only one element");
    }
    else{
        struct node *temp1 ,*temp2,*p;
        for (temp1=start;temp1!=NULL;temp1=temp1->next){
            for(temp2=start;temp2!=NULL;temp2=temp2->next){
                if(temp1->data<temp2->data){
                    p=temp1;
                    temp1=temp2;
                    temp2=p;
                }
            }
        }
        printf("sorted elements");
        display(start);
    }
 }

// ---------------------Main Function----------------------
int main(){
    int n,e=1;
    while(e){
    printf("1.creation\n2.display the list\n3.traverse\n4.Reverse the list\n5.delete a node at specified pos\n6.delete node at beginning\n7.Deleta a node at end\n8.insert a node at beginning\n9insert a node at end \n 10.insert at specified position \n 11.Search an element \n12.concatenate two linked lists\n13.sorting\n14.Exit from the program\ngive your choice:-");
    scanf("%d",&n);
    switch(n){
        case 1:
            create();
            break;
        case 2:
            display(start);
            break;
        case 3:
            traverse(start);
            break;
        case 4:
            reverse();
            break;
        case 5:
            delete();
            break;
        case 6:
            d_beg();
            break;
        case 7:
            d_end();
            break;
        case 8:
            insertAtBeg();
            break;
        case 9:
            insertAtEnd();
            break;
        case 10:
            insertAtPos();
            break;
        case 11:
            search();
            break;
        case 12:
            concatenate();
            break;
        case 13:
            sorting();
            break;
        case 14:
            exit(1);
        default:
            printf("invalid choice");
    }
    }
}
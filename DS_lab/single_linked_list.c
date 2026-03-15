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
void insertatpos(struct node* start);
void insertatend(struct node* start);
void insertatbeg(struct node* start);
void sorting(struct node* start);
void search(struct node* start);
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
    start=temp->next;
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
        temp=p->next;void search(struct node* start);
        p->next=NULL;
        printf("%d\n",temp->data);
        free(temp);
        printf("updated list is\n");
        display(start);
    }
}

void delete(){
    if (start==NULL){
        printf("the linked list is empty");
    start=create();
    delete();
    }
    else{
	int pos,i;
	//create();
	temp=start;
	printf("enter the position where you want to delete");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++){
		temp=temp->next;
	}
	p=temp->next;
	temp->next=p->next;
	free(p);
	display(start);
    }
}
void insertatpos(struct node* start){
	start=create();

	int pos,i,x;
	struct node *ne;
	ne=(struct node *)malloc(sizeof(struct node));
	printf("enter data you want to insert");
	scanf("%d",&x);
	ne->data=x;
	ne->next=0;
	//create();
	temp=start;
	printf("enter the position where you want to insert");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++){
		temp=temp->next;
	}
	ne->next=temp->next;
	temp->next=ne;
	display(start);	
}
void insertatend(struct node* start){
	start=create();

	int x;
	struct node *ne;
	ne=(struct node *)malloc(sizeof(struct node));
	printf("enter data you want to insert");
	scanf("%d",&x);
	ne->data=x;
	ne->next=0;
	temp=start;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=ne;
	display(start);	
}
void insertatbeg(struct node* start){
	start=create();

	int x;
	struct node *ne;
	ne=(struct node *)malloc(sizeof(struct node));
	printf("enter data you want to insert");
	scanf("%d",&x);
	ne->data=x;
	ne->next=0;
	ne->next=start;
	start=ne;
	display(start);	
}
void sorting(struct node* start){
	int j,i,c;
	start=create();

	temp=start;
	printf("%d",start->data);
	struct node *temp1;
	for(temp;temp!=0;temp=temp->next){
		for(temp1=temp->next;temp1!=0;temp1=temp->next){
			if(temp->data>temp1->data){
				c=temp->data;
				temp->data=temp1->data;
				temp1->data=c;
			}
		}
	}

	display(start);
}
void search(struct node* start){
	start=create();

	int s,flag;
	printf("enter data you want to found");
	scanf("%d",&s);
	for(temp=start;temp!=0;temp=temp->next){
		if(s==temp->data){
			flag++;
			
		}
	}
	if(flag>0){
		printf("searched data is found");
	}
	else{
		printf("searched data is not found");
	}
}
void concatenate(){
    struct node *start1,*start2,*temp2;
    printf("create the first list\n");
    start1=create();
    printf("create the second list\n");
    start2=create();
    temp=start1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=start2;
    display(start1);
}

// ---------------------Main Function----------------------
int main(){
    int n,e=1;
    while(e){
    printf("1.creation\n2.display the list\n3.traverse\n4.Reverse the list\n5.delete a node at specified pos\n6.delete node at beginning\n7.Deleta a node at end\n8:insert at beginning\n9:insert at position\n10:insert at end\n11:sorting\n12:search\n13.concatenate\n14.Exit from program\ngive your choice:-");
    scanf("%d",&n);
    switch(n){
        case 1:
            start=create();
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
			insertatbeg(start);
			break;
		case 9:
			insertatpos(start);
			break;
		case 10:
			insertatend(start);
			break;
		case 11:
			sorting(start);
			break;
		case 12:
			search(start);
			break;
        case 13:
            concatenate();
            break;
        case 14:
            exit(0);	
		default:
			printf("invalid choice");
			break;
    }
    }
}
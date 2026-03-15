#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start=NULL,*temp,*p,*n;
struct node *create(){
	int x,choice;
	do{
	n=(struct node *)malloc(sizeof(struct node));
	printf("enter data");
	scanf("%d",&x);
	n->data=x;
	n->next=0;
	if(start==NULL){
		start=temp=n;
	}
	else{
		temp->next=n;
		temp=n;
	}
	printf("if you want another node(1)or(0)");
	scanf("%d",&choice);
}while(choice);
return start;
}
void traverse(struct node *start){
//	printf("%d",start->data);
	if(start==0){
	start=create();
	traverse(start);
	}
	else{
	temp=start;
	while(temp->next!=0){
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d\t",temp->data);
}
}
void reverse(struct node *start){
	struct node *p1=NULL,*p2=start,*p3=start;
	if(start==NULL){
		start=create();
		reverse(start);
	}
	else {
		p1=start;
		p2=p1->next;
		p3=p2->next;
		p2->next=p1;
		p1->next=NULL;
		while(p3!=0){
			p1=p2;
			p2=p3;
			p3=p3->next;
			p2->next=p1;
		}
		start=p2;
		
	}
	/*
	else{
		while(p3!=0){
			p3=p3->next;
			p2->next=p1;
			p1=p2;1
			p2=p3;
			
		}
		start=p1;
	}*/
	traverse(start);
}
void deleteatbeg(struct node* start){
	start=create();
	temp=start;
	start=temp->next;
	temp->next=NULL;
	free(temp);
	traverse(start);
}
void deleteatpos(struct node* start){
	start=create();
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
	traverse(start);	
}
void deleteatend(struct node* start){
	start=create();

	temp=start;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	p=temp->next;
	temp->next=NULL;
	free(p);
	traverse(start);	
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
	traverse(start);	
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
	traverse(start);	
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
	traverse(start);	
}
void sorting(struct node* start){
	int j,i,c;
	start=create();
	temp=start;
	//printf("%d",start->data);
	struct node *temp1;
	for(temp;temp!=0;temp=temp->next){
		for(temp1=temp->next;temp1!=0;temp1=temp1->next){
			if(temp->data>temp1->data){
				c=temp->data;
				temp->data=temp1->data;
				temp1->data=c;
			}
		}
	}

	traverse(start);
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
    if(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=start2;
    traverse(start1);
}

int main(){

int c;
	printf("1:create\n2:travesing\n3:reverse\n4:delete at beginning\n5:delete at position\n6:delete at end\n7:insert at beginning\n8:insert at position\n9:insert at end\n10:sorting\n11:search\n12.concatenation\n give your choice:");
	scanf("%d",&c);
	switch(c){
		case 1:
			create();
			break;
		case 2:
			traverse(start);
			break;
		case 3:
			reverse(start);
			break;
		case 4:
			deleteatbeg(start);
			break;
		case 5:
			deleteatpos(start);
			break;
		case 6:
			deleteatend(start);
			break;
		case 7:
			insertatbeg(start);
			break;
		case 8:
			insertatpos(start);
			break;
		case 9:
			insertatend(start);
			break;
		case 10:
			sorting(start);
			break;
		case 11:
			search(start);
			break;
		case 12:
            concatenate();
            break;	
		default:
			printf("invalid");
			break;
	}
}

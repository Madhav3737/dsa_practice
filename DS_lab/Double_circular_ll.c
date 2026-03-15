#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start = NULL, *tail, *temp, *p, *n;
struct node *create()
{
    //struct node *start = NULL;
    int x, choice = 0;
    printf("Enter no of nodes:");
    scanf("%d", &choice);
    for (int i = 0; i < choice; i++)
    {
        n = (struct node *)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d", &x);
        n->data = x;
        n->prev = NULL;
        n->next = NULL;
        if (start == NULL)
        {
            start = tail = n;
            start->next = start->prev = start;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
            tail->next = start;
            start->prev = tail;
        }
    }
    return start;
}

void traverse(struct node *start)
{
    if (start == NULL)
    {
        printf("linked list is empty so create one\n");
        start = create();
        traverse(start);
    }
    else
    {
        temp = start;
        printf("list elements:");
        do
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp!= start);
    }
}

void reverse(struct node *start)
{
    if (start==NULL){
        printf("list is empty so create\n");
        start=create();
        reverse(start);
    }
    else{
        p=start;
        do{
            temp=p->next;
            p->next=p->prev;
            p->prev=temp;
            p=p->prev;
        }while(p!=start);
        temp=tail;
        tail=start;
        start=temp;
        traverse(start);
    }
}
void insertatbeg(struct node *start){
    struct node *new;
    new =(struct node*)malloc(sizeof(struct node));
    printf("give the data to be stored in the inserting node:");
    scanf("%d",&(new->data));
    if(start==NULL){
        start->next=start->prev=start=tail=new;
    }
    else{
        tail->next=new;
        new->prev=tail;
        new->next=start;
        start->prev=new;
        start=new;
    }
    traverse(start);
}

void insertatend(struct node *start){
    struct node *new;
    new =(struct node*)malloc(sizeof(struct node));
    printf("give the data to be stored in the inserting node:");
    scanf("%d",&(new->data));
    if(start==NULL){
        start->next=start->prev=start=tail=new;
    }
    else{
        tail->next=new;
        new->prev=tail;
        new->next=start;
        start->prev=new;
        tail=new;
    }
    traverse(start);
}

void insertatpos(struct node *start){
    struct node *new;
    new =(struct node*)malloc(sizeof(struct node));
    printf("give the data to be stored in the inserting node:");
    scanf("%d",&(new->data));
    if(start==NULL){
        start->next=start->prev=start=tail=new;
    }
    else{
        printf("\ngive the position where you want to insert the node:");
        int pos,i=1;
        scanf("%d",&pos);
        p=start;
        while(i<pos-1){
            p=p->next;
            i++;
        }
        new->prev=p;
        new->next=p->next;
        p->next->prev=new;
        p->next=new;
    }
    traverse(start);
}

void deleteatbeg(){
    if (start==NULL){
        printf("linked list is empty\n");
    }
    else if (start->next=start){
        
    }
}

int main()
{
	int choice, n = 1;
	printf("1:create\n2:traverse\n3:insertion at beginning\n4:insertion at end\n5:insertion at any position\n6:deletion at beginning\n7:deletion at end\n8:deletion at any position\n9:reverse\n10:search\n11:sorting\n12:concatenation\n:13:EXIT from program\n");
	while (n)
	{
		printf("\nenter the choice :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			start = create();
			break;
		case 2:
			traverse(start);
			break;
		case 3:
			insertatbeg(start);
			break;
		case 4:
			insertatend(start);
			break;
		case 5:
			insertatpos(start);
			break;
		case 6:
			deleteatbeg();
			break;
		/*case 7:
			deleteatend(start);
			break;
		case 8:
			deleteatpos(start);
			break;*/
		case 9:
			reverse(start);
			break;
		/*case 10:
			search(start);
			break;
		case 11:
			sorting(start);
			break;
		case 12:
			concate(start);
			break;*/
		case 13:
			exit(1);
		default:
			printf("invalid entry");
			break;
		}
	}
}

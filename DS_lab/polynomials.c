//lab 6
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int expo;
    int coef;
    struct node *next;
};
struct node *start = NULL, *temp, *p;
struct node *poly_create()
{
    int ex, co, c = 0;
    start = NULL;
    do
    {
        printf("\nenter the coefficient value:");
        scanf("%d", &co);
        printf("\nenter the Exponent value:");
        scanf("%d", &ex);
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->expo = ex;
        temp->coef = co;
        temp->next = NULL;
        if (start == NULL || ex > start->expo)
        {
            temp->next = start;
            start = temp;
        }
        else
        {
            p = start;
            while (p->next != NULL && p->expo > ex)
            {
                p = p->next;
            }
            if(p->expo==ex){
                p->coef=p->coef+co;
            }
            else{
            temp->next = p->next;
            p->next = temp;
            }
        }
        printf("\ndo you want to create another node(1/0)");
        scanf("%d", &c);
    } while (c);
    return start;
}
void traverse(struct node *p)
{
    if (p == NULL)
    {
        printf("Polynomial is not created\n");
        p = poly_create();
        traverse(p);
    }
    else
    {
        while (p->next != NULL)
        {
            printf("%dx^%d+", p->coef, p->expo);
            p = p->next;
        }
        printf("%dx^%d\n", p->coef, p->expo);
    }
}
struct node *poly_add(struct node *p1, struct node *p2)
{
    struct node *p3, *start3 = NULL;
    if (p1 == NULL && p2 == NULL)
    {
        printf("Both polynomials are null");
        return start3;
    }
    else
    {
        while (p1 != NULL && p2 != NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            if (start3 == NULL)
            {
                start3 = temp;
                p3 = temp;
            }
            else
            {
                p3->next = temp;
                p3 = temp;
            }
            if (p1->expo > p2->expo)
            {
                temp->expo = p1->expo;
                temp->coef = p1->coef;
                p1 = p1->next;
            }
            else if (p2->expo > p1->expo)
            {
                temp->expo = p2->expo;
                temp->coef = p2->coef;
                p2 = p2->next;
            }
            else if (p1->expo == p2->expo)
            {
                temp->expo = p1->expo;
                temp->coef = (p1->coef + p2->coef);
                p1 = p1->next;
                p2 = p2->next;
            }
            else
            {
                printf("Some error occured");
            }
        }
        p = NULL;
        if (p1 == NULL)
        {
            p = p2;
        }
        else if (p2 == NULL)
        {
            p = p1;
        }
        else
        {
            p = NULL;
        }
        while (p != NULL)
        {
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            if (start3 == NULL)
            {
                start = temp;
                p3 = temp;
            }
            else
            {
                p3->next = temp;
                p3 = temp;
            }
            temp->expo = p->expo;
            temp->coef = p->coef;
            temp->next = NULL;
            p = p->next;
        }
    }
    return start3;
}

void main()
{
    int choice, n = 1;
    while (n)
    {
        printf("1.Polynomial Creation\n2.Traverse\n3.Polynomial addition(Adding two polynomials)\n4.Exit from program\nGive your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = poly_create();
            printf("the created polynomial is:");
            traverse(start);
            break;
        case 2:
            traverse(start);
            break;
        case 3:
            int x;
            struct node *start1, *start2, *start3;
            printf("do you want to take two new polynomials or take one new and use the existing polynomial for additon(2/1)\n");
        label1:
            scanf("%d", &x);
            if (x == 2)
            {
                printf("\ncreate the first polynomial\n");
                start1 = poly_create();
                printf("\nThe first polynomial is:");
                traverse(start1);
                printf("create the second polynomial\n");
                start2 = poly_create();
                printf("\nThe second polynomial is:");
                traverse(start2);
                printf("\nthe sum of given two polynomials is:");
                start3 = poly_add(start1, start2);
                traverse(start3);
            }
            else if (x == 1)
            {
                start1 = start;
                printf("\nThe first polynomial is:");
                traverse(start1);
                printf("create the second polynomial\n");
                start2 = poly_create();
                printf("\nThe second polynomial is:");
                traverse(start2);
                printf("\nthe sum of given two polynomials is:");
                start3 = poly_add(start1, start2);
                traverse(start3);
            }
            else
            {
                printf("invalid input , give only one(1) or two(2)");
                goto label1;
            }

            break;
        case 4:
            exit(1);
        default:
            printf("invalid choice");
            break;
        }
    }
}
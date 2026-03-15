#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
    int id;
    char name[20];
    float gpa;
    struct a{
        char village[20];
        char mandal[20];
        char district[10];
    }ad;
};
void main(){
    int n,i,j;
    printf("enter no of students:");
    scanf("%d",&n);
    struct student s[n];
    for (i=0;i<n;i++){
        printf("enter %d th student details\n",i+1);
        printf("enter id");
        scanf("%d",&s[i].id);
        printf("enter name:");
        scanf("%s",&s[i].name);
        printf("enter gpa:");
        scanf("%f",&s[i].gpa);
        printf("enter village:");
        scanf("%s",&s[i].ad.village);
        printf("enter mandal:");
        scanf("%s",&s[i].ad.mandal);
        printf("enter district:");
        scanf("%s",&s[i].ad.district);
        printf("\n");
    }
        for (i=0;i<n;i++){
        printf("student details are\n");
        printf("id:%d\n",&s[i].id);
        printf("name:%s\n",&s[i].name);
        printf("gpa:%f\n",&s[i].gpa);
        printf("village:%s\n",&s[i].ad.village);
        printf("mandal:%s\n",&s[i].ad.mandal);
        printf("district:%s\n",&s[i].ad.district);
        printf("\n");
        }
}
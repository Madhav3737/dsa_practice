#include<stdio.h>
int gcd(int,int);
int gcd(int a,int b){
    int r;
    r=b%a;
    if(r==0){
        return a;
    }
    else{
        gcd(r,a);
    }
}
int main(){
    int n1,n2,hcf;
    printf("enter the two numbers:-");
    scanf("%d%d",&n1,&n2);
    if (n1<n2){
        hcf=gcd(n1,n2);
    }
    else if(n1>n2){
        hcf=gcd(n2,n1);
    }
    else if (n1==n2){
        hcf=n1;
    }
    else{
        printf("enter valid numbers");
    }
    printf("the gcd of the given two numbers is %d",hcf);
}
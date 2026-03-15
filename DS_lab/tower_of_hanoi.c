#include<stdio.h>
void tower(int,char,char,char);
int main()
{
int n;
printf("enter the number of rings:");
scanf("%d",&n);
printf("The sequence of moves involved in the tower of hanoi are:\n");
tower(n,'A','C','B');
return 0;
}
void tower(int n,char source,char dest,char spare)
{
if(n==1){
printf("\n Move from %c to %c",source,dest);
}
else
{
tower(n-1,source,spare,dest);
tower(1,source,dest,spare);
tower(n-1,spare,dest,source);
}
}
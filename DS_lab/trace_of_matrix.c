#include<stdio.h>
int main(){
    printf("give no fo rows and coloumns");
    int r,c;
    scanf("%d%d",&r,&c);
    if (r==c){
    int a[r][c],i,j;
    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("give the a[%d][%d] th element:-",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("the given matrix is\n");
    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    int sum=0;
    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            if(i==j){
                sum=sum+a[i][j];
            }
        }
    }
    printf("\nthe trace of the matrix is %d",sum);
    }
    else{
        printf("the matrix should be asquare matrix");
    }

}

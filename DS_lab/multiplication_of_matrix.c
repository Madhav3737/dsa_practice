#include <stdio.h>
void main(){
    int r1,c1,r2,c2,i,j,k;
    printf("give the no of rows and coloumns of the two arrays r1 c1 and r2 c2\n note:- c1 must be equal to r2\n");
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    int c[r1][c2];
    if (c1==r2){
    int a[r1][c1],b[r2][c2];
    printf("give the elements of the first array\n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&a[i][j]);
        }
    }            printf("\t");
    printf("give the elements of the second array\n");
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&b[i][j]);
        }
    }
    
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                c[i][j] = 0;
                for (k=0;k<c1;k++){
                    c[i][j] = c[i][j]+(a[i][k]*b[k][j]);
                }
            }
        }
    }
    else{
        printf("multiplication is not possible");
    }
    printf("the multiplication of matrices is \n");
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

}
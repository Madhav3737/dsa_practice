int a[];
void insertion_sort(int a[],int n){
    int i,j,key;
    for(i=0;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
void main(){
    int n,i;
    printf("How many elements do you want to give:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("give the %dth element:",i);
        scanf("%d",&a[i]);
    }
    printf("Entered elements:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    insertion_sort(a,n);
    printf("Sorted elements:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }


}
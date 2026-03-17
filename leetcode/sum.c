

 struct ListNode {
      int val;
    struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result,*temp1,*temp2,*tempR,*temp;
    temp1=l1;temp2=l2;
    int i,j,carry,sum;
    // int count1=0 ,count2=0,count=0;
    // while(temp1!=NULL){
    //     count1=count1+1;
    //     temp1=temp1->next;
    // }
    // while(temp2!=NULL){
    //     count2=count2+1;
    //     temp2=temp2->next;
    // }
    // if(count1<count2){
    //     count=count1;
    // }
    // else{
    //     count = count2;
    // }
    //temp1=l1;temp2=l2;
    while(temp1!=NULL&&temp2!=NULL){
        if (tempR==NULL){
            tempR = (struct ListNode *)malloc(sizeof(struct ListNode));
            result=tempR;
            sum=temp1->val+temp2->val;
            temp1=temp1->next;
            temp2=temp2->next;
            tempR->val=sum%10;
            carry=floor(sum/10);
        }
        else{
            temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            tempR->next = temp;
            tempR = temp;
            sum = carry+temp1->val+temp2->val;
            temp1=temp1->next;
            temp2=temp2->next;
            tempR->val=sum%10;
            carry=floor(sum/10);
        }
    }
    while(temp1!=NULL){
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            tempR->next = temp;
            tempR = temp;
            tempR->val=temp1->val+carry;
            carry=0;
            temp1=temp1->next;
    }
        while(temp2!=NULL){
        temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            tempR->next = temp;
            tempR = temp;
            tempR->val=temp2->val+carry;
            carry=0;
            temp2=temp2->next;
    }
   return result;
}
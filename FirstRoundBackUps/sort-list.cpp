/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
    MergeSort(headRef)
    If head == NULL or åªæä¸ä¸ªåç´ 
        then return
    Else å°é¾è¡¨åä¸ºä¸¤ä¸ªé¨å 
        FrontBackSplit(head, &a, &b);  a,båå«ä»£è¡¨åå²åçé¾è¡¨ 
    åå«å¯¹a,bæåº
        MergeSort(a);
        MergeSort(b);
    åå¹¶å·²æåºça,b ï¼å¹¶è·æ° å¤´æéheadRef
        *headRef = SortedMerge(a, b);
*/

class Solution {
public:
ListNode* MergeSort(ListNode*head){
    if(!head)return head;
    if(head->next==NULL)return head;
    auto mid=splitlist(head);
    head=MergeSort(head);
    mid=MergeSort(mid);
    
    //åå¹¶ä¸¤ä¸ªé¾è¡¨å°ç¬¬äºä¸ªé¾è¡¨åå¹¶å°ç¬¬ä¸ä¸ªä¸é¢
    ListNode*h=new ListNode(-1);
    h->next=head;
    ListNode*q=h,*p=h->next,*p2=mid;
    while(p2&&p){
        auto tmp=p2->next;
        if(p->val<p2->val){
            q=p,p=p->next;
        }else{
            q->next=p2,p2->next=p;
            q=q->next;
            p2=tmp;
        }
        
    }
    if(!p)
        q->next=p2;
    return h->next;
}
public:
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
public:
ListNode* splitlist(ListNode*head){//åå²é¾è¡¨æä¸¤é¨å,è¦æ±ç¬¬äºé¨åæå¤æ¯ç¬¬ä¸é¨åå¤ä¸ä¸ªåç´ 
    ListNode*fast=head,*slow=head;
    while(1){
        //å¿«æéè¿ä¸¤ä¸ª
        fast=fast->next->next;
        slow=slow->next;
        if(fast==NULL||fast->next==NULL||fast->next->next==NULL){
            break;
        }
    }
    //å¹¶ä¸å°ä¸ä¸ä¸ªçæåä¸ä¸ªç½®ä¸ºé¶
    ListNode*p=head;
    while(p->next!=slow){
        p=p->next;
    }
    p->next=NULL;
    //è¿åä¸­é´çå¼
    return slow;
    }
};
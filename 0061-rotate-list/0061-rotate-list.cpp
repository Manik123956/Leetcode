/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 0){
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            count++;
        }
        k = k % count;
        if(k == 0){
            return head;
        }
        temp = head;
        for(int i = 1; i < count - k; i++){
            temp = temp -> next;
        }
        ListNode* newhead = temp -> next ;
        temp -> next = NULL;
        ListNode *last = newhead;
        while(last -> next != NULL){
            last = last -> next;
        }
        last -> next = head;
        return newhead;
    }
};
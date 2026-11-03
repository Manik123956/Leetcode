/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int count = 0;
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    k = k % count;
    if (k == 0)
        return head;
    struct ListNode *temp = head, *curr;
    int step = count - k;
    for (int i = 1; i < step; i++) {
        temp = temp->next;
    }
    curr = temp->next;
    temp->next = NULL;
    struct ListNode* p = curr;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = head;
    return curr;
}
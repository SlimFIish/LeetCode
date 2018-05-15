/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    typedef struct ListNode node;
    int val1, val2, tmp, sum, carry = 0;
    node *p1, *p2, *head, *q, *new;
    
    if(!l1) return l2;
    if(!l2) return l1;
    
    p1 = l1;
    p2 = l2;
    
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
    q = head;
    
    while(carry || p1 || p2){
        val1 = ( p1 != NULL ? p1->val : 0);
        p1 = ( p1 != NULL ? p1->next : NULL);
        
        val2 = ( p2 != NULL ? p2->val : 0);
        p2 = ( p2 != NULL ? p2->next : NULL);
        
        tmp = val1 + val2 + carry;
        carry = tmp/10;
        sum = tmp%10;
        
        q->val = sum;
        q->next = (node *)malloc(sizeof(node));
        new = q;
        q = q->next;
    }
    free(new->next);
    new->next = NULL;
    
    return head;
}

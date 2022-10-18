/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = 0;
        
        ListNode * cur = head;
        ListNode *curr = head, *prev = NULL;
        
        while(cur){
            
            size++;
            cur = cur->next;
        }
        
        if(size == 1){
            
            if(n == 0) return head;
            else return NULL;
        }else if( size == n){
            
            return head->next;
        }
        
        int rem = size - n;
        
        while(rem--){
            
            prev = curr;
            curr = curr->next;
            
        }
        
        prev->next = curr->next;
        
        
        return head;
    }
};
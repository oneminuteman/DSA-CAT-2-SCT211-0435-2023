//Question One (1): Detect Cycle in a Linked List

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (slow != fast) {
        if (!fast || !fast->next) return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // For debugging purposes
    std::cout << "Cycle detected" << std::endl;
    
    return true;
}


//Question Two (2): Detect the Node Where the Cycle Begins

ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return nullptr;
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    
    return nullptr;
}

//Question Three (3): Reverse a Linked List

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *nextNode;
    
    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    
    return prev;
}


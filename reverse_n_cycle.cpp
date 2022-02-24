#include <iostream>

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int hasCycle(ListNode *head)
{
    ListNode* regular = head;
    ListNode* f_forward = head;

    while(f_forward != nullptr && f_forward->next != nullptr)
    {
        regular = regular->next;
        f_forward = f_forward->next->next;

        if(regular == f_forward)
            return 1;
    }
    return 0;
}

ListNode* reverse(ListNode *head)
{
    ListNode* current = nullptr;
    ListNode* previous = nullptr;

    while(head != nullptr)
    {
        current = head;
        head = head->next;
        current->next = previous;
        previous = current;
    }
    return current;
}
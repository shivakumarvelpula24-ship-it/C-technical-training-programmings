struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode dummy;
    struct ListNode *temp = &dummy;
    int sum, carry = 0;

    dummy.next = NULL;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        sum = carry;

        if (l1 != NULL)
        {
            sum = sum + l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
    {
        
            sum = sum + l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        temp->next = malloc(sizeof(struct ListNode));
        temp = temp->next;

        temp->val = sum % 10;
        temp->next = NULL;
    }

    return dummy.next;
}
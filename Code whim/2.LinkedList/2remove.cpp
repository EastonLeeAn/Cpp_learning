#include <iostream>

struct ListNode
{
    int val;                                // 节点上存储的元素
    ListNode *next;                         // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数 初始化
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val) // 避免内存开销
    {
        // 删除头结点
        while (head != NULL && head->val == val)
        { // 注意这里不是if 连续几个都是val的情况
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }

    ListNode *removeElements1(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点

        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        //-> 是 C++ 中的成员访问运算符，用于通过指针访问对象的成员。
        ListNode *cur = dummyHead;

        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
    }

    ListNode *removeElements2(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *cur = dummyHead; // 当前节点
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            { // next的val
                ListNode *tmp = cur->next;
                cur->next == cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        // return dummyHead -> next;.
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
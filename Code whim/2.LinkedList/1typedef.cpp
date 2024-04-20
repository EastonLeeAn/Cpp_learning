// 单链表
#include <cstddef>

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数 初始化
};

ListNode* head = new ListNode(5);
// ListNode* head = new ListNode(); 构造函数
// head->val = 5;

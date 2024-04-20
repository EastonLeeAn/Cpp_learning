#include <iostream>
using namespace std;

class MyLinkedList
{
public:
    // 定义链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList()
    {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }
    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index)
    {
        if (index > (_size - 1) || index < 0)
        {
            return -1;
        }
        LinkedNode *cur = _dummyHead->next;
        while (index--) // 先判断在减
        {               // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }
    void addAtHead(int val) // void 无返回值
    {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    void addAtTail(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val)
    {
        if (index > _size)
            return;
        if (index < 0)
            index = 0;
        LinkedNode *newNode = new LinkedNode(val);
           LinkedNode* cur = _dummyHead;
           while (index--){
            cur = cur ->next;
           }
           newNode->next = cur->next;
           cur -> next = newNode;
           _size++;

    }
    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while(index--) {
            cur = cur ->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp=nullptr;
        _size--;
    }

    // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode *_dummyHead;
};
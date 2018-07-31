// 面试题目6： 从尾到头打印链表 
#include <iostream>

using namespace std;
struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};
// 初始化链表 
ListNode* InitList()
{
    ListNode *p = new ListNode;
    p->m_pNext = NULL;
    return p;
}
// 创建链表 
void CreateList(ListNode *list, int len)
{
    ListNode *rear;
    rear = list;
    while(len--)
    {
        ListNode *tmp = new ListNode;
        cin>>tmp->m_nKey;
        tmp->m_pNext = NULL;
        rear->m_pNext = tmp;
        rear = tmp;
    }
}
int count;
void PrintListReversingly_Recursively(ListNode *list,int len)
{
    count ++ ;
    if(list->m_pNext != NULL)
    {
        PrintListReversingly_Recursively(list->m_pNext,len-1);
    }
    if(count != len+1)
    cout<<list->m_nKey<<' ';
}
int main()
{
    int len;
    cout<<"请输入链表长度: ";
    cin>>len;
    ListNode *list;
    list = InitList();
    CreateList(list,len);
    count = 0;
    PrintListReversingly_Recursively(list,len);
    return 0;
}

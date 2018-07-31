#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    char m_pValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{

    if(pNode == NULL)
        return NULL;
    BinaryTreeNode* pNext = NULL;
    // ���ýڵ����Һ��ӵ����
    if(pNode->m_pRight != NULL)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != NULL)
            pRight = pRight->m_pLeft;
        pNext = pRight;
    }
    // û���Һ��ӵ����
    else if(pNode->m_pParent != NULL)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        // �ظ��ڵ����ϱ���
        while(pParent != NULL && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}
BinaryTreeNode* TraverseBinaryTree(BinaryTreeNode *Tree,const char value)
{
    if(Tree == NULL)
        return NULL;
    if(Tree->m_pValue == value)
        return Tree;
    BinaryTreeNode *next = TraverseBinaryTree(Tree->m_pLeft,value);
    if(next)
        return next;
    else
    {
        next = TraverseBinaryTree(Tree->m_pRight,value);
        return next;

    }
}
// һ����Ϊ���ӵĶ����� 
BinaryTreeNode* Example()
{
    BinaryTreeNode *root, *level2_1,*level2_2,*level3_1,*level3_2,*level3_3,*level3_4,*level4_3,*level4_4;
    root = new BinaryTreeNode; level2_1 = new BinaryTreeNode; level2_2 = new BinaryTreeNode;
    level3_1 = new BinaryTreeNode; level3_2 = new BinaryTreeNode; level3_3 = new BinaryTreeNode; level3_4 = new BinaryTreeNode;
    level4_3 = new BinaryTreeNode; level4_4 = new BinaryTreeNode;;
    root->m_pValue = 'a';     root->m_pLeft = level2_1;     root->m_pRight = level2_2;     root->m_pParent = NULL;
    level2_1->m_pValue = 'b'; level2_1->m_pLeft = level3_1; level2_1->m_pRight = level3_2; level2_1->m_pParent = root;
    level2_2->m_pValue = 'c'; level2_2->m_pLeft = level3_3; level2_2->m_pRight = level3_4; level2_2->m_pParent = root;
    level3_1->m_pValue = 'd'; level3_1->m_pLeft = NULL;     level3_1->m_pRight = NULL;     level3_1->m_pParent = level2_1;
    level3_2->m_pValue = 'e'; level3_2->m_pLeft = level4_3; level3_2->m_pRight = level4_4; level3_2->m_pParent = level2_1;
    level3_3->m_pValue = 'f'; level3_3->m_pLeft = NULL;     level3_3->m_pRight = NULL;     level3_3->m_pParent = level2_2;
    level3_4->m_pValue = 'g'; level3_4->m_pLeft = NULL;     level3_4->m_pRight = NULL;     level3_4->m_pParent = level2_2;
    level4_3->m_pValue = 'h'; level4_3->m_pLeft = NULL;     level4_3->m_pRight = NULL;     level4_3->m_pParent = level3_2;
    level4_4->m_pValue = 'i'; level4_4->m_pLeft = NULL;     level4_4->m_pRight = NULL;     level4_4->m_pParent = level3_2;
    return root;
}
int main()
{
    cout<<"�������������У�d,b,h,e,i,a,f,c,g "<<endl;
    cout<<"������Ҫ���ҵĽڵ㣺 ";
    char value;
    cin>>value;
    BinaryTreeNode* pNode,* pNext,* root;
    root = Example();
    pNode = TraverseBinaryTree(root,value);
    cout<<pNode->m_pValue<<endl;
    pNext = GetNext(pNode);
    cout<<"���������иýڵ���һ���ڵ��ǣ� ";
    cout<<pNext->m_pValue;
    return 0;
}

// 面试题目7： 重建二叉树
#include<iostream>
using namespace std;
#define maxSize 100
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;

    return ConstructCore(preorder, preorder + length - 1,
        inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
)
{
    // 前序遍历序列的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            cout<<"Invalid input."<<endl;
    }

    // 在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++ rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        cout<<"Invalid input."<<endl;
    }
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd,
            startInorder, rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder,
            rootInorder + 1, endInorder);
    }

    return root;
}
void visit(BinaryTreeNode *p)
{
    cout << p->m_nValue << " ";
}
void level(BinaryTreeNode *p)
{
    int front,rear;
    BinaryTreeNode *que[maxSize];
    front = rear = 0;
    BinaryTreeNode *q;
    if(p!=0)
    {
        rear=(rear+1)%maxSize;
        que[rear]=p;
        while(front!=rear)
        {
            front = (front+1)%maxSize;
            q=que[front];
            visit(q);
            if(q->m_pLeft!=0)
            {
                rear=(rear+1)%maxSize;
                que[rear]=q->m_pLeft;
            }
            if(q->m_pRight!=0)
            {
                rear=(rear+1)%maxSize;
                que[rear]=q->m_pRight;
            }
        }
    }
}
int main()
{
    cout<<"请输入二叉树的节点数： ";
    int Node_num;
    cin>>Node_num;
    int pre_order[Node_num],mid_order[Node_num];
    cout<<"请输入二叉树的先序序列：";
    for(int i = 0;i < Node_num;i ++)
    {
        cin>>pre_order[i];
    }
    cout<<"请输入二叉树的中序序列： ";
    for(int i = 0;i < Node_num;i++)
    {
        cin>>mid_order[i];
    }
    BinaryTreeNode* BiTree;
    BiTree = Construct(pre_order,mid_order,Node_num);
    cout<<"该二叉树层次遍历序列为: ";
    level(BiTree);
    return 0;
}

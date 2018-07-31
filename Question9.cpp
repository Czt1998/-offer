#include <iostream>
#include <stack>
using namespace std;
#define Elemtype char
class CQueue
{
public:
    void appendTail(Elemtype node);
    Elemtype deleteHead();

private:
    stack<Elemtype>stack1;
    stack<Elemtype>stack2;
};
// 入队操作 
void CQueue::appendTail(Elemtype node)
{
    stack1.push(node);
    cout<<"操作成功."<<endl;
}
// 出队操作 
Elemtype CQueue::deleteHead()
{
    if(stack2.size()<=0)
    {
    	// 首先把stack1的元素压进stack2 
        while(stack1.size()>0)
        {
            Elemtype data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0)
        return '\0';
	// stack2为stack1的逆向序列 
    Elemtype head = stack2.top();
    stack2.pop();
    return head;
}
int main()
{
    CQueue cqueue;
    while(1)
    {
        int choice;
        Elemtype ch,head;
        cout<<"  =============="<<endl;
        cout<<"|| 请选择操作： ||"<<endl;
        cout<<"|| 1. 入队.     ||"<<endl;
        cout<<"|| 2. 出队.     ||"<<endl;
        cout<<"|| 0. 退出      ||"<<endl;
        cout<<"  =============="<<endl;
        cin>>choice;
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:
                cout<<"请输入插入的元素（单字符）： ";
                cin>>ch;
                cqueue.appendTail(ch);
                break;
            case 2:
                head = cqueue.deleteHead();
                if(head)
                {
                    cout<<"队首元素为： ";
                    cout<<head<<endl;
                }
                else
                {
                    cout<<"队列为空."<<endl;
                }
                break;
        }
    }
    return 0;
}

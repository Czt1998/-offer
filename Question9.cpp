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
// ��Ӳ��� 
void CQueue::appendTail(Elemtype node)
{
    stack1.push(node);
    cout<<"�����ɹ�."<<endl;
}
// ���Ӳ��� 
Elemtype CQueue::deleteHead()
{
    if(stack2.size()<=0)
    {
    	// ���Ȱ�stack1��Ԫ��ѹ��stack2 
        while(stack1.size()>0)
        {
            Elemtype data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    if(stack2.size()==0)
        return '\0';
	// stack2Ϊstack1���������� 
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
        cout<<"|| ��ѡ������� ||"<<endl;
        cout<<"|| 1. ���.     ||"<<endl;
        cout<<"|| 2. ����.     ||"<<endl;
        cout<<"|| 0. �˳�      ||"<<endl;
        cout<<"  =============="<<endl;
        cin>>choice;
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:
                cout<<"����������Ԫ�أ����ַ����� ";
                cin>>ch;
                cqueue.appendTail(ch);
                break;
            case 2:
                head = cqueue.deleteHead();
                if(head)
                {
                    cout<<"����Ԫ��Ϊ�� ";
                    cout<<head<<endl;
                }
                else
                {
                    cout<<"����Ϊ��."<<endl;
                }
                break;
        }
    }
    return 0;
}

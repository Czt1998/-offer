// ������Ŀ5�� �滻�ո� 
#include <iostream>
#include<string>
#include<cstring>
using namespace std;
void Replace(char *str)
{
    int len,count = 0;
    len = strlen(str);
    // ������Ҫ���Ӷ��ٸ�λ�� 
    for(int i=0;i<len;i++)
    {
        if(str[i] == ' ')
        {
            count++;
        }
    }
    int p1,p2;
    p1 = len;
    p2 = len+2*count;
    // ѭ���ƶ�ָ�� 
    while(p1 != p2 && p1>=0)
    {
        if(str[p1] != ' ')
        {
            str[p2]=str[p1];
            --p1;
            --p2;
        }
        else
        {
            --p1;
            str[p2]='0';
            str[--p2]='2';
            str[--p2]='%';
            --p2;
        }
    }
    cout<<str;
}
int main()
{
    cout<<"�������ַ����� ";
    char str[100];
    cin.getline(str,100);
    Replace(str);
    return 0;
}

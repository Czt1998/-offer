// ������ 3: �������ظ�������
#include<iostream>
#include<cstring> 
using namespace std;
void Find_Double(int arry[],int len)
{
	int jud[len],*dou,count=0;
	memset(jud,0,sizeof(jud));
	for(int i=1;i<len;i++)
	{
		jud[arry[i]]+=1;
	}
	for(int i=0;i<len;i++)
	{
		cout<<jud[i]<<' ';
		if(jud[i]>1)
		{
			dou[count]=i;
			count++;
		}
	}
	dou[count]='\0';
	for(int i=0;i<count;i++)
	{
		cout<<dou[i]<<' ';
	}
//	return dou;
}
int main()
{
	int len;
	cout<<"���������鳤�ȣ� ";
	cin>>len;
	int arry[len];
	cout<<"���������飺 ";
	for(int i=0;i<len;i++)
	{
		cin>>arry[i];
	}
	int *Double_Number;
	Find_Double(arry,len);
	int l;
	sizeof(Double_Number)/sizeof(int);
//	for(int i=0;i<l;i++)
//	cout<<Double_Number[i]<<' ';
	return 0;
}

//面试题目1： 赋值运算符函数
#include<iostream>
#include<cstring>
using namespace std;
class CMyString
{
	public:
		CMyString(char *pData=NULL); //拷贝构造函数 
		CMyString(const CMyString &str); //拷贝构造函数 
		~CMyString(void); //析构函数 
	private:
		char *m_pData;
};
CMyString::CMyString(char *pData) //定义拷贝方式 
{
    if(pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str) //处理引用型变量拷贝构造函数 
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString() //析构函数，释放存放数据的空间 
{
    delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString &str) // 赋值函数 
{
	if(this!=&str) // 判断是否相同，若相同不进行接下来的步骤 
	{
		CMyString strTemp(str); //创建临时实例，调用构造函数并初始化 
		char *pTemp=strTemp.m_pData; //申请临时字符型指针存放实例中 m_pData 的数据地址 
		strTemp.m_pData=m_pData; // 将交换临时实例与实例的 m_pData 
		m_pData=pTemp; // 将临时字符型指针中的地址赋给实例 
	}
	// 结束 if 时会调用析构函数释放临时实例的空间 
	// 此时实例的数据地址已经改变 
	return this;
}

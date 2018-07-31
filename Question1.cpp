//������Ŀ1�� ��ֵ���������
#include<iostream>
#include<cstring>
using namespace std;
class CMyString
{
	public:
		CMyString(char *pData=NULL); //�������캯�� 
		CMyString(const CMyString &str); //�������캯�� 
		~CMyString(void); //�������� 
	private:
		char *m_pData;
};
CMyString::CMyString(char *pData) //���忽����ʽ 
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

CMyString::CMyString(const CMyString &str) //���������ͱ����������캯�� 
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString() //�����������ͷŴ�����ݵĿռ� 
{
    delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString &str) // ��ֵ���� 
{
	if(this!=&str) // �ж��Ƿ���ͬ������ͬ�����н������Ĳ��� 
	{
		CMyString strTemp(str); //������ʱʵ�������ù��캯������ʼ�� 
		char *pTemp=strTemp.m_pData; //������ʱ�ַ���ָ����ʵ���� m_pData �����ݵ�ַ 
		strTemp.m_pData=m_pData; // ��������ʱʵ����ʵ���� m_pData 
		m_pData=pTemp; // ����ʱ�ַ���ָ���еĵ�ַ����ʵ�� 
	}
	// ���� if ʱ��������������ͷ���ʱʵ���Ŀռ� 
	// ��ʱʵ�������ݵ�ַ�Ѿ��ı� 
	return this;
}

#include <iostream>
#include <conio.h>
using namespace std;
class stek				//����� ������ ����������, ����� �� ������ � ������������ std::stack
{
	int n[100];		//����������, ������ ������
	int length;
public:
	stek()
	{
		for (int i=0; i<100; i++)		//�������� ���� ��� ��������
			n[i]=0;
		length=0;
	}
	void push(int elem)						//���������� ��������
	{
		n[length]=elem;
		length++;
	}
	bool isEmpty()							//�������� �� �������
	{
		return !(length);
	}
	void pop()								//�������� ��������
	{
		if (!isEmpty())
		{
		n[length-1]=0;
		length--;
		}
	}
	int top()								//��������� �������� ��������
	{		
		if (!isEmpty())
		return n[length-1];
		else
			return 0;
	}
};
void main()
{
	stek st1;
	st1.push(0);
	st1.push(1);
	st1.push(2);
	cout<<st1.top()<<"\t";
	st1.pop();
	cout<<st1.top();
	getch();
}
#include <iostream>
#include <conio.h>
using namespace std;
const int len=4; //���������� ����� � �������
class queue
{
	int n[len];			//����������, ������ ������
	int first, last, length;
public:
	queue()
	{
		for (int i=0; i<len; i++)		//�������� ������� ��� ��������
			n[i]=0;
			first=last=0;
			length=0;
	}
	void push(int elem)			//���������� ��������
	{
		if (length!=len)		//���� ��� ���� �����...
		{
			if (length)					//���� ������� �����, ������ � ��������� �������� ���������, ����� ���������� ����� � ��������� � �� ����������� "���������"
			{									//���� �� ������� �� �����, �� ����������� "���������" � ���������� � ����� �����.
				last=(last+1)%len;		//��� ����, ���� "���������" ��������� � ������ "�����������" ����� �������, ��� ��� ����������� "�����������" �������
			}
			n[last]=elem;
			length++;
		}
	}
	void pop()					//�������� ��������
	{
		n[first]=0;
		first=(first+1)%len;
		length--;
	}
	int top()					//����������� �������� ��������
	{
		if (length)		//���� ������� �� �����...
			return n[first];
		else return 0;
	}
};
void main()
{
	queue qu1;
	qu1.push(1);
	qu1.push(2);
	qu1.push(3);
	qu1.pop();
	qu1.push(4);
	qu1.pop();
	qu1.pop();
	qu1.push(5);
	qu1.push(6);
	getch();
}
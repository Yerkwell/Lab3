#include <conio.h>
#include <iostream>
using namespace std;
class elem
{
	int n;
	elem* next;
	elem* prev;
public:
	elem():next(NULL),prev(NULL){};					//����������� ��-��������� (�� ������ ������)
	elem(int newn):n(newn),next(NULL),prev(NULL){};	//����������� � �������������� �����
	/*
	���� - ������ ��������� � ������� �������� �����
	*/
	void setN(int zn)
	{
		n=zn;
	}
	int getN()
	{
		return n;
	}
	void setNext(elem *uk)
	{
		next=uk;
	}
	void setPrev(elem *uk)
	{
		prev=uk;
	}
	elem* getNext()
	{
		return next;
	}
	elem* getPrev()
	{
		return prev;
	}
};
class spisok
{
	int length;
	elem* first;
	elem* last;
public:
	spisok():length(0),first(0),last(0){};
	void paste(int n)					//������� � �����
	{
		elem *newelem=new elem(n);
		newelem->setPrev(last);			//���� ������ ����, ��������� prev ����� ������
		if (!first)						//���� ������ ����, ����� ������� ����� ������
		{
			first=newelem;
		}
		else
			last->setNext(newelem);		//����� - ����� �� ���������
		last=newelem;					
		length++;
	}
	/*���������� ������������� ������� paste. ���� �� ������� ����� ��� �������, ������� ������������ � �����*/
	void paste(int n, int i)			//������� � ����� �����
	{
		if (i<length)
		{
		elem *newelem=new elem(n);
		elem *tek=first;
		for (int j=0; j<i; j++)			//��������� � ���� ��������, ����� ������� ����� ���������
		{
			tek=tek->getNext();
		}
		newelem->setNext(tek);
		newelem->setPrev(tek->getPrev());		//���� ������� �� ����� 0, �� tek->getPrev()==0
		if (tek->getPrev())						//� ��� ��� �������� ������ ���� i>0
			(tek->getPrev())->setNext(newelem);
		tek->setPrev(newelem);
		if (i==0) first=newelem;				//���� �� �� � ������ ���������, �� ����� �������, ��� ���� ������� ������ ������
		length++;
		}
		else if(i==length)				//���� ������� � �����, �� ���������� ��� ������������ ��������
		{
			paste(n);
		}
	}
	void deleteElem(int i)				//�������� �������� �� ������
	{
		if (i<length)
		{
		elem *tek=first;
		for (int j=0; j<i; j++)
		{
			tek=tek->getNext();			//��������� � ���������� ��������
		}
		if (tek->getNext())
		(tek->getNext())->setPrev(tek->getPrev());		//���� �� �� ���������, ��������� ��������� ����������
		else
			last=tek->getPrev();						//����� ���������� ��������� �� ���������
		if (tek->getPrev())
			(tek->getPrev())->setNext(tek->getNext());	//���� �� �� ������, ��������� ��������� �����������
		else 
			first=tek->getNext();						//����� ���������� ��������� �� ������
		delete tek;						//�� ��������� ����� ������� ������, ����� ���������� ���������
		length--;
		}
	}
	int getN(int i)					//��������� �������� �������� �� ������
	{
		if (i<length)
		{
		elem *tek=first;
		for (int j=0; j<i; j++)
		{
			tek=tek->getNext();
		}
		return tek->getN();
		}
		else
		return 0;
	}
	void print()					//������ ������
	{
		for (int i=0; i<length; i++)
		{
			cout<<getN(i)<<"\t";
		}
	}
};
void main()
{
	spisok sp1;
	/*�������� ������ �������*/
	sp1.paste(0);
	sp1.paste(1);	
	sp1.paste(2);
	sp1.paste(3);
	sp1.paste(0,0);
	sp1.paste(1,1);
	sp1.paste(12,0);
	sp1.paste(2,2);
	sp1.paste(3,3);
	sp1.paste(5,1);
	sp1.deleteElem(5);
	sp1.print();
	getch();
}
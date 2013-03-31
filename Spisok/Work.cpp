#include <conio.h>
#include <iostream>
using namespace std;
class elem
{
	int n;
	elem* next;
	elem* prev;
public:
	elem():next(NULL),prev(NULL){};					//Конструктор по-умолчанию (на всякий случай)
	elem(int newn):n(newn),next(NULL),prev(NULL){};	//Конструктор с инициализацией полей
	/*
	Ниже - методы получения и задания значения полей
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
	void paste(int n)					//Вставка в конец
	{
		elem *newelem=new elem(n);
		newelem->setPrev(last);			//Если список пуст, указатель prev будет пустым
		if (!first)						//Если список пуст, новый элемент будет первым
		{
			first=newelem;
		}
		else
			last->setNext(newelem);		//Иначе - вслед за последним
		last=newelem;					
		length++;
	}
	/*Используем перегруженную функцию paste. Если не указано место для вставки, вставка производится в конец*/
	void paste(int n, int i)			//Вставка в любое место
	{
		if (i<length)
		{
		elem *newelem=new elem(n);
		elem *tek=first;
		for (int j=0; j<i; j++)			//Переходим к тому элементу, перед которым будем вставлять
		{
			tek=tek->getNext();
		}
		newelem->setNext(tek);
		newelem->setPrev(tek->getPrev());		//Если вставка на место 0, то tek->getPrev()==0
		if (tek->getPrev())						//А вот это возможно только если i>0
			(tek->getPrev())->setNext(newelem);
		tek->setPrev(newelem);
		if (i==0) first=newelem;				//Если всё же в начало вставляем, то нужно сказать, что этот элемент теперь первый
		length++;
		}
		else if(i==length)				//Если вставка в конец, то пользуемся уже существующей функцией
		{
			paste(n);
		}
	}
	void deleteElem(int i)				//Удаление элемента по номеру
	{
		if (i<length)
		{
		elem *tek=first;
		for (int j=0; j<i; j++)
		{
			tek=tek->getNext();			//Переходим к удаляемому элементу
		}
		if (tek->getNext())
		(tek->getNext())->setPrev(tek->getPrev());		//Если он не последний, переводим указатель следующего
		else
			last=tek->getPrev();						//Иначе перемещаем указатель на последний
		if (tek->getPrev())
			(tek->getPrev())->setNext(tek->getNext());	//Если он не первый, переводим указатель предыдущего
		else 
			first=tek->getNext();						//Иначе перемещаем указатель на первый
		delete tek;						//Со спокойной душой очищаем память, ранее занимаемую элементом
		length--;
		}
	}
	int getN(int i)					//Получение значения элемента по номеру
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
	void print()					//Печать списка
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
	/*Проверка работы функций*/
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
#include <iostream>
#include <conio.h>
using namespace std;
class stek				//Класс назван неграмотно, чтобы не путать с библиотечным std::stack
{
	int n[100];		//Собственно, массив данных
	int length;
public:
	stek()
	{
		for (int i=0; i<100; i++)		//Обнуляем стек при создании
			n[i]=0;
		length=0;
	}
	void push(int elem)						//Добавление элемента
	{
		n[length]=elem;
		length++;
	}
	bool isEmpty()							//Проверка на пустоту
	{
		return !(length);
	}
	void pop()								//Удаление элемента
	{
		if (!isEmpty())
		{
		n[length-1]=0;
		length--;
		}
	}
	int top()								//Получение значения элемента
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
#include <iostream>
#include <conio.h>
using namespace std;
const int len=4; //Количество ячеек в очереди
class queue
{
	int n[len];			//Собственно, массив данных
	int first, last, length;
public:
	queue()
	{
		for (int i=0; i<len; i++)		//Обнуляем очередь при создании
			n[i]=0;
			first=last=0;
			length=0;
	}
	void push(int elem)			//Добавление элемента
	{
		if (length!=len)		//Если ещё есть место...
		{
			if (length)					//Если очередь пуста, первый и последний элементы совпадают, тогда записываем прямо в последний и не передвигаем "указатель"
			{									//Если же очерень не пуста, то передвигаем "указатель" и записываем в новое место.
				last=(last+1)%len;		//При этом, если "указатель" находится в районе "физического" конца массива, даём ему возможность "перескочить" границу
			}
			n[last]=elem;
			length++;
		}
	}
	void pop()					//Удаление элемента
	{
		n[first]=0;
		first=(first+1)%len;
		length--;
	}
	int top()					//Возвращение верхнего элемента
	{
		if (length)		//Если очередь не пуста...
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
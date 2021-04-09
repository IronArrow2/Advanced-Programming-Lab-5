#include "DynTempQueue.h"
#include "DynTempStack.h"
#include "MyRect.h"
#include <iostream>
using namespace std;

int main()
{
	DynTempStack<int> numberStack;
	DynTempStack<MyRect> rectStack;

	DynTempQueue<int> numberQueue;
	DynTempQueue<MyRect> rectQueue;

	cout << "Populating a stack of numbers: " << endl;
	for (int i = 0; i < 11; i++)
	{
		numberStack.push(i);
		numberStack.printStack();
		cout << endl;
	}
	cout << "Depopulating a stack of numbers: " << endl;
	for (int i = 0; i < 10; i++)
	{
		int temp;
		numberStack.pop(temp);
		numberStack.printStack();
		cout << endl;
	}

	cout << endl;

	cout << "Populating a stack of rectangles: " << endl;
	for (int i = 0; i < 11; i++)
	{
		rectStack.push({i, i, i * 2, i * 3});
		rectStack.printStack();
		cout << endl;
	}
	cout << "Depopulating a stack of rectangles: " << endl;
	for (int i = 0; i < 10; i++)
	{
		MyRect temp;
		rectStack.pop(temp);
		rectStack.printStack();
		cout << endl;
	}

	cout << endl;

	cout << "Populating a queue of ints: " << endl;
	for (int i = 0; i < 11; i++)
	{
		numberQueue.enqueue(i * 2);
		numberQueue.printQueue();
		cout << endl;
	}
	cout << "Depopulating a queue of ints: " << endl;
	for (int i = 0; i < 10; i++)
	{
		int temp;
		numberQueue.dequeue(temp);
		numberQueue.printQueue();
		cout << endl;
	}

	cout << endl;

	cout << "Populating a queue of rects: " << endl;
	for (int i = 0; i < 11; i++)
	{
		rectQueue.enqueue({ i * 2, i, 10, i * 10 });
		rectQueue.printQueue();
		cout << endl;
	}
	cout << "Depopulating a queue of rects: " << endl;
	for (int i = 0; i < 10; i++)
	{
		MyRect temp;
		rectQueue.dequeue(temp);
		rectQueue.printQueue();
		cout << endl;
	}
	return 0;
}
#include <cstddef>
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef DYNTEMPQUEUE_H
#define DYNTEMPQUEUE_H

template <class T>
class DynTempQueue
{
private:
	class QueueNode
	{
      friend class DynTempQueue;
	   T value;
      QueueNode *next;
      QueueNode(T value1, QueueNode *next1 = NULL)
      {
         value = value1;
         next = next1;
      }
      void printNode();
	};
	// These track the front and rear of the queue
	QueueNode *front;
	QueueNode *rear;	
public:
   // Constructor and Destructor
   DynTempQueue();
   ~DynTempQueue();
	
	// Member functions
   void enqueue(T num);
   void dequeue(T &num);
   bool isEmpty() const;     
   void clear();
   void printQueue();
};

//************************
// Constructor.          *
//************************
template <class T>
DynTempQueue<T>::DynTempQueue()
{
    front = NULL;
    rear = NULL;
}

//************************
// Destructor.           *
//************************
template <class T>
DynTempQueue<T>::~DynTempQueue()
{
    clear();
}

//********************************************
// Function enqueue inserts the value in num *
// at the rear of the queue.                 *
//********************************************
template <class T>
void DynTempQueue<T>::enqueue(T num)
{
    if (isEmpty())
    {
        front = new QueueNode(num);
        rear = front;
    }
    else
    {
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
}

//**********************************************
// Function dequeue removes the value at the   *
// front of the queue, and copies it into num. *
//**********************************************
template <class T>
void DynTempQueue<T>::dequeue(T& num)
{
    QueueNode* temp;
    if (isEmpty())
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
    else
    {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise.             *
//*********************************************
template <class T>
bool DynTempQueue<T>::isEmpty() const
{
    if (front == NULL)
        return true;
    else
        return false;
}

//********************************************
// Function clear dequeues all the elements  *
// in the queue.                             *
//********************************************
template <class T>
void DynTempQueue<T>::clear()
{
    T value;   // Dummy variable for dequeue

    while (!isEmpty())
        dequeue(value);
}

template<class T>
void DynTempQueue<T>::printQueue()
{
    if (!isEmpty())
    {//the printNode function requires the template data type to have an overloaded << operator in order to work
        front->printNode();
    }
}

template<class T>
void DynTempQueue<T>::QueueNode::printNode()
{//T must have an overloaded << operator in order for this function to work
    cout << value << " ";
    if (next != NULL)
    {
        next->printNode();
    }
}
#endif
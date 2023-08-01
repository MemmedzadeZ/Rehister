#pragma once

#pragma once



template<typename T, int MAX = 10>

class Deque
{
	T arr[MAX];
	int front = -1;
	int rear = -1;


public:

	Deque() = default;
	bool isFull() const { return ((rear + 1) % MAX) == front; }
	bool isEmpty() const { return front = -1; }


	void push_front(const T item)
	{
		if (isFull()) {
			cout << "Front is FULL";
			return;
		}
		if (isEmpty())
		{
			front = 0;
			rear = 0;
		}
		else
			front = front - 1;

		arr[front] = item;
	}

	void push_rear(const T item)
	{
		if (isFull()) {
			cout << "Rear is Full:";
			return;
		}

		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else
			rear = rear + 1;

		arr[rear] = item;

	}

	void pop_front()
	{
		if (isEmpty())
		{
			cout << "Front is Empty:";
			return;
		}
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
			front = front + 1;
	}

	void pop_rear()
	{
		if (isEmpty())
		{
			cout << "Rear is Empty:";
			return;
		}
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
			rear = rear - 1;
	}


	const T& getFront() const
	{
		if (isEmpty())
		{
			cout << " GetFron is empty" << endl;
			return -1;
		}
		return arr[front];
	}

	const T& getRear() const
	{
		if (isEmpty())
		{
			cout << "GetRear is Empty" << endl;
			return -1;
		}
		return arr[rear];
	}


};
#include <iostream>

using namespace std;
#include "Deque.h"

template<typename T>
int main()
{

	Deque<T> deq(5);

	deq.push_rear(2);
	deq.push_front(8);
	deq.push_front(8);
	deq.push_front(6);
	deq.push_front(9);

	deq.pop_rear();
	deq.pop_front();


}
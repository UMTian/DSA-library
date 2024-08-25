#include<iostream>
#include "mylibrary.h"
using namespace std;
int main()
{
	array a1(10);
	a1.insert_at_end(9);
	a1.insert_at_end(3);
	a1.insert_at_end(7);
	a1.insert_at_end(6);
	a1.display();
	a1.find_max();
	a1.insertion_sort();
	a1.display();
	
	singly_linked_list L1(3);
	L1.insert_at_end(10);
	L1.insert_at_end(89);
	L1.insert_at_end(67);
	L1.display();
}

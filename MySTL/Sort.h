#ifndef SORT_H
#define SORT_H

class Sort
{
public:
	Sort();
	virtual ~Sort();

public:
	int Bubble_sort(int* array, int array_len);
	int Quick_sort();

};


#endif
#include "sort.h"

int Sort::Bubble_sort(int* array, int array_len)
{
	int iTemp;
	for (int i = 0; i < array_len -1; i++)
	{
		for(int j =0; j < array_len -1; j++)
		{
			if(array[j] > array[j + 1])
			{
				iTemp = array[j];
				array[j] = array[j+1];
				array[j+1] =  iTemp;
			}
		}
	}
	return 0;
}


int Sort::Quick_sort()
{

	return 0;
}
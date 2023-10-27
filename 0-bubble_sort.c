#include "sort.h"
/**
 * bubble_sort - sort data
 * @array: data
 * @size: size of data
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	int new;
	size_t i, j;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				new = array[j];
				array[j] = array[j + 1];
				array[j + 1] = new;
				print_array(array, size);
			}
		}
	}
}

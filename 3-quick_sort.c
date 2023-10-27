#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element to be swapped
 * @b: Pointer to the second element to be swapped
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if( *a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * partition_lumoto - Partitions the array into subarrays and places the pivot
 * element in its correct position using the Lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: The low index of the subarray.
 * @high: The high index of the subarray.
 * @size: The size of the full array for printing.
 * Return: The index of the pivot element after partition.
 */
int partition_lumoto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i, j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_sort_recursion - Recursive function for the quick sort algorithm
 * with the Lomuto partition scheme
 * @array: The array to be sorted
 * @low: The low index of the subarray to be sorted
 * @high: The high index of the subarray to be sorted
 * @size: The size of the full array for printing
 * Return: void
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_lumoto(array, low, high, size);
		quick_sort_recursion(array, low, pivot - 1, size);
		quick_sort_recursion(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * quick sort algorithm with the Lomuto partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}

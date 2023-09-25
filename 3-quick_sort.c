#include "sort.h"

/**
 * swap - Swap two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partition an array using the last element as pivot
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Partition index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int index = low;
	int i;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[index]);
			if (i != index)
				print_array(array, size);
			index++;
		}
	}

	swap(&array[index], &array[high]);
	if (index != high)
		print_array(array, size);

	return (index);
}

/**
 * quicksort_helper - Recursive helper function for Quicksort algorithm
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int index = partition(array, low, high, size);

		quicksort_helper(array, low, index - 1, size);
		quicksort_helper(array, index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_helper(array, 0, size - 1, size);
}

#include "sort.h"
/**
 * bubble_sort - sorts array using Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of an array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t swapped = 1, i;
	int temp;

	while (swapped)
	{
		swapped = 0;

		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				swapped = 1;
			}
		}
		print_array(array, size);
	}
}

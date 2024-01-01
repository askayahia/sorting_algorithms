#include "sort.h"

/**
 * swap_ints - It swaps two integers!
 * @a: first integer!
 * @b: Second integer!
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sort an array of integers in ascending order!
 * using selection sort algorithm.
 * @array: Array of integers to sort!
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;

		if (min_idx != i)
		{
			swap_ints(array + min_idx, array + i);
			print_array(array, size);
		}
	}
}

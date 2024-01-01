#include "sort.h"

/**
 * swap - Swaping two elements in an array
 * @a: Pointer to the first element.
 * @b: Pointer to th second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort!
 * @array: Array to be partitioned!
 * @low: starting index of the partition.
 * @high: Ending index of the partition!
 * @size: number of elements in the array !
 *
 * Return: Index of the pivot after partitioning.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort!
 * @array: The array to sort!
 * @low: Starting index of the array or partition!
 * @high: Ending index of the array or partition!
 * @size: number of elments in the array!
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending order using quick sort!
 * @array: Array to be sorted!
 * @size: number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

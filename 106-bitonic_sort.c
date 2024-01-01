#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * my_print_seq - Print array
 * @array: arrays
 * @my_low: Low bound
 * @my_hight: up bound
 */
void my_print_seq(int *array, int my_low, int my_hight)
{
	char *my_sep;

	for (my_sep = ""; my_low <= my_hight; my_low++)
	{
		printf("%s%d", my_sep, array[my_low]);
		my_sep = ", ";
	}
	printf("\n");
}


/**
 * my_swap_direct - swap element if are in the
 * specific bitonic my_direction
 * @array: Giv array
 * @my_a1: first elem
 * @my_a2: Second elem
 * @my_dir: my_direction 1 for up and 0 for down
 */
void my_swap_direct(int *array, int my_a1, int my_a2, int my_dir)
{
	int my_temp;

	if (my_dir == (array[my_a1] > array[my_a2]))
	{
		my_temp = array[my_a1];
		array[my_a1] = array[my_a2];
		array[my_a2] = my_temp;
	}
}


/**
 * my_merge_sequ - merging bitonica
 * @array: giv array!
 * @my_low: low bound
 * @my_hight: my_hight bound
 * @my_dir: my_direction 1 for up and 0 for down
 * @size: array size
 */
void my_merge_sequ(int *array, size_t my_low, size_t my_hight,
		int my_dir, size_t size)
{
	size_t my_midle, s, y;

	if (my_hight - my_low < 1)
		return;

	my_midle = (my_low + my_hight) / 2;
	for (s = my_low, y = my_midle + 1; s <= my_midle; s++, y++)
		my_swap_direct(array, s, y, my_dir);

	my_merge_sequ(array, my_low, my_midle, my_dir, size);
	my_merge_sequ(array, my_midle + 1, my_hight, my_dir, size);
}


/**
 * my_make_seq - To make bito seq
 * @array: array
 * @my_low: low bound
 * @my_hight: my_hight bound.
 * @my_dir: my_direction 1 for up  and 0 for down
 * @size: array size
 */
void my_make_seq(int *array, size_t my_low, size_t my_hight,
		int my_dir, size_t size)
{
	char *my_direction;
	size_t my_midle;

	if (my_hight - my_low < 1)
		return;

	my_direction = my_dir ? "UP" : "DOWN";
	printf("Merging [%ld/%ld] (%s):\n", my_hight - my_low + 1,
			size, my_direction);
	my_print_seq(array, my_low, my_hight);

	my_midle = (my_low + my_hight) / 2;
	my_make_seq(array, my_low, my_midle, 1, size);
	my_make_seq(array, my_midle + 1, my_hight, 0, size);

	my_merge_sequ(array, my_low, my_hight, my_dir, size);
	printf("Result [%ld/%ld] (%s):\n", my_hight - my_low + 1, size, my_direction);
	my_print_seq(array, my_low, my_hight);
}


/**
 * bitonic_sort -  sorting array integer
 * ascend order use the Bito sort algo
 * @array: given array
 * @size: array size.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	my_make_seq(array, 0, size - 1, 1, size);
}

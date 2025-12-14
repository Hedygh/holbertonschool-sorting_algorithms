#include "sort.h"

/**
 * shell_sort - sort an array using shell sort Knuth
 * @array: array
 * @size: size
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int tmp;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
				print_array(array, size);
				j -= gap;
			}
			i++;
		}
		gap = (gap - 1) / 3;
	}
}

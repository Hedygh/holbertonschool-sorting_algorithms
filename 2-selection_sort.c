#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int tmp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;

		while (j < size)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
			j++;
		}

		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}

		i++;
	}
}


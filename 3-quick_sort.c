#include "sort.h"

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array of integers
 * @low: index of the first element of the partition
 * @high: index of the last element of the partition (pivot)
 * @size: size of the whole array (for print_array)
 *
 * Return: index of the pivot after partition
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, tmp;
	int i, j;

	pivot = array[high];
	i = low - 1;
	j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}

	if (i + 1 != high)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - recursive quick sort using Lomuto partition
 * @array: array of integers
 * @low: index of the first element of the partition
 * @high: index of the last element of the partition
 * @size: size of the whole array (for print_array)
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, p - 1, size);
		quick_sort_rec(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto)
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}


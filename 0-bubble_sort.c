#include "sort.h"

/**
 * bubble_sort - sort an array using bubble sorting
 * @array: array
 * @size: array's size
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	int i = 0;
	int j = 0;
	int tmp;
	int *ar;

	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}

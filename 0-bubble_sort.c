#include "sort.h"

/**
 * bubble_sort - sorting an array integers by ascending order
 * @array: array to sorted
 * @size: size of array
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}

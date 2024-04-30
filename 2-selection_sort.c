#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: integers from array
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, s, min;

	while (i < size - 1)
	{
		min = i;
		for (s = i + 1; s < size; s++)
		{
			if (array[s] < array[min])
				min = s;
		}
		if (min != i)
		{
			int tmp = array[i];

			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}

#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 * @s1: pointer of first int
 * @s2: pointer of second int
*/
void swap(int *s1, int *s2)
{
	int temp = *s1;

	*s1 = *s2;
	*s2 = temp;
}

/**
 * partition - partition scheme
 * @array: array to be partitioned
 * @start: start of index array
 * @end: end of index array
 * @size: length of the array
 *
 * Return: Index of the pivot element
*/
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = (start - 1), j = start;

	while (j <= end - 1)
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
		j++;
	}
	if (array[i + 1] != array[end])
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort_recursive - recursive function to implement quicksort
 * @array: array to be partitioned
 * @start: start of index array
 * @end: end of index array
 * @size: length of the array
 */
void sort_recursive(int *array, int start, int end, size_t size)
{
	int pi;

	if (start < end)
	{
		pi = partition(array, start, end, size);
		sort_recursive(array, start, pi - 1, size);
		sort_recursive(array, pi + 1, end, size);
	}
}

/**
 * quick_sort - sorting an array of int in ascending order using quicksort
 * @array: array to be sorted
 * @size: length of the array
 */
void quick_sort(int *array, size_t size)
{
	sort_recursive(array, 0, size - 1, size);
}

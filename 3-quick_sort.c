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
 * partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @size: Size of the array
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
 * sort_recursive - Recursive function to implement quicksort
 * @array: Array to be sorted
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @size: Size of the array
 */
void sort_recursive(int *array, int start, int end, size_t size)
{
	if (start < end)
	{
		int pi = partition(array, start, end, size);

		sort_recursive(array, start, pi - 1, size);
		sort_recursive(array, pi + 1, end, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	sort_recursive(array, 0, size - 1, size);
}

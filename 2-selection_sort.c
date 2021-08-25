#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order,
 * using the Selection sort algorithm.
 * @array: Array to be sorted.
 * @size: Length of the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, ti;
	int tmp;

	for (i = 0; i < size; i++)
	{
		/* save the value of array[i] */
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			/* each time a lower value is found, save that value and index */
			if (array[j] < tmp)
			{
				tmp = array[j];
				ti = j;
			}
		}
		/* if a lower value was found, swap the values */
		if (tmp != array[i])
		{
			tmp = array[i];
			array[i] = array[ti];
			array[ti] = tmp;
			print_array(array, size);
		}
	}
}

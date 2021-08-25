#include "sort.h"

/**
 * Lomuto - Partitions an array of integers so that the given high index's
 * value is placed in its ordered position, with all lower numbers before it.
 * @array: Array to be partitioned.
 * @low: Starting point of the partition.
 * @high: Last index of array or array partition to be partitioned. (index of
 * the end value, but not necessarily end index of the resulting partition)
 * @size: Length of the array.
 * Return: The index of the resulting partition.
 */
unsigned int Lomuto(int *array, int low, int high, size_t size)
{
	int pivot, tmp;
	/* These store the Array index and Lomuto partition index. */
	int Ai, Li;

	pivot = array[high];
	Li = low - 1;
	for (Ai = low; Ai < high; Ai++)
	{
		/* Any numbers lower than the pivot value are placed at the front */
		if (array[Ai] < pivot && Ai != ++Li)
		{
			tmp = array[Ai];
			array[Ai] = array[Li];
			array[Li] = tmp;
			print_array(array, size);
		}
	}
	/* The pivot value is placed directly after all lower values */
	if (high != ++Li && pivot != array[Li])
	{
		array[high] = array[Li];
		array[Li] = pivot;
		print_array(array, size);
	}
	return (Li);
}

/**
 * recursive_quick_sort - Sorts an array of integers in ascending order
 * recursively, using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @low: Starting point of the array partition to be sorted.
 * @high: End point of the array partition to be sorted.
 * @size: Length of the array overall.
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int Li;

	if (low < high)
	{
		/* Partition the array and save the index of the sorted value */
		Li = Lomuto(array, low, high, size);
		/* Do it again on the partitions below and above that index */
		recursive_quick_sort(array, low, Li - 1, size);
		recursive_quick_sort(array, Li + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order,
 * using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Length of the array.
 */
void quick_sort(int *array, size_t size)
{
	recursive_quick_sort(array, 0, size - 1, size);
}

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
unsigned int Lomuto(int *array, size_t low, size_t high, size_t size)
{
	int pivot, tmp;
	/* These store the Array index and Lomuto partition index. */
	unsigned int Ai, Li;

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
	if (high != ++Li)
	{
		array[high] = array[Li];
		array[Li] = pivot;
		print_array(array, size);
	}
	return (Li);
}
/**
 * quick_sort - Sorts an array of integers in ascending order,
 * using the Quick sort algorithm.
 * @array: Array to be sorted.
 * @size: Length of the array.
 */
void quick_sort(int *array, size_t size)
{
	unsigned int low, high, nextLow;

	for (low = 0, high = size - 1; low < high; low = nextLow, high = size - 1)
	{
		nextLow = Lomuto(array, low, high, size) + 1;
		while (low < high)
		{
			high = Lomuto(array, low, high, size) - 1;
		}
	}
}

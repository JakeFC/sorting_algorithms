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
	array[high] = array[++Li];
	array[Li] = pivot;
	if (high != Li)
		print_array(array, size);
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
	int tmpHigh;

	if (!array)
		return;
	/* Reset low to first high found - 1 and high to length of array */
	for (low = 0, high = size - 1; low < size; low = nextLow, high = size - 1)
	{
		/* Store next high in an int, in case it is negative */
		tmpHigh = Lomuto(array, low, high, size) - 1;
		/* Next low will be the previous high + 1, or next high + 2 */
		nextLow = tmpHigh + 2;
		/* Continue to next iteration if tmpHigh is negative */
		if (tmpHigh < 0)
			continue;
		/* Cast next high to an unsigned int for comparison with low and */
		/* use with Lomuto */
		high = tmpHigh;
		/* While there is still a partition to parse, continue sorting */
		while (low < high)
		{
			Lomuto(array, low, high, size);
			high--;
		}
	}
}

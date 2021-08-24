#include "sort.h"

/**
 * bubble_sort - Sorts an array by iterating through and swapping neighboring
 * integers, printing each time it swaps.
 * @array: integer array input to be sorted
 * @size: length of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	int tmp;
	char flag = 1;

	/* As long as a change was made, iterate again. */
	while (flag)
	{
		/* Set flag to 0 to denote no change has been made yet this iteration. */
		flag = 0;
		for (i = 0; i < size; i++)
		{
			if (i < size - 1 && array[i] > array[i + 1])
			{
				/* Swap the misordered integers. */
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				/* Change flag to 1 to denote a change has been made. */
				flag = 1;
			}
		}
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner
 * @array: The array to be merged
 * @low: Starting index of the subarray
 * @size: Size of the subarray to be merged
 * @up: A flag indicating whether the merge is in an upward direction
 */
void bitonic_merge(int *array, size_t low, size_t size, int up)
{
    if (size > 1)
    {
        size_t k = size / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == up)
            {
                
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }

        printf("Merging [%lu/%lu] (%s):\n", size, size, up ? "UP" : "DOWN");
        print_array(array + low, size);

        bitonic_merge(array, low, k, up);
        bitonic_merge(array, low + k, k, up);
    }
}

/**
 * bitonic_sort_recursive - Recursively performs the Bitonic sort
 * @array: The array to be sorted
 * @low: Starting index of the subarray
 * @size: Size of the subarray to be sorted
 * @up: A flag indicating whether the sort should be in an upward direction
 */
void bitonic_sort_recursive(int *array, size_t low, size_t size, int up)
{
    if (size > 1)
    {
        size_t k = size / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);

        bitonic_merge(array, low, size, up);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array (always a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
}

#pragma once
#include "../Extensions/Checkers.h"

/// <summary>
/// Information about and sorting itself.
/// </summary>
class Sorting
{
private:
	template<class type>
	static void QuickSort(type* list, int start, int end)
	{
		int i=start, j=end;
		type temp;
		bool swapped = false;
		for (; i<end; i++)
		{
			// check if the current element is greater than the pivot
			if (list[i] > list[end-1])
			{
				swapped = false;
				// if yes: find first (from the end of the list) element which is smaller than the pivot
				for (j=end-2; j>i; j--)
					if (list[j] < list[end-1])
					{
						// if found: swap
						temp = list[i];
						list[i] = list[j];
						list[j] = temp;
						swapped = true;
						break;
					}
				if (!swapped)
					break;
			}
		}
		// moving the pivot
		int pivot = (end+start)/2;
		for (i=start; i<end; i++)
			if (list[i] > list[end-1])
			{
				temp = list[i];
				list[i] = list[end-1];
				list[end-1] = temp;
				pivot = i;
				break;
			}
		// recursively calling the algorithm
		if (pivot-start > 1)
			QuickSort(list, start, pivot);
		if (end-pivot > 1)
			QuickSort(list, pivot+1, end);
	}

public:
	/// <summary>
	/// Definition about the sorting: what is it, what are the types, etc.
	/// </summary>
	/// <returns>A text with the information (in form of an array of <see cref="char"/>s).</returns>
	static char* Definition(void)
	{
		return (char*)"Sorting means \"to put elements of a list into an (most frequent numerical or \
lexicographical) order\".\nTwo conditions must be satisfied:\n1. the output is in monotonic \
order,\n2. the output is a permutation of the input.\nAdaptability: sorting is adaptive \
if it takes advantage of existing order in the input (presort).\nStability: stable sort \
leaves the equal elements in the same order that they appear in the input.";
	}

	/// <summary>
	/// Implementation of the "quicksort".
	/// </summary>
	/// <typeparam name="type">Type of the elements in the list to be sorted.</typeparam>
	/// <param name="list">List of elements to be sorted.</param>
	/// <param name="size">Size of the list.</param>
	/// <returns>Pointer to the sorted list (or <see cref="nullptr"/> if an '&lt;=' operator does not exist
	/// in the used type).</returns>
	template<class type>
	static type* QuickSort(type* list, int size)
	{
		/*
		* partitioning method
		* the algorithm works by selecting the "pivot" element from the list/array and partitioning the
		* other elements into two sub-lists, according to whether they are less than or greater than the
		* pivot; the sub-lists are then sorted recursively
		*/
		// checking if the needed operator exists in the class
		if (!Operators::GreaterYes<type>::value)
			// if not: exiting from the function
			return nullptr;
		type* ret = new type[size];
		for (int i=0; i<size; i++)
			ret[i] = list[i];
		QuickSort<type>(ret, 0, size);
		return ret;

	} // end of: static type* QuickSort(type* list, int size)

	/// <summary>
	/// Implementation of the "quicksort".
	/// </summary>
	/// <typeparam name="type">Type of the elements in the list to be sorted.</typeparam>
	/// <param name="list">List of elements to be sorted.</param>
	/// <param name="ret">Pointer to the sorted list (or <see cref="nullptr"/> if an '&lt;=' operator does not exist
	/// in the used type).</param>
	/// <param name="size">Size of the list.</param>
	template<class type>
	static void QuickSort(type* list, type* ret, int size)
	{
		/*
		* partitioning method
		* the algorithm works by selecting the "pivot" element from the list/array and partitioning the
		* other elements into two sub-lists, according to whether they are less than or greater than the
		* pivot; the sub-lists are then sorted recursively
		*/
		// checking if the needed operator exists in the class
		if (!Operators::GreaterYes<type>::value)
			// if not: exiting from the function
			return;
		for (int i=0; i<size; i++)
			ret[i] = list[i];
		QuickSort<type>(ret, 0, size);

	} // end of: static void QuickSort(type* list, type* ret, int size)


}; // end of: class Sorting
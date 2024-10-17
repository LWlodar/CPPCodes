#pragma once

/// <summary>
/// Exchanging sort algorithms.
/// </summary>
namespace Exchanging
{
	/// <summary>
	/// "Bubble sort" is an exchanging type algorithm that compares two adjacent elements and swaps them
	/// if needed, it does it for every element of the list, recursively until there is no need to swap.
	/// </summary>
	class BubbleSort
	{
		template<class T>
		static void Sort(T* list, int count)
		{
			// variable used for swapping
			int* temp = nullptr;

			for (int i=0; i<count-1; i++)
				// check if a swap is needed
				if (list[i] > list[i+1])
				{
					// if yes: swap
					if (temp == nullptr)
						temp = new int;
					*temp = list[i];
					list[i] = list[i+1];
					list[i+1] = *temp;
				}

			// check if there was a swap
			if (temp != nullptr)
				// if yes: there should be a new pass to check if all elements are sorted
				Sort(list, count);
			delete temp;

		} // end of: static void Sort(T* list, int count)

	public:

		template<class T>
		static void Sort(T* list, T* ret, int count)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return;

			// copy the list
			for (int i=0; i<count; i++)
				ret[i] = list[i];

			// sort the list
			Sort(ret, count);

		} // end of: static void Sort(T* list, T* ret, int count)

	}; // end of: static class BubbleSort


} // end of: namespace Exchanging
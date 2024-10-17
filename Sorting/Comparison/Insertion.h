#pragma once

/// <summary>
/// Insertion sort algorithms.
/// </summary>
namespace Insertion
{
	/// <summary>
	/// Insertion sort is a comparison algorithm which operates on one element of the list at the time. It
	/// iterates, consuming one input element each repetition and grows a sorted output list. At each
	/// iteration, insertion sort removes one element from the input data, finds the location it belongs
	/// within the sorted list, and inserts it there. It repeats until no input elements remain.
	/// </summary>
	class InsertionSort
	{
	public:

		template<class T>
		static T* Sort(T* list, int count)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return nullptr;
			T* ret = new T[count];
			int i, key, j;

			// copy the input list
			for (i=0; i<count; i++)
				ret[i] = list[i];

			for (i=1; i<count; i++)
			{
				key = ret[i];
				j = i-1;
				// move elements that are greater than key, to one position ahead of their current
				while (j >= 0 && ret[j] > key)
				{
					ret[j+1] = ret[j];
					j = j-1;
				}
				ret[j+1] = key;
			}
			return ret;

		} // end of: T* Sort(T* list, int count)


		template<class T>
		static void Sort(T* list, T* ret, int count)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return;

			int i, key, j;

			// copy the input list
			for (i=0; i<count; i++)
				ret[i] = list[i];

			for (i=1; i<count; i++)
			{
				key = ret[i];
				j = i-1;
				// move elements that are greater than key, to one position ahead of their current
				while (j >= 0 && ret[j] > key)
				{
					ret[j+1] = ret[j];
					j = j-1;
				}
				ret[j+1] = key;
			}

		} // end of: T* Sort(T* list, T* ret, int count)

	}; // end of: class InsertionSort

}; // end of: namespace Insertion
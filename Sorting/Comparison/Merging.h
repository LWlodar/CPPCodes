#pragma once

/// <summary>
/// Merging sort algorithms.
/// </summary>
namespace Merging
{
	/// <summary>
	/// Merge sort is a divide-and-conquer algorithm.<para/>
	/// 1. Devide the unsorted list into n sublists, each containing one element (a list of one element
	/// is considered sorted).<para/>
	/// 2. Repeatedly merge sublists to produce new stored sublists until there is only one sublist remaining.
	/// <para/>This is the sorted list. There are two implementations of the algorithm: "bottom-up" and
	/// "top-down" merge sort.
	/// </summary>
	class MergeSort
	{
	private:
		template<class T>
		static void MergeTwo(T* list, const int start, const int count, const int size)
		{
			// temp array
			T* temp = new T[count*2];
			// left/right indices
			int left = start, right = start+count;
			// merging two sorted "subarrays" (operating on the input array by indices)
			for (int i=0; i<count*2; i++)
				if (right < size && right < start+count*2 &&
					(list[left] > list[right] || left >= start+count))
					temp[i] = list[right++];
				else
					temp[i] = list[left++];
			// copying sorted values to the input array
			for (int i=0; i<count*2 && start+i<size; i++)
				list[start+i] = temp[i];
			// clearing the memory
			delete[] temp;
		}

		template<class T>
		static void BottomUpMerge(T* list, const int count, const int size)
		{
			// merging two subarrays
			for (int i=0; i<size; i+=count*2)
				MergeTwo(list, i, count, size);
			// recursively calling the method until the whole array is sorted
			if (count < size/2)
				BottomUpMerge(list, count*2, size);
		}

		template<class T>
		static void TopDownMerge(T* list, const int start, const int end)
		{
			if (end-start > 1)
			{
				TopDownMerge(list, start, (start+end)/2);
				TopDownMerge(list, (start+end)/2, end);
			}

			// temp array
			T* temp = new T[end-start];
			// left/right indices
			int left = start, right = (start+end)/2;
			// merging two sorted "subarrays" (operating on the input array by indices)
			for (int i=0; i<end-start; i++)
				if (right < end && (list[left] > list[right] || left >= (start+end)/2))
					temp[i] = list[right++];
				else
					temp[i] = list[left++];
			// copying sorted values to the input array
			for (int i=0; i<end-start; i++)
				list[start+i] = temp[i];
			// clearing the memory
			delete[] temp;

		} // end of: static void TopDownMerge(T* list, int start, int end)

	public:
		/// <summary>
		/// Type of merge sort.
		/// </summary>
		enum EMergeSortType
		{
			/// <summary>
			/// Devides the list into the smallest possible ones (of one element) and merges them with
			/// sorting recursively until the list of the input size is achieved.
			/// </summary>
			BottomUp,
			/// <summary>
			/// Splits the list recursively into two lists of the same size to the point of one element
			/// lists and merges them back with sorting.
			/// </summary>
			TopDown
		};

		/// <summary>
		/// Merge sort a list.
		/// </summary>
		/// <typeparam name="T">Type of the objects put into the list.</typeparam>
		/// <param name="list">Pointer to the list to be sorted.</param>
		/// <param name="count">Number of the elements in the list.</param>
		/// <param name="mergetype">Type of merge sorting algorithm (a <see cref="EMergeSortType"/> object).
		/// Available types are top-down and bottom-up (more info in <see cref="EMergeSortType"/>
		/// elements descriptions).</param>
		/// <returns>Pointer to the sorted list (or <see cref="nullptr"/> if an '&lt;=' operator does not
		/// exist in the used type).</returns>
		template<class T>
		static T* Sort(const T* list, const int count, EMergeSortType mergetype = BottomUp)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return nullptr;

			// return list
			T* ret = new T[count];

			// start the merging
			switch (mergetype)
			{
			case EMergeSortType::BottomUp:
				// copy the input array
				for (int i=0; i<count; i++)
					ret[i] = list[i];
				// do the merge sort
				BottomUpMerge(ret, 1, count);
				break;
			case EMergeSortType::TopDown:
				// copy the input array
				for (int i=0; i<count; i++)
					ret[i] = list[i];
				// do the merge sort
				TopDownMerge(ret, 0, count);
				break;
			}

			return ret;

		} // end of: static T* Sort(T* list, int count, EMergeSortType mergetype = BottomUp)

		/// <summary>
		/// Merge sort a list.
		/// </summary>
		/// <typeparam name="T">Type of the objects put into the list.</typeparam>
		/// <param name="list">Pointer to the list to be sorted.</param>
		/// <param name="ret">Pointer to the sorted list (or <see cref="nullptr"/> if an '&lt;=' operator does not
		/// exist in the used type).</param>
		/// <param name="count">Number of the elements in the list.</param>
		/// <param name="mergetype">Type of merge sorting algorithm (a <see cref="EMergeSortType"/> object).
		/// Available types are top-down and bottom-up (more info in <see cref="EMergeSortType"/>
		/// elements descriptions).</param>
		template<class T>
		static void Sort(const T* list, T* ret, const int count, EMergeSortType mergetype = BottomUp)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return;

			// start the merging
			switch (mergetype)
			{
			case EMergeSortType::BottomUp:
				// copy the input array
				for (int i=0; i<count; i++)
					ret[i] = list[i];
				// do the merge sort
				BottomUpMerge(ret, 1, count);
				break;
			case EMergeSortType::TopDown:
				// copy the input array
				for (int i=0; i<count; i++)
					ret[i] = list[i];
				// do the merge sort
				TopDownMerge(ret, 0, count);
				break;
			}

		} // end of: static T* Sort(T* list, T* ret, int count, EMergeSortType mergetype = BottomUp)

	}; // end of: class MergeSort


}; // end of: namespace Merging
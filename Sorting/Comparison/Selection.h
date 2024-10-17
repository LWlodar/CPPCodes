#pragma once


namespace Selection
{
	/// <summary>
	/// "Selection sort" is an in-place comparison sorting algorithm which divides the input into two
	/// parts: sorted and unsorted sublists. The split point is the item which is now going to be compared
	/// with all others from the unsorted sublist. If a smaller (or greater - depending on sorting
	/// </summary>
	class SelectionSort
	{
	public:
		template<class T>
		static void Sort(const T* list, T* ret, int count)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return;

			// copy the list
			for (int i=0; i<count; i++)
				ret[i] = list[i];

			// currently found min value (index)
			int min;

			// going through the list
			for (int i=0; i<count; i++)
			{
				min = i;
				// looking for a new min
				for (int j=i+1; j<count; j++)
					if (ret[min] > ret[j])
						min = j;

				// checking if a min was found
				if (min != i)
				{
					// if yes: swapping
					T temp = ret[min];
					ret[min] = ret[i];
					ret[i] = temp;
				}
			}

		} // end of: static void Sort(const T* list, T* ret, int count)

	}; // end of: class SelectionSort


	/// <summary>
	/// "Heap sort" is a comparison sorting algorithm which uses heap as the main tool. The first step is to
	/// create the heap which is then sorted by swapping the elements.<para/>Heap is a binary tree in which a parent
	/// is greater(max heap)/lower(min heap) of its both children.
	/// </summary>
	class HeapSort
	{
	private:
		template<class T>
		static void heapify(T* list, int count, int current)
		{
			// indices of the current tree node
			int left = 2*current+1, right = 2*current+2, largest = current;

			// find the largest element of the node
			if (left < count && list[left] > list[largest])
				largest = left;
			if (right < count && list[right] > list[largest])
				largest = right;

			// swap and continue heapifying if root is not largest
			if (largest != current)
			{
				T temp;
				temp = list[current];
				list[current] = list[largest];
				list[largest] = temp;
				heapify(list, count, largest);
			}

		} // end of: static void heapify(T* list, int count, int current)

	public:
		template<class T>
		static void Sort(const T* list, T* ret, int count)
		{
			// checking if the needed operator exists in the class
			if (!Operators::GreaterYes<T>::value)
				// if not: exiting from the function
				return;

			for (int i=0; i<count; i++)
				ret[i] = list[i];

			// make a heap of the array
			for (int i=count/2-1; i>=0; i--)
				heapify(ret, count, i);

			// sort
			T temp;
			for (int i=count-1; i>=0; i--)
			{
				temp = ret[0];
				ret[0] = ret[i];
				ret[i] = temp;

				heapify(ret, i, 0);
			}

		} // end of: static void Sort(const T* list, T* ret, int count)

	}; // end of: class HeapSort

}; // end of: namespace SelectionSorts
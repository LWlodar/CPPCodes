#include <iostream>
#include <thread>
#include <vector>
#include "Sorting/Sorting.h"
#include "Sorting/Comparison/Merging.h"
#include "Sorting/Comparison/Insertion.h"
#include "Sorting/Comparison/Selection.h"
#include "Sorting/Comparison/Exchanging.h"


/// <summary>
/// Invoke all types of sorting - check which is the fastest on the same random numbers (list of size 110).<para>Each
/// sorting is done on its own thread.</para>
/// </summary>
/// <returns>0 on success, -1 on any exception.</returns>
int SortingTestOnRandoms(void)
{
    int ret = 0;

    // show the info about the sorting
    std::cout << Sorting::Definition() << '\n';
    // define arrays
    int* list = new int[110];
    int* quick = new int[110];
    int* merge = new int[110];
    int* topmerge = new int[110];
    int* insert = new int[110];
    int* selection = new int[110];
    int* bubble = new int[110];
    int* heap = new int[110];
    try
    {
        // create a list of random values
        srand((unsigned)time(NULL));
        for (int i=0; i<110; i++)
            list[i] = rand();
        // declare sorting time values
        double timeQ, timeM, timeTM, timeI, timeS, timeB, timeH;
        // do sorting
        auto quickT = std::thread([&]() {
            Sorting::QuickSort<int>(list, quick, 110);
            });
        auto mergeT = std::thread([&]() {
            Merging::MergeSort::Sort<int>(list, merge, 110);
            });
        auto topmergeT = std::thread([&]() {
            Merging::MergeSort::Sort<int>(list, topmerge, 110, Merging::MergeSort::TopDown);
            });
        auto insertT = std::thread([&]() {
            Insertion::InsertionSort::Sort<int>(list, insert, 110);
            });
        auto selectionT = std::thread([&]() {
            Selection::SelectionSort::Sort<int>(list, selection, 110);
            });
        auto bubbleT = std::thread([&]() {
            Exchanging::BubbleSort::Sort<int>(list, bubble, 110);
            });
        auto heapT = std::thread([&]() {
            Selection::HeapSort::Sort<int>(list, heap, 110);
            });
        // wait for all threads
        quickT.join();
        mergeT.join();
        topmergeT.join();
        insertT.join();
        selectionT.join();
        bubbleT.join();
        heapT.join();
        // print all the info
        std::cout << "input:\n";
        for (int i=0; i<110; i++)
            std::cout << list[i] << ' ';
        std::cout << "\n\nquick sort:\n";
        for (int i=0; i<110; i++)
            std::cout << quick[i] << ' ';
        std::cout << "\n\nbottom-up merge sort:\n";
        for (int i=0; i<110; i++)
            std::cout << merge[i] << ' ';
        std::cout << "\n\ntop-down merge sort:\n";
        for (int i=0; i<110; i++)
            std::cout << topmerge[i] << ' ';
        std::cout << "\n\ninsert sort:\n";
        for (int i=0; i<110; i++)
            std::cout << insert[i] << ' ';
        std::cout << "\n\nselection sort:\n";
        for (int i=0; i<110; i++)
            std::cout << selection[i] << ' ';
        std::cout << "\n\nbubble sort:\n";
        for (int i=0; i<110; i++)
            std::cout << bubble[i] << ' ';
        std::cout << "\n\nheap sort:\n";
        for (int i=0; i<110; i++)
            std::cout << heap[i] << ' ';
    }
    catch (std::exception e)
    {
        // an exception was caught: print the info and set the return value
        std::cout << e.what() << '\n';
        ret = -1;
    }
    // free the memory
    delete[] bubble;
    delete[] selection;
    delete[] insert;
    delete[] merge;
    delete[] topmerge;
    delete[] quick;
    delete[] heap;
    delete[] list;

    return ret;

} // end of: int SortingTestOnRandoms(void)


int main()
{
    // return value
    int ret = 0;

    // perform the sorting
    SortingTestOnRandoms();

    return ret;

} // end of: int main()
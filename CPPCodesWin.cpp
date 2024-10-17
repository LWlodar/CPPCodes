#include <iostream>
#include <thread>
#include <vector>
#include "Sorting/Sorting.h"
#include "Sorting/Comparison/Merging.h"
#include "Sorting/Comparison/Insertion.h"
#include "Sorting/Comparison/Selection.h"
#include "Sorting/Comparison/Exchanging.h"
#include <Windows.h>


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
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Sorting::QuickSort<int>(list, quick, 110);
            QueryPerformanceCounter(&end);
            timeQ = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        auto mergeT = std::thread([&]() {
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Merging::MergeSort::Sort<int>(list, merge, 110);
            QueryPerformanceCounter(&end);
            timeM = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        auto topmergeT = std::thread([&]() {
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Merging::MergeSort::Sort<int>(list, topmerge, 110, Merging::MergeSort::TopDown);
            QueryPerformanceCounter(&end);
            timeTM = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        auto insertT = std::thread([&]() {
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Insertion::InsertionSort::Sort<int>(list, insert, 110);
            QueryPerformanceCounter(&end);
            timeI = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        auto selectionT = std::thread([&]() {
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Selection::SelectionSort::Sort<int>(list, selection, 110);
            QueryPerformanceCounter(&end);
            timeS = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        auto bubbleT = std::thread([&]() {
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Exchanging::BubbleSort::Sort<int>(list, bubble, 110);
            QueryPerformanceCounter(&end);
            timeB = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        auto heapT = std::thread([&]() {
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
            Selection::HeapSort::Sort<int>(list, heap, 110);
            QueryPerformanceCounter(&end);
            timeH = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
            });
        // wait for all threads
        quickT.join();
        mergeT.join();
        topmergeT.join();
        insertT.join();
        selectionT.join();
        bubbleT.join();
        heapT.join();
        // check the fastest
        double fastest = timeQ;
        std::string nameFastest = "quick";
        if (timeM < fastest)
        {
            fastest = timeM;
            nameFastest = "bottom-up merge";
        }
        if (timeTM < fastest)
        {
            fastest = timeTM;
            nameFastest = "top-down merge";
        }
        if (timeI < fastest)
        {
            fastest = timeI;
            nameFastest = "insertsort";
        }
        if (timeS < fastest)
        {
            fastest = timeS;
            nameFastest = "selection";
        }
        if (timeB < fastest)
        {
            fastest = timeB;
            nameFastest = "bubble";
        }
        if (timeH < fastest)
        {
            fastest = timeH;
            nameFastest = "heap";
        }
        // print all the info
        std::cout << "input:\n";
        for (int i=0; i<110; i++)
            std::cout << list[i] << ' ';
        std::cout << "\n\nquick sort (time = " << timeQ << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << quick[i] << ' ';
        std::cout << "\n\nbottom-up merge sort (time = " << timeM << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << merge[i] << ' ';
        std::cout << "\n\ntop-down merge sort (time = " << timeTM << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << topmerge[i] << ' ';
        std::cout << "\n\ninsert sort (time = " << timeI << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << insert[i] << ' ';
        std::cout << "\n\nselection sort (time = " << timeS << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << selection[i] << ' ';
        std::cout << "\n\nbubble sort (time = " << timeB << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << bubble[i] << ' ';
        std::cout << "\n\nheap sort (time = " << timeH << "sec.):\n";
        for (int i=0; i<110; i++)
            std::cout << heap[i] << ' ';
        std::cout << "\n\nfastest algorithm: " << nameFastest << " sort (time: " << fastest << ")";
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
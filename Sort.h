#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

    static void sortSegment(T* start, T* end, int segment_idx) ;

public:
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) ;
    static void SelectionSort(T* start, T* end);
    static void QuickSort(T* start, T* end);
    static void MergeSort(T* start, T* end);
};
template<class T>
void Sorting<T>::sortSegment(T* start, T* end, int segment_idx)
{
        int n = end - start;
        int temp = 0;
        int j = 0;
        for (int i = segment_idx; i < n; i++)
        {
            temp = start[i];    
            for (j = i; j >= segment_idx && start[j - segment_idx] > temp; j -= segment_idx)
            {
                start[j] = start[j - segment_idx];
            }
            start[j] = temp;
        }
}
template<class T>
void Sorting<T>::ShellSort(T* start, T* end, int* num_segment_list, int num_phases)
{
    for(int i = 0; i < num_phases; i++)
    {
        cout<<*(num_segment_list+i)<<" segments: ";
        sortSegment(start, end, *(num_segment_list + num_phases - i - 1));
        printArray(start, end);
    }
}
template<class T>
void Sorting<T>::SelectionSort(T* start, T* end)
{
    int n = end - start;
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if(start[min] > start[j])
                min = j;
        }
        if(min != i)
        {
            int temp = start[min];
            start[min] = start[i];
            start[i] = temp;
        }
    }
    printArray(start, end);
}

template<class T>
void Sorting<T>::QuickSort(T* start, T* end)
{
    //First element as Pivot
    int n = end - start;
    if (n <= 1) return;
    int i = 0, j = 1;
    for (j; j < n; j++)
    {
        if (start[j] < start[0])
        {
            i++;
            int temp = start[j];
            start[j] = start[i];
            start[i] = temp;
        }
    }
    int temp = *start;
    *start = start[i];
    start[i] = temp;
    QuickSort(start, &start[i]);
    QuickSort(&start[i]+1, end);
    printArray(start, end);
}
template<class T>
void Sorting<T>::MergeSort(T* start, T* end)
{
    int n = end - start;
    if (n <= 1) return;
    MergeSort(start, start + n / 2);
    MergeSort(start + n / 2, end);
    T* array1 = new T[n / 2];
    T* array2 = new T[n - n / 2];
    for (int i = 0; i < n / 2; i++)
        array1[i] = start[i];
    for (int i = 0; i < n - n / 2; i++)
        array2[i] = start[i + n / 2];
    int i = 0, j = 0;
    for (int z = 0; z < n; z++)
    {
        if (j < (n - n/2) && (array1[i] > array2[j] || i >= n / 2))
        {
            start[z] = array2[j];
            j++;
        }
        else if (i < n/2 && (array1[i] <= array2[j] || j >= (n - n / 2)))
        {
            start[z] = array1[i];
            i++;
        }
    }
    delete array1;
    delete array2;
    printArray(start, end);
}
#endif /* SORTING_H */
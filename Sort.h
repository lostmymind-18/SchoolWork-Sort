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
#endif /* SORTING_H */
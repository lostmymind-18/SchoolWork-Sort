#include "Sort.h"
#include<iostream>
using namespace std;
int main()
{
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };
    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    system("pause");
    return 0;
}
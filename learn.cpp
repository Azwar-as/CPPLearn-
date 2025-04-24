#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int binarySearch(int arr[], int size, int key)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int center = (left + right) / 2;

        if (arr[center] == key)
        {
            return center;
        }
        else if (key < arr[center])
        {
            right = center - 1;
        }
        else if (key > arr[center])
        {
            left = center + 1;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    cout << "I am Still Learn!" << endl;
}
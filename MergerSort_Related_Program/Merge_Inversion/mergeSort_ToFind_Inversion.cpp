//Find the inversion using merge sort, by reading the file
//Read the mergesort_test.txt
//http://www.geeksforgeeks.org/counting-inversions/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long merge(vector<int>&arr, vector<int>&temp, int left, int mid, int right)
{
    long i, j, k;
    long inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* i is index for right subarray*/
    k = left; /* i is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            /*this is tricky -- see above explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }

    /* Copy the remaining elements of left subarray
     *    (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];

    /* Copy the remaining elements of right subarray
     *    (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];

    /*Copy back the merged elements to original array*/
    for (i=left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;

}

long _mergeSort(vector<int>&arr, vector<int>&temp, int left, int right)
{
    long mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left)/2;
        /* Inversion count will be sum of inversions in left-part, right-part
         * and number of inversions in merging */
        inv_count  = _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid+1, right);
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid+1, right);

    }

    return inv_count;
}

long mergeSortInversion(vector<int>& arr)
{
    vector<int> temp(arr.size());
    return _mergeSort(arr, temp, 0, arr.size()-1);
}

int main()
{
    long inversion;
    ifstream mergeSortFile;
    int data;
    vector<int> vector_data;

    mergeSortFile.open("mergesort_test.txt", ios::in);

    while(mergeSortFile >> data) {
        vector_data.push_back(data);
    }

    inversion = mergeSortInversion(vector_data);
    mergeSortFile.close();
    cout << "Inversion: " << inversion << endl;

}

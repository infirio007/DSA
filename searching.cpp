#include <iostream>
#include <math.h>
using namespace std;

/*
Linear Search finds the element in O(n) time
Jump Search takes O(√n) time. better than linear search but not better than binary search.
Binary Search take O(Log n) time.
interpolation Search time depends on the uniformity of data. it is used when the array is sorted and has uniform difference. 
    it is also considered to be better than binary search in those conditions.
Exponential Search take O(Log n) time. but is better than binary search for large data set
*/

/*interpolation search formula - l + (x-a[l] / a[h] - a[l]) * (h - l)
here l = least index(0), x = no. to search, a = array, h = highest index
*/

int linear_search(int arr[], int n, int key) {
    for(int i = 0; i<n; n++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int key, int start=0) {
    int s = start;
    int e = n;

    while(s<=e) {
        int mid = (s+e)/2;
        if(arr[mid] > key) {
            e = mid - 1;
        }
        else if(arr[mid] < key) {
            s = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

int jump_search(int arr[], int n, int key) {
    int step = sqrt(n);
    int prev = 0;
    while(arr[min(step, n)-1] < key) {
        prev = step;
        step += sqrt(n);
        if(prev >= n) {
            return -1;
        }
    }
    while(prev <= step) {
        if(arr[prev] == key) {
            return prev;
        }
        prev++;
    }
    return -1;
}

int exponential_search(int arr[], int n, int key) {
    int i = 1;
    while(arr[i] <= key && i<n) {
        i *= 2;
    }

    return binary_search(arr, min(i, n-1), key, i/2);
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    cout<<exponential_search(arr, 6, 6);
    return 0;
}
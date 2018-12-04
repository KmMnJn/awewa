#include <stdio.h>
#include <iostream> 
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>

using namespace std; 

const int arr_size = 1000; 
int hcomp, hswap;
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]){
      largest = l;
    }
    hcomp++;
         
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]){
        largest = r; 
    }
    hcomp++;
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        hswap++;
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
        hswap++;
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

int main() 
{ 
    int i;
    int hdata[arr_size];
    int data[arr_size];
    srand(time(NULL));
    for(i=0;i<arr_size;i++){
      data[i] = hdata[i] = rand();
    }

    heapSort(hdata, arr_size); 
    sort(data, data+arr_size);
    for(i=0;i<arr_size;i++){
      if(data[i] != hdata[i]){
        printf("sorting error\n");
      }
    }
    printf("hswap : %d, hcomp : %d\n", hswap, hcomp);
} 
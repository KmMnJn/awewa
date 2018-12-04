#include <stdio.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <functional>
#include <algorithm>

using namespace std;

const int arr_size = 5000;

int qswap, qcomp;
int hswap, hcomp;

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
//#######################
void Swap(int arr[], int a, int b) // a,b 스왑 함수 
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int Partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽에서 시작
    int low = left + 1;
    int high = right;
 
    while (low <= high) // 교차되기 전까지 반복한다 
    {
        qcomp++;
        while (pivot >= arr[low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
        {
            qcomp++;
            low++; // low를 오른쪽으로 이동 
        }
        qcomp++;
        while (pivot <= arr[high] && high >= (left+1) ) // 피벗보다 작은 값을 찾는 과정 
        {
            qcomp++;
            high--; // high를 왼쪽으로 이동
        }
        if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
        {
            qswap++;
            Swap(arr, low, high); //low와 high를 스왑 
        }
    }
    qswap++;
    Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환 
    return high;  // 옮겨진 피벗의 위치정보를 반환 
 
}
 
 
void QuickSort(int arr[], int left, int right){
    if (left <= right){
        int pivot = Partition(arr, left, right); // 둘로 나누어서
        QuickSort(arr, left, pivot - 1); // 왼쪽 영역을 정렬한다.
        QuickSort(arr, pivot + 1, right); // 오른쪽 영역을 정렬한다.
    }
    qcomp++;
}
 
int main(void){
    int i;
    int data[arr_size];
    int qdata[arr_size];
    int hdata[arr_size];
    //############ fill arr ###########
    srand(time(NULL));
    for(i=0;i<arr_size;i++){
        data[i] = qdata[i] = hdata[i] = rand();
    }
    //########### perfect sort #########
    sort(data, data+arr_size);
    //############ heap sort #############
    clock_t hstart = clock();
    heapSort(hdata, arr_size);
    clock_t hend = clock();
    //########### quick sort ################
    clock_t qstart = clock();
    QuickSort(qdata, 0, arr_size-1);
    clock_t qend = clock();
    //########### print result ##############
    for(i=0;i<arr_size;i++){
        if(data[i] != qdata[i]){
            printf("at %d, qsort bug!\n", i);
        }
    }
    for(i=0;i<arr_size;i++){
        if(data[i] != hdata[i]){
            printf("at %d, hsort bug!\n", i);
        }
    }
    printf("arr size : %d\n", arr_size);
    printf("quick sorting swap : %d, compare : %d\n", qswap, qcomp);
    printf("quick sort wall-clock : %0.5f\n", (float)(qend - qstart)/CLOCKS_PER_SEC);
    printf("heap sorting swap : %d, compare : %d\n", hswap, hcomp);
    printf("heap sort wall-clock : %0.5f\n", (float)(hend - hstart)/CLOCKS_PER_SEC);
    return 0;
}
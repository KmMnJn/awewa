#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <algorithm>

#define parent(x) (x-1)/2

using namespace std;

const int arr_size = 1000;

int qswap, qcomp;
int hswap, hcomp;

void heap(int *data, int num){
    for(int i=1; i<num; i++){
        int child = i;
        while(child > 0){
            hcomp++;
            int root = parent(child);
            if(data[root] < data[child]){
                int temp = data[root];
                data[root] = data[child];
                data[child] = temp;
                hswap++;
            }
            child = root;
        }
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
        while (pivot >= arr[low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
        {
            qcomp++;
            low++; // low를 오른쪽으로 이동 
        }
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
}
 
int main(void){
    int i;
    int data[arr_size];
    int qdata[arr_size];
    int hdata[arr_size];
    //############ fill arr ########
    srand(time(NULL));
    for(i=0;i<arr_size;i++){
        data[i] = qdata[i] = hdata[i] = rand();
    }

    //########### perfect sort #####
    sort(data, data+arr_size);
    //############ heap sort #############
    heap(hdata, arr_size);    
    for(int i=arr_size-1; i>=0; i--){
        hswap++;
        int temp = hdata[i];
        hdata[i] = hdata[0];
        hdata[0] = temp;
        heap(hdata, i);    
    }
    
    //###########quick sort ################
    QuickSort(qdata, 0, arr_size-1);

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
    return 0;
}
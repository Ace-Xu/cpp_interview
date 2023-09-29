// #include <algorithm>
// #include <iostream>
// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// }
// void heap_build(int arr[], int len, int index){  //数组、长度、根索引
//     int left = 2*index+1;
//     int right = 2*index+2;
//     int maxindex = index;   //交换下标，方便判断是否发生过交换
//     //len-1 是最大下标。0
//     if(left<len && arr[maxindex]<arr[left]){
//         maxindex = left;
//     }
//     if(right<len && arr[maxindex]<arr[right]){
//         maxindex = right;
//     }
//     if(maxindex!=index){
//         swap(arr[maxindex], arr[index]);
//         heap_build(arr, len, maxindex);
//     }
// }

// void heap_sort(int arr[], int len){   //数组、长度
//     //构建初始大根堆,arr[0]肯定是最大的
//     for(int i=len/2-1; i>=1; --i){
//         heap_build(arr, len, i);
//     }
//     //从最后一个开始，与arr[0]进行交换，每交换一次，待更新的heap长度就-1
//     for(int i = len-1; i>=1; --i){
//         swap(arr[0], arr[i]);
//         heap_build(arr, i, 0);  //长度从len-1开始，越来越小
//     }
// }

//调整需要的三个参数：数组、长度、调整堆的索引

//排序需要两个参数：数组，长度

#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = a;
}

void heap_build(int arr[], int len, int index){
    int l = index*2+1;
    int r = index*2+2;
    int maxindex = index;
    if(l<len && arr[l] > arr[maxindex]){
        maxindex = l;
    }
    if(r<len && arr[r] > arr[maxindex]){
        maxindex = r;
    }
    if(maxindex != index){
        swap(arr[maxindex], arr[index]);
        heap_build(arr, len, maxindex);
    }
}

void heap_sort(int arr[], int len){
    for(int i=len/2-1; i>=0; ++i){
        heap_build(arr, len, i);
    }
    for(int i=len-1; i>=1; --i){
        swap(arr[0], arr[i]);
        heap_build(arr, i, 0);
    }
}


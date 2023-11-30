#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int list[MAX_SIZE];
int n;
float move_count = 0.0;
float comp_count = 0.0;

int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left];
    do {
      
        do
            low++;
        while (low <= right && list[low] < pivot);
        comp_count++; // 비교 횟수 증가
  
        do
            high--;
        while (high >= left && list[high] > pivot);
        comp_count++; // 비교 횟수 증가
        

        if (low < high) {
            SWAP(list[low], list[high], temp);
            move_count++; // 이동 횟수 증가
            comp_count++; // 비교 횟수 증가
        }

    } while (low < high);
    SWAP(list[left], list[high], temp);
    move_count++; // 이동 횟수 증가
    comp_count++; // 비교 횟수 증가
   

    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return high;
}

void quick_sort(int list[], int left, int right) {
    if (left < right) {
        
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for (int a = 0; a < 20; a++) {
        for (i = 0; i < n; i++) {    // 난수 생성 및 출력
            list[i] = rand() % 100;  // 난수 발생 범위 0~99
        }
        printf("\nOriginal List %d\n", a + 1);
        for (i = 0; i < n; i++) {
            printf("%d ", list[i]);
        }
        printf("\n\n");
        printf("Quick Sort\n");
        quick_sort(list, 0, n - 1);
    }
    printf("\nAverage Move Count : %f", move_count / 20);
    printf("\nAverage Comp Count : %f", comp_count / 20);

    return 0;
}
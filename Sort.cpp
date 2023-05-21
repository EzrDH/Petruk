#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

// Fungsi untuk menukar dua elemen pada array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Algoritma Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

// Algoritma Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Fungsi untuk menggabungkan dua subarray terurut
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Algoritma Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Fungsi untuk memilih pivot pada Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Algoritma Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menghasilkan array dengan elemen acak
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

// Fungsi untuk mencetak array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int sizes[] = { 100, 1000, 10000, 100000, 1000000 };
    const int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int* arr1 = new int[size];
        int* arr2 = new int[size];
        int* arr3 = new int[size];
        int* arr4 = new int[size];

        generateRandomArray(arr1, size);
        memcpy(arr2, arr1, size * sizeof(int));
        memcpy(arr3, arr1, size * sizeof(int));
        memcpy(arr4, arr1, size * sizeof(int));

        cout << "Sorting " << size << " data..." << endl;

        clock_t startTime = clock();
        bubbleSort(arr1, size);
        clock_t endTime = clock();

        double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Bubble Sort Running Time: " << executionTime << " ms" << endl;

        startTime = clock();
        selectionSort(arr2, size);
        endTime = clock();

        executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Selection Sort Running Time: " << executionTime << " ms" << endl;

        startTime = clock();
        mergeSort(arr3, 0, size - 1);
        endTime = clock();

        executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Merge Sort Running Time: " << executionTime << " ms" << endl;

        startTime = clock();
        quickSort(arr4, 0, size - 1);
        endTime = clock();

        executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Quick Sort Running Time: " << executionTime << " ms" << endl;
    }

    return 0;
}
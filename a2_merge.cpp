#include <iostream>
#include <cstdlib>
#include <ctime>

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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int sz;
    std::cout << "Enter the size of array: ";
    std::cin >> sz;

    int rand_array[sz];
    for (int i = 0; i < sz; ++i) {
        rand_array[i] = rand() % 10000;
    }

    int arr[sz];
    for (int i = 0; i < sz; ++i) {
        arr[i] = rand_array[i];
    }

    std::cout << "The generated array:" << std::endl;
    for (int i = 0; i < sz; ++i) {
        std::cout << rand_array[i] << " ";
    }
    std::cout << std::endl;

    clock_t start_time = clock();

    mergeSort(arr, 0, sz - 1);

    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    std::cout << "\nElements sorted in ascending order using Merge Sort:" << std::endl;
    for (int i = 0; i < sz; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The sorting time is: " << elapsed_time << " seconds." << std::endl;

    return 0;
}

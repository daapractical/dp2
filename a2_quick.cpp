#include <iostream>
#include <cstdlib>
#include <ctime>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] < pivot) {
                ++i;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
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

    quickSort(arr, 0, sz - 1);

    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    std::cout << "\nElements sorted in ascending order using Quick Sort:" << std::endl;
    for (int i = 0; i < sz; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The sorting time is: " << elapsed_time << " seconds." << std::endl;

    return 0;
}

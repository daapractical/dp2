#include <iostream>
#include <cstdlib>

int binary_search(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int array_size = 5000;
    int arr[5000];

    for (int i = 0; i < array_size; ++i) {
        arr[i] = rand() % 10000;
    }

    for (int i = 0; i < array_size - 1; ++i) {
        for (int j = 0; j < array_size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << "Generated Array:" << std::endl;
    for (int i = 0; i < array_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int key;
    std::cout << "\nEnter the key element to search for: ";
    std::cin >> key;

    int result = binary_search(arr, array_size, key);
    if (result != -1) {
        std::cout << "Element " << key << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << key << " not found in the array." << std::endl;
    }

    return 0;
}

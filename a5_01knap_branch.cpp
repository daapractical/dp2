#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

struct Item {
    int value;
    int weight;
    double value_per_weight;
};

void swap(Item& a, Item& b) {
    Item t = a;
    a = b;
    b = t;
}

int partition(Item arr[], int low, int high) {
    double pivot = arr[high].value_per_weight;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].value_per_weight > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void knapsackBranchAndBound(int values[], int weights[], int capacity, int n) {
    Item* items = new Item[n];

    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
        items[i].value_per_weight = static_cast<double>(values[i]) / weights[i];
    }

    quickSort(items, 0, n - 1);

    int max_value = 0;
    std::vector<int> best_selection(n, 0);
    std::vector<int> current_selection(n, 0);

    auto bound = [&](int i, int current_weight, int current_value) {
        double bound_value = current_value;
        int total_weight = current_weight;

        while (i < n && total_weight + items[i].weight <= capacity) {
            total_weight += items[i].weight;
            bound_value += items[i].value;
            i++;
        }

        if (i < n) {
            bound_value += static_cast<double>(capacity - total_weight) * items[i].value_per_weight;
        }

        return bound_value;
    };

    std::function<void(int, int, int, std::vector<int>&)> branchAndBound = [&](int i, int current_weight, int current_value, std::vector<int>& selected_items) {
        if (current_weight > capacity) {
            return;
        }

        if (i == n) {
            if (current_value > max_value) {
                max_value = current_value;
                best_selection = selected_items;
            }
            return;
        }

        if (bound(i, current_weight, current_value) <= max_value) {
            return;
        }

        branchAndBound(i + 1, current_weight, current_value, selected_items);
        selected_items[i] = 1;
        branchAndBound(i + 1, current_weight + items[i].weight, current_value + items[i].value, selected_items);
        selected_items[i] = 0;
    };

    branchAndBound(0, 0, 0, current_selection);

    std::cout << "Results for Branch and Bound:" << std::endl;
    std::cout << "Maximum value: " << max_value << std::endl;

    std::cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        if (best_selection[i] == 1) {
            std::cout << i << " ";
        }
    }

    delete[] items;
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    knapsackBranchAndBound(values, weights, capacity, n);

    return 0;
}

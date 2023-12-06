#include <iostream>
#include <vector>
#include <functional>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackBacktracking(int values[], int weights[], int n, int capacity) {
    int current_weight = 0;
    int current_value = 0;
    std::vector<int> selected_items(n, 0);
    std::vector<int> max_items(n, 0);
    int max_value = 0;

    std::function<void(int)> backtrack = [&](int i) {
        if (i == n) {
            if (current_value > max_value) {
                max_value = current_value;
                max_items = selected_items;
            }
            return;
        }

        auto is_valid = [&](int i, int current_weight) {
            return (i < n && current_weight + weights[i] <= capacity);
        };

        if (is_valid(i, current_weight + weights[i])) {
            selected_items[i] = 1;
            current_weight += weights[i];
            current_value += values[i];
            backtrack(i + 1);
            current_weight -= weights[i];
            current_value -= values[i];
        }

        selected_items[i] = 0;
        backtrack(i + 1);
    };

    backtrack(0);

    std::cout << "Results for Backtracking:" << std::endl;
    std::cout << "Maximum value: " << max_value << std::endl;

    std::cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        if (max_items[i] == 1) {
            std::cout << i << " ";
        }
    }
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 50;

    knapsackBacktracking(values, weights, n, capacity);

    return 0;
}

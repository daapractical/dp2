#include <iostream>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackDynamicProgramming(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int max_value = dp[n][capacity];
    std::cout << "Results for Dynamic Programming:" << std::endl;
    std::cout << "Maximum value: " << max_value << std::endl;

    std::cout << "Selected items: ";
    int w = capacity;
    for (int i = n; i > 0 && max_value > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            std::cout << i - 1 << " ";
            max_value -= values[i - 1];
            w -= weights[i - 1];
        }
    }
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 50;

    knapsackDynamicProgramming(values, weights, n, capacity);

    return 0;
}

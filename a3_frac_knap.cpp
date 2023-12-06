#include <iostream>
#include <algorithm>
#include <iomanip>

struct Item {
    int weight;
    int profit;
};

bool compareItems(const Item& a, const Item& b) {
    double ratioA = static_cast<double>(b.profit) / b.weight;
    double ratioB = static_cast<double>(a.profit) / a.weight;
    return ratioA > ratioB;
}

double knapsackGreedy(int W, Item items[], int n) {
    std::sort(items, items + n, compareItems);

    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; ++i) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            int remainingWeight = W - currentWeight;
            totalProfit += static_cast<double>(items[i].profit) / items[i].weight * remainingWeight;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int W = 20;
    int n = 5;

    Item items[] = {
        {3, 10},
        {5, 20},
        {5, 21},
        {8, 30},
        {4, 16}
    };

    double maxProfit = knapsackGreedy(W, items, n);
    std::cout << "Maximum profit that can be obtained: " << std::fixed << std::setprecision(2) << maxProfit << std::endl;

    return 0;
}

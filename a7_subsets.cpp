#include <iostream>

#define MAX 100

void printSubset(int subset[], int subsetSize) {
    std::cout << "Solution: ";
    for (int i = 0; i < subsetSize; i++) {
        std::cout << subset[i] << " ";
    }
    std::cout << std::endl;
}

void findSubsetsWithSumUtil(int S[], int n, int targetSum, int subset[], int subsetSize, int sum, int start) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }

    for (int i = start; i < n; i++) {
        if (sum + S[i] <= targetSum) {
            subset[subsetSize] = S[i];
            findSubsetsWithSumUtil(S, n, targetSum, subset, subsetSize + 1, sum + S[i], i + 1);
        }
    }
}

void findSubsetsWithSum(int S[], int n, int targetSum) {
    int subset[MAX];
    std::cout << "Subsets with a sum of " << targetSum << ":\n";
    findSubsetsWithSumUtil(S, n, targetSum, subset, 0, 0, 0);
    if (subset[0] == 0) {
        std::cout << "No subsets found.\n";
    }
}

int main() {
    int S[] = {1, 2, 5, 6, 8};
    int n = sizeof(S) / sizeof(S[0]);
    int targetSum = 9;

    findSubsetsWithSum(S, n, targetSum);

    return 0;
}

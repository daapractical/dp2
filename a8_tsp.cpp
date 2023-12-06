#include <iostream>
#include <climits>
#include <cstring>

#define n 4
#define MAX LLONG_MAX

long long dist[n + 1][n + 1] = {
    {0, 0, 0, 0, 0},
    {0, 0, 10, 15, 20},
    {0, 10, 0, 25, 25},
    {0, 15, 25, 0, 30},
    {0, 20, 25, 30, 0}
};

long long memo[n + 1][1 << (n + 1)];

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

long long fun(int i, int mask) {
    if (mask == ((1 << i) | 3)) {
        return dist[1][i];
    }
    if (memo[i][mask] != 0) {
        return memo[i][mask];
    }
    long long res = MAX;
    for (int j = 1; j <= n; j++) {
        if ((mask & (1 << j)) && j != i && j != 1) {
            res = min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);
        }
    }
    memo[i][mask] = res;
    return res;
}

int main() {
    long long ans = LLONG_MAX;  // Initialize ans to a large positive value
    memset(memo, 0, sizeof(memo));  // Initialize memo to zeros
    for (int i = 1; i <= n; i++) {
        ans = min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);
    }
    std::cout << "The cost of the most efficient tour = " << ans << std::endl;

    return 0;
}

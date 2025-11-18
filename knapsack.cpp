#include <bits/stdc++.h>
using namespace std;

// Standard 0-1 knapsack DP (your function)
int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n), k(n);
    for (auto &i : h) cin >> i;   // prices
    for (auto &i : s) cin >> i;   // pages
    for (auto &i : k) cin >> i;   // copies

    vector<int> wt, val; // expanded items

    // Binary splitting for bounded knapsack
    for (int i = 0; i < n; i++) {
        int copies = k[i];
        int price = h[i];
        int pages = s[i];

        int p = 1;
        while (copies > 0) {
            int take = min(p, copies);
            wt.push_back(take * price);
            val.push_back(take * pages);
            copies -= take;
            p <<= 1;
        }
    }

    int total_items = wt.size();

    cout << knapsack(x, wt, val, total_items) << endl;

    return 0;
}

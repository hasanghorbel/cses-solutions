#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve_case() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int s = 1; s < n + 1; s++) {
        for (int d = 1; d <= 6 && d <= s; d++) {
            dp[s] += dp[s - d];
            if (dp[s] >= MOD)
                dp[s] -= MOD;
        }
    }
    cout << dp[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve_case();

    return 0;
}

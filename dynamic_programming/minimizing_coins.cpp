#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;

    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int s = 1; s <= x; s++) {
        for (int c : coins) {
            if (c <= s && dp[s - c] != INF)
                dp[s] = min(dp[s], dp[s - c] + 1);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

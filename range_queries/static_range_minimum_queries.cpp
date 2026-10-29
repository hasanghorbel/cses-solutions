#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    int LOG = bit_width((unsigned)n);
    vector<vector<int>> sp(LOG, vector<int>(n));
    for (int &x : sp[0])
        cin >> x;

    for (int k = 1; k < LOG; k++)
        for (int i = 0; i + (1 << k) <= n; i++)
            sp[k][i] = min(sp[k - 1][i], sp[k - 1][i + (1 << (k - 1))]);

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        int k = bit_width((unsigned)(b - a + 1)) - 1; // floor(log2(len))
        cout << min(sp[k][a], sp[k][b - (1 << k) + 1]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

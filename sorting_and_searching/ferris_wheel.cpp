#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> p(n);
    for (auto &a : p)
        cin >> a;

    sort(p.begin(), p.end());
    int ans = 0, l = 0, r = p.size() - 1;
    while (l <= r) {
        if (l < r && p[l] + p[r] <= x)
            l++;
        r--;
        ans++;
    }
    cout << ans << "\n";

    return 0;
}

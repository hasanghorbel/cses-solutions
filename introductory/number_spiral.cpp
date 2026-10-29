#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long y, x;
        cin >> y >> x;
        long long m = max(y, x);
        long long base = (m - 1) * (m - 1);
        long long ans;
        if (m % 2 == 0) {
            if (x == m)
                ans = base + y;
            else
                ans = base + m + m - x;
        } else {
            if (y == m)
                ans = base + x;
            else
                ans = base + m + (m - y);
        }
        cout << ans << "\n";
    }
    return 0;
}

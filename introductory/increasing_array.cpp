#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long prev, ans = 0;
    cin >> prev;
    for (int i = 1; i < n; i++) {
        long long x;
        cin >> x;
        if (x < prev)
            ans += prev - x;
        else
            prev = x;
    }
    cout << ans << "\n";
    return 0;
}

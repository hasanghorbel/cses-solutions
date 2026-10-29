#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (b[j] < a[i] - k)
            j++;
        else if (b[j] > a[i] + k)
            i++;
        else {
            cnt++;
            i++;
            j++;
        }
    }
    cout << cnt << "\n";

    return 0;
}

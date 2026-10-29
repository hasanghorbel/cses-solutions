#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x;
    cin >> n;
    long long total = n * (n + 1) / 2;
    for (long long i = 0; i < n - 1; i++) {
        cin >> x;
        total -= x;
    }
    cout << total << "\n";
    return 0;
}

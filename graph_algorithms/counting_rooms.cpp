#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &row : g)
        cin >> row;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int rooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '.')
                continue;
            rooms++;
            queue<pair<int, int>> q;
            q.push({i, j});
            g[i][j] = '#';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (g[nx][ny] != '.')
                        continue;
                    g[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << rooms << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

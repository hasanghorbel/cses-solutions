#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &row : g)
        cin >> row;

    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A')
                sx = i, sy = j;
            if (g[i][j] == 'B')
                ex = i, ey = j;
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    char name[4] = {'D', 'U', 'R', 'L'};

    vector<vector<int>> from(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    from[sx][sy] = 4;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (g[nx][ny] == '#' || from[nx][ny] != -1)
                continue;
            from[nx][ny] = d;
            q.push({nx, ny});
        }
    }

    if (from[ex][ey] == -1) {
        cout << "NO\n";
        return;
    }

    string path;
    int x = ex, y = ey;
    while (!(x == sx && y == sy)) {
        int d = from[x][y];
        path += name[d];
        x -= dx[d];
        y -= dy[d];
    }
    reverse(path.begin(), path.end());

    cout << "YES\n"
         << path.size() << "\n"
         << path << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

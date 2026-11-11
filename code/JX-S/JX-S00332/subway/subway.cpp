#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005];
int k[505], a[505][500005], t[505][500005];
int dis[100005];
bool vis[505][505];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct node {
    int x, y, step;
};

int bfs(int s, int e) {
    queue<node> q;
    q.push({s, s, t[s][s]});
    memset(vis, 0, sizeof(vis));
    vis[s][s] = 1;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();

        if (cur.y == e) {
            return cur.step;
        }
        vis[cur.x][cur.y] = 1;

        for (int i = 0; i < 4; i ++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny] || !t[nx][ny]) {
                continue;
            }
            q.push({nx, ny, cur.step + t[nx][ny]});
        }
    }
    return 0;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i ++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j ++) {
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int r = 1; r <= q; r ++) {
        int x, y;
        cin >> x >> y;
        dis[r] = w[x] + bfs(x, y) + w[y];
    }

    for (int r = 1; r <= q; r ++) {
        cout << dis[r] << " ";
    }
    cout << "\n";
    
    return 0;
}
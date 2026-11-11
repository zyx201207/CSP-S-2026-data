#include<bits/stdc++.h>
using namespace std;
const int N = 505, M = 3e5 + 5, INF = 1e9;
int c, n, m, d, q, w[M], k[N], cnt[M], a[N][M], t[N][M];//cnt统计地铁站经过的地铁线路数量
bool tx[M];//是否为换乘站
bool train[N][M];//等于1表示线路i经过j
vector<int> transs[M];//每个地铁站经过的线路编号
vector<int> txee;//换乘地铁站编号
vector<int> tran[N][N];//线路与线路连接的地铁站编号
int cw[N][N];
int h[N], to[N * N], nxt[N * N], ct[N * N], dis[N][N], idx;
void add(int u, int v, int c) {
    idx++;
    to[idx] = v, nxt[idx] = h[u], ct[idx] = c, h[u] = idx;
}
void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s}), dis[s][s] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top();pq.pop();
        if(d > dis[s][u]) continue;
        for(int i = h[u];i ;i = nxt[i]) {
            int v = to[i], ctw = ct[i];
            if(dis[s][v] > dis[s][u] + ctw) {
                dis[s][v] = dis[s][u] + ctw;
                pq.push({dis[s][v], v});
            }
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i < n; i++) {
        for(int j = i + 1;j <= n; j++) cw[i][j] = INF;
    }
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= n; j++) dis[i][j] = INF;
    }
    for(int i = 1;i <= m; i++) cin >> w[i];
    for(int i = 1;i <= n; i++) {
        cin >> k[i];
        for(int j = 1;j <= k[i]; j++) {
            int tmp;
            cin >> a[i][j] >> tmp;
            train[i][a[i][j]] = 1;
            t[i][a[i][j]] = tmp;;
            cnt[a[i][j]]++;
            transs[a[i][j]].push_back(i);
        }
    }
    for(int i = 1;i <= m; i++) {
        if(cnt[i] > 1) {
            txee.push_back(i), tx[i] = 1;
        }
    }
    for(auto v : txee) {
        for(int i = 0;i < transs[v].size() - 1; i++) {
            for(int j = i + 1;j < transs[v].size(); j++) {
                if(i == j) continue;
                int a = transs[v][i], b = transs[v][j];
                tran[a][b].push_back(v);
            }
        }
    }
    for(int i = 1;i < n; i++) {
        for(int j = i + 1;j <= n; j++) {
            int minn = 1e9;
            for(auto v : tran[i][j]) {
                int pos = v, a = i, b = j;
                int sum = t[a][v] + t[b][v];
                minn = min(minn, sum);
            }
            cw[i][j] = minn;
        }
    }
    for(int i = 1;i < n; i++) {
        for(int j = i + 1;j <= n; j++) {
            if(cw[i][j] != INF) add(i, j, cw[i][j]), add(j, i, cw[i][j]);
        }
    }
    for(int i = 1;i <= n; i++) dijkstra(i);
    while(q--) {
        int x, y;
        cin >> x >> y;
        int sum = w[x] + w[y];
        if(!tx[x] && !tx[y]) {
            int a = transs[x][0], b = transs[y][0];
            sum += dis[a][b] + t[a][x] + t[b][y];
            cout << sum << '\n';
        }
        else {
            int minn = INF;
            for(auto f1 : transs[x]) {
                for(auto f2 : transs[y]) {
                    minn = min(minn, dis[f1][f2] + t[f1][x] + t[f2][y]);
                }
            }
            sum += minn;
            cout << sum << '\n';
        }
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

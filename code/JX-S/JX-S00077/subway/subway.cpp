#include <bits/stdc++.h>
using namespace std;
const int M = 2e4 + 5;
const int N = 505;
const int K = 2 * M + N;
const int Q = 4 * M;
struct Edge {
    int to, nxt;
    int w;
}e[Q];
int head[K], ecnt = 0;
int c, n, m, d, q;
int w[M];
int k[N];
int a[N][M], t[N][M];
int dist[N][M];
void init() {
    memset(head, -1, sizeof(head));
    ecnt = 1;
}
void floyd(int st) {
    for (int i = head[st]; ~i; i = e[i].to) {
        for (int j = head[st]; ~j; j = e[j].to) {
            if (dist[i][j] + e[i].w < dist[j][i]) {
                dist[j][i] = dist[i][j] + e[i].w;
            }
        }
    }
}
void add(int u, int v, int w) {
    head[u] = u;
    e[ecnt].w = w;
    e[ecnt].to = v;
    e[ecnt].nxt = ecnt++;
}
void addEdge(int u, int v, int w) {
    add(u, v, w);
    add(v, u, w);
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
        addEdge(i, m + i, w[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            addEdge(m + a[i][j], 2 * m + i, t[i][j]);
        }
    }
    floyd(1);
    for (int r = 1; r <= q; r++) {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << '\n';
    }
    return 0;
}
//hao ji ge yue mei xie zui duan lu de xia chang
//jin shi hou ren:yi hou csp qian yi ding yao xie zui duan lu
//a lian shi qian xiang xing wo ye hao jiu mei xie le a
//zui jin lian de yi ge mei kao aaa QAQ

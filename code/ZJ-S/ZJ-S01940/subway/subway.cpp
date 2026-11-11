#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 511, MAXM = 5e5 + 11, MAXMM = 6e5 + 11;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
int ww[MAXM];
int k[MAXN];
int a[MAXM], t[MAXM];

struct Edge{
    int to, nxt, dist;
} edge[MAXMM];
int head[MAXMM], tot = 0;
void addEdge(int u, int v, int w)
{
    ++tot;
    edge[tot].to = v;
    edge[tot].dist = w;
    edge[tot].nxt = head[u];
    head[u] = tot;
}
ll dis[MAXMM];
bool vis[MAXMM];

struct Node{
    int v;
    ll w;
    bool operator< (const Node obj) const {
        return w > obj.w;
    }
};

void dijkstra(int s)
{
    for (int i = 1; i <= 2 * m + 1; i++)
        dis[i] = INF, vis[i] = false;
    priority_queue <Node> pq;
    dis[s] = 0;
    pq.push((Node) {s, 0});
    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) continue;
        for (int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            int w = edge[i].dist;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push((Node) {v, dis[u] + w});
            }
        }
    }
}

signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> ww[i];
    }
    for (int i = 1; i <= m; i++) {
        addEdge(i, i + m, ww[i]);
        addEdge(i + m, i, ww[i]);
        //cout << i << "->" << i + m <<"\n";
    }
    int cnt1 = tot;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[j] >> t[j];
            addEdge(a[j] + m, a[j] + cnt1 + i, t[j]);
            addEdge(a[j] + cnt1 + i, a[j] + m, t[j]);
            cout << a[j] + m << "->"<< a[j] + cnt1 + i <<"\n";
            if (j >= 2) {
                addEdge(a[j] + cnt1 + i, a[j - 1] + cnt1 + i, 0);
                addEdge(a[j - 1] + cnt1 + i, a[j] + cnt1 + i, 0);
                //cout << a[j - 1] + cnt1 + i << "->"<< a[j] + cnt1 + i <<"\n";
            }
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        dijkstra(x);
        cout << dis[y] << "\n";
    }
    cout.flush();
    return 0;
}

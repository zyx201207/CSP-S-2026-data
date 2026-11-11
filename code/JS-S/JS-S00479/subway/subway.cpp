#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e2 + 5;
const int maxm = 5e5 + 5;
const int INF = 1e18;
int c, n, m, d, q, w[maxm], k[maxn], dis[maxm + maxn];
bool vis[maxm + maxn];
struct Node {
    int to, val;
};
vector<Node> G[maxn + maxm];
struct Cmp {
    bool operator()(const Node& X, const Node& Y) {
        return X.val > Y.val;
    }
};
void dijkstra(int s) {
    for(int i = 1; i <= m + n; i++) dis[i] = INF, vis[i] = false;
    priority_queue<Node, vector<Node>, Cmp> pq;
    dis[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()){
        Node tmp = pq.top(); pq.pop();
        int u = tmp.to;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto it : G[u]) {
            int v = it.to, val = it.val;
            if(dis[v] > dis[u] + val) {
                dis[v] = dis[u] + val;
                pq.push({v, dis[v]});
            }
        }
    }
}
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
        for(int j = 1; j <= k[i]; j++) {
            int v, a;
            cin >> v >> a;
            G[m + i].push_back({v, a});
            G[v].push_back({m + i, a});
        }
    }
    while(q--) {
        int s, t;
        cin >> s >> t;
        int ans = 0;
        dijkstra(s);
        ans = w[s] + w[t] + dis[t];
        cout << ans << '\n';

    }
    return 0;
}

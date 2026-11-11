#include<bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
int c, n, m, d, q, k, ans = INT_MAX;
struct node{
    long long x, w;
};
vector<node> adj[100010];
long long W[100010];
bool vis[1000010];
//long long dis[1000010];
bool operator<(node x, node y) {
    return x.w < y.w;
}
/*void dij(int st) {
    priority_queue<node> q;
    q.push({st, 0});
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[st] = 0;
    while (!q.empty()) {
        int top = q.top().x;
        int w = q.top().w;
        cout << top << " " << w << '\n';
        q.pop();
        for (auto i : adj[top]) {
            int u = i.x;
            if (dis[u] > dis[top] + i.w + W[u]) {
                dis[u] = dis[top] + i.w + W[u];
                cout << "111 "<< i.x << ' ' << dis[u] << "\n";
                if (!vis[u]) {
                    q.push({u, dis[u]});
                    vis[u] = 1;
                }
            }
        }
        cout << '\n';
    }
}*/
void dfs(int x, int y,int sum) {
    //cout << x << " " << sum << '\n';
    if (x == y) {
        ans = min(sum, ans);
        return ;
    }
    for (auto i : adj[x]) {
        if (!vis[i.x]) {
            vis[i.x] = 1;
            dfs(i.x, y, sum + i.w + W[i.x]);
            vis[i.x] = 0;
        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> W[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k;
        int tme = 0;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            tme += t;
            adj[i].push_back({a, tme});
            adj[a].push_back({i, tme});
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ans = INT_MAX;
        memset(vis, 0, sizeof(vis));
        dfs(x, y, 0);
        cout << ans + W[x]<< '\n';
    }
    return 0;
}

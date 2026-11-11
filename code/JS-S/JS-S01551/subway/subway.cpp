#include <bits/stdc++.h>
using namespace std;
struct id {
    int xl, idn;
};
struct node {
    id num;
    int t;
};
int c, n, m, d, q, w[500010];
bool vis[500010];
long long ans, f[500010];
vector<node> g[500010];
void dijkstra(int s, int t) {
    memset(f, 0x3f, sizeof f);
    memset(vis, 0, sizeof vis);
    f[s] = 0, f[t] = 0, vis[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
    qu.push({0, s});
    while (qu.size()) {
        auto x = qu.top();
        qu.pop();
        for (node i : g[x.second]) {

        }
    }
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int a, te;
            cin >> a >> te;

        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        ans = 0, ans += w[x] + w[y];
        dijkstra(x, y);
        cout << f[y];
    }
    return 0;
}

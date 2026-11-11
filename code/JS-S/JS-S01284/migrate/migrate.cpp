#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, t, n, d, x[5005], dis[5005], dp[5005], ans;
bool vis[5005];
vector<int> g[5005];
void dijkstra(ll s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 0x3f3f3f3f3f3f3f3f;
        vis[i] = 0;
        dp[i] = 0;
    }
    priority_queue<pair<ll, ll> > q;
    dis[s] = 0;
    dp[s] = 1;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (auto v : g[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                dp[v] = dp[u];
                q.push(make_pair(-dis[v], v));
            } else if (dis[v] == dis[u] + 1) {
                dp[v] += dp[u];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] != 0x3f3f3f3f3f3f3f3f && dp[i] == 2)ans++;
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (x[j] - x[i] <= d) {
                    g[i].push_back(j);
                } else {
                    break;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            dijkstra(i);
        }
        cout << ans << endl;
        for (int i = 1; i <= n; i++)g[i].clear();
    }
    return 0;
}

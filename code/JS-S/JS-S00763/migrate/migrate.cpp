#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5010;

int c, tt;

int n;

ll d;

ll x[N];

vector<int> g[N];

int dist[N], cnt[N];

queue<int> que;

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (abs(x[j] - x[i]) <= d) {
                g[i].emplace_back(j);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        que.push(i);
        memset(dist, -1, sizeof dist);
        memset(cnt, 0, sizeof cnt);
        dist[i] = 0;
        while (que.size()) {
            int u = que.front();
            que.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    cnt[v] ++;
                    que.push(v);
                } else if (dist[v] == dist[u] + 1) {
                    cnt[v] += 1;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            ans += (cnt[j] == 2 && i < j);
            //cout << cnt[j] << " \n"[j == n];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

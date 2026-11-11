#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll c, n, m, d, q;
vector<ll> a[N];
vector<ll> t[N];
ll w[N];
ll bfs(int st, int ed) {
    ll vis[N];
    queue<ll> q;
    q.push(st);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (ll i : a[now]) {
            if (vis[i] == 0) {
                q.push(i);
                vis[i] += t[now][i];
            }
        }
    }
    return vis[ed];
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int x, y;
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
        }
    }
    for (int i = 1; i <= q; i++) {
        int st, ed;
        cin >> st >> ed;
        cout << bfs(st, ed) + w[ed] << endl;
    }
    return 0;
}

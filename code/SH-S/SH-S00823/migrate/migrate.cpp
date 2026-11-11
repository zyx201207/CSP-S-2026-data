#include <bits/stdc++.h>
using namespace std;

const int N = 2E6 + 5;
typedef long long ll;
ll n, d;
ll x[N];
vector<int> E[N];

bool check(int l, int r) {
    // xr - d, xl + d
    int fs = lower_bound(x + 1, x + n + 1, x[r] - d) - x;
    int lst = upper_bound(x + 1, x + n + 1, x[l] + d) - x - 1;
    return (lst - fs == 1);
}

void case1() {
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int r = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        // xv - d <= xl
        int xl = r - 1;
        if (xl < 1) continue;
        // xv <= d + xl
        int v = upper_bound(x + 1, x + n + 1, x[xl] + d) - x - 1;
        if (v > i && check(i, v))
            ans++;
        // ans += max(v - i, 0);
        // cerr << i << ' ' << v << '\n';
    }
    cout << ans << '\n';
    return ;
}

int cnt[N];
ll dis[N];
queue<int> q;
bool vis[N];

// void spfa(int s) {
//     for (int i = 1; i <= n; i++) dis[i] = 1e9;
//     for (int i = 1; i <= n; i++) vis[i] = 0;
//     for (int i = 1; i <= n; i++) cnt[i] = 0;
//     dis[s] = 0;
//     cnt[s] = 1;
//     vis[s] = 1;
//     q.push(s);
//     while (q.size()) {
//         int u = q.front();
//         q.pop();
//         vis[u] = 0;
//         for (int v : E[u]) {
//             if (dis[v] > dis[u] + 1) {
//                 dis[v] = dis[u] + 1;
//                 if (!vis[v]) {
//                     q.push(v);
//                     vis[v] = 1;
//                 }
//                 cnt[v] = cnt[u];
//             } else if (dis[v] == dis[u] + 1) {
//                 // if (!vis[v])
//                     cnt[v] += cnt[u];
//             }
//         }
//     }
// }

struct node {
    int u; ll dis;
    bool operator > (const node &b) const {
        return dis > b.dis;
    }
};

priority_queue<node, vector<node>, greater<node>> q2;

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    dis[s] = 0;
    cnt[s] = 1;
    q2.push({s, 0});
    while (q2.size()) {
        auto tmp = q2.top(); int u = tmp.u; q2.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : E[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q2.push({v, dis[v]});
                cnt[v] = cnt[u];
            } else if (dis[v] == dis[u] + 1) cnt[v] += cnt[u];
        }
    }
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        E[i].clear();
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] - d <= x[1] && x[i] + d >= x[n] && n > 300) {
            case1();
            return ;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (x[j] - x[i] <= d) {
                E[i].push_back(j);
                E[j].push_back(i);
            } else break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        for (int j = i + 1; j <= n; j++) {
            ans += (cnt[j] == 2);
        }
    }
    cout << ans << '\n';
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    // cerr << (double)clock() / CLOCKS_PER_SEC << '\n';
}
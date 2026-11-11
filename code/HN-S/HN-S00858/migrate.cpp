#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e6 + 10;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[N];
vector<int> g[N];
ll dis[N];
ll cnt[N];
bool vis[N];
int n;
ll d;

void Init() {
    fill(g + 1, g + n + 1, vector<int>());
}

ll Bfs(int s) {
    fill(dis + 1, dis + n + 1, INF);
    fill(cnt + 1, cnt + n + 1, 0);
    fill(vis + 1, vis + n + 1, false);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    cnt[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (auto y : g[x]) {
            if (dis[x] + 1 < dis[y]) {
                dis[y] = dis[x] + 1;
                cnt[y] = cnt[x];
            } else if (dis[x] + 1 == dis[y]) {
                cnt[y] += cnt[x];
            }
            q.push(y);
        }
    }

    ll ans = 0;
    for (int i = s + 1; i <= n; ++i) {
        ans += cnt[i] == 2;
        // cout << dis[i] << ' ' << cnt[i] << '\n';
    }
    return ans;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, t;
    cin >> c >> t;
    if (11 <= c && c <= 12) {
        while (t--) {
            cin >> n >> d;
            for (int i = 1; i <= n; ++i) cin >> a[i];
            if (n == 1) {
                cout << 0 << '\n';
                continue;
            }
            ll delta = a[2] - a[1];
            d /= delta;
            if (d == 0 || d == 1 || n <= d * 2 - 1) cout << 0 << '\n';
            else cout << n - (d * 2 - 1) << '\n';
        }
        return 0;
    }
    while (t--) {
        cin >> n >> d;
        Init();
        for (int i = 1; i <= n; ++i) cin >> a[i];

        for (int i = 1; i <= n; ++i) {
            int j = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
            for (int k = i + 1; k <= j; ++k) {
                g[i].push_back(k);
                g[k].push_back(i);
            }
        }

        ll ans = 0;
        for (int s = 1; s <= n; ++s) ans += Bfs(s);
        cout << ans << '\n';
    }
}


// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define int ll
// constexpr int N = 2e6 + 10;

// ll a[N];
// int rmost[N];
// int n;
// ll d;

// int Dfs(int l, int r) {
//     if (l >= r) {
//         return 0;
//     } else if (l + 1 == r) {
//         return max(rmost[l] - r, 0LL) + Dfs(rmost[l] + 1, rmost[r]);
//     }
//     int r1 = rmost[r], r2 = rmost[r - 1], r3 = rmost[r - 2];
//     // cout << l << ' ' << r << ' ' << r1 << ' ' << r2 << ' ' << r3 << '\n';
//     return r2 - r3 + Dfs(r2 + 1, r1);
// }

// signed main() {
//     // freopen("migrate.in", "r", stdin);
//     // freopen("migrate.out", "w", stdout);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int c, t;
//     cin >> c >> t;
//     while (t--) {
//         cin >> n >> d;
//         for (int i = 1; i <= n; ++i) cin >> a[i];
//         for (int i = 1; i <= n; ++i) {
//             rmost[i] = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
//         }
//         int ans = 0;
//         for (int i = 1; i <= n; ++i) {
//             ans += Dfs(i, rmost[i]);
//             // cout << '\n';
//         }
//         cout << ans << '\n';
//     }
// }

// /*
// 5 3
// -3 0 2 3 4
// */
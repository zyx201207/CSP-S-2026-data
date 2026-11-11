#ifndef ENABLE_DEBUG
#define NDEBUG
#endif
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using ui128 = __uint128_t;
#define amin(x, y) x = min(x, y)
#define amax(x, y) x = max(x, y)
#define gcd(x, y) __gcd(x, y)
#ifdef NO_FILE
#define file(x) (void)0
#else
#define file(x) auto _ = freopen(x ".in", "r", stdin); \
                     _ = freopen(x ".out", "w", stdout); \
                (void)_;
#endif

constexpr int maxm = 500001;
constexpr int maxn = 501;
constexpr int maxq = 100001;

int c, n, m, d, q;
ll w[maxm];

vector<pair<int, ll>> g[maxm + maxn];
ll gdis[maxn][maxm + maxn];
int ver_d[maxm + maxn];
int ver[maxm + maxn];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    file("subway");

    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            int a;
            ll t;
            cin >> a >> t;
            g[a].emplace_back(m + i, t);
            g[m + i].emplace_back(a, t);
        }
    }

    // spj B
    if (12 <= c && c <= 19) {
        int v = m + n;
        for (int i = m + 1; i <= v; ++i) {
            auto &dis = gdis[i - m];
            queue<int> q;
            q.emplace(i);
            dis[i] = 0;
            ver[i] = i;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                for (const auto &p : g[cur]) {
                    int ch = p.first;
                    if (ver[ch] == i) {
                        continue;
                    }
                    ver[cur] = i;
                    dis[ch] = dis[cur] + p.second;
                    q.emplace(ch);
                }
            }
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            if (g[x].size() > g[y].size()) {
                swap(x, y);
            }
            ll mn = 0x3f3f3f3f3f3f3f3f;
            for (const auto &p : g[x]) {
                amin(mn, gdis[p.first - m][y] + p.second);
            }
            cout << mn + w[x] + w[y] << '\n';
        }

        cout << flush;
        return 0;
    }

    int v = m + n;
    for (int i = m + 1; i <= v; ++i) {
        auto &dis = gdis[i - m];
        priority_queue<pair<ll, int>> pq;
        pq.emplace(0, i);
        dis[i] = 0;
        ver_d[i] = i;
        while (!pq.empty()) {
            int cur = pq.top().second;
            pq.pop();
            if (ver[cur] == i) {
                continue;
            }
            ver[cur] = i;

            for (const auto &p : g[cur]) {
                int ch = p.first;
                ll d = dis[cur] + p.second;
                if (ver_d[ch] != i || dis[ch] > d) {
                    ver_d[ch] = i;
                    dis[ch] = d;
                    pq.emplace(-dis[ch], ch);
                }
            }
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        if (g[x].size() > g[y].size()) {
            swap(x, y);
        }
        ll mn = 0x3f3f3f3f3f3f3f3f;
        for (const auto &p : g[x]) {
            amin(mn, gdis[p.first - m][y] + p.second);
        }
        cout << mn + w[x] + w[y] << '\n';
    }

    cout << flush;
    return 0;
}

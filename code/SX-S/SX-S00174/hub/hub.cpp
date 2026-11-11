#include <bits/stdc++.h>
using namespace std;
template <class T> T lowbit(T x) {return x & -x;}
template <class T> T lg(T x) {return x == 0 ? 0 : __lg(x);}
template <class T> T ctz(T x) {return x == 0 ? 0 : __builtin_ctzll(x);}
#define gcd __gcd
#define pb emplace_back
#define popcount __builtin_popcountll
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
mt19937 rand32(time(0));
mt19937_64 rand64(time(0));
template <class T>
ostream& operator<< (ostream& out, const vector<T>& v) {
	out << '['; int n = v.size();
	for (const auto& i : v) out << i << (--n ? ", " : "");
	return out << ']';
}
#undef assert
#ifdef LOCAL
#define FLOCAL(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define FILE(x) void()
#define assert(x) ((x) ? void() : (cerr << "Assertion Failed on Line " << __LINE__ << endl, exit(0)))
#define debug(x) (cerr << "On Line " << __LINE__ << ": " << #x << " = " << (x) << endl)
void _o(auto&&... x) {bool f = 1; ((cerr << (f?"":", ") << x, f = 0), ...);}
#define mdebug(...) (cerr << "On Line " << __LINE__ << ": {" << #__VA_ARGS__ << "} = [", _o(__VA_ARGS__), cerr << "]\n")
#else
#define FILE(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define FLOCAL(x) void()
#define assert(x) void()
#define debug(x) void()
#define mdebug(...) void()
#endif

// #define int long long
const int N = 1e6 + 5, inf = 1e9;
int num, n, k;
vector<int> e[N];

namespace BF {
    const int N = 105;
    int dis[N][N];
    void dfs(int u, int fa, int* d) {
        for (int v : e[u]) if (v != fa) d[v] = d[u] + 1, dfs(v, u, d);
    }
    void _main() {
        for (int i = 1; i <= n; i++) dis[i][i] = 0, dfs(i, -1, dis[i]);
        int res = inf;
        for (int s = 0; s < (1<<n); s++) {
            if (popcount(s) != k) continue;
            auto check = [&]() -> bool {
                int cnt = 0;
                for (int u = 1; u <= n; u++) if (s >> (u-1) & 1) 
                    for (int v : e[u]) if (s >> (v-1) & 1) cnt++;
                return k - cnt/2 <= 2;
            };
            if (!check()) continue;
            int cur = -inf;
            for (int u = 1; u <= n; u++) {
                int dm = inf;
                for (int v = 1; v <= n; v++) if (s >> (v-1) & 1) dm = min(dm, dis[u][v]);
                cur = max(cur, dm);
            }
            res = min(res, cur);
        }
        cout << res << '\n';
    }
}

namespace SubA {
    void _main() {
        int m = (n+1) / 2;
        if (k >= m) return cout << 1 << '\n', void();
        int res = inf;
        for (int l1 = 1; l1 <= m; l1++) {
            int r1 = min(m, l1 + (k+1)/2 - 1);
            int r2 = m - l1 + 1;
            int l2 = max(1, r2 - k/2 + 1);
            int cur = l1;
            if (r1 < l2) {
                int mid = (r1 + l2) >> 1;
                cur = max(cur, mid - r1 + 1);
                cur = max(cur, l2 - (mid+1) + 1);
            }
            // mdebug(l1, r1, l2, r2);
            res = min(res, cur);
        }
        cout << res << '\n';
    }
}

namespace K2 {
    const int N = 1005;
    int dis[N][N];
    void dfs(int u, int fa, int* d) {
        for (int v : e[u]) if (v != fa) d[v] = d[u] + 1, dfs(v, u, d);
    }
    void _main() {
        for (int i = 1; i <= n; i++) dis[i][i] = 0, dfs(i, -1, dis[i]);
        int res = inf;
        for (int u = 1; u <= n; u++)
            for (int v = u+1; v <= n; v++) {
                int cur = -inf;
                for (int i = 1; i <= n; i++) cur = max(cur, min(dis[i][u], dis[i][v]));
                res = min(res, cur);
            }
        cout << res << '\n';
    }
}

namespace dale {
    const int N = 1005;
    int dis[N][N];
    bool tag[N];
    vector<int> vec;
    void dfs(int u, int fa, int* d) {
        for (int v : e[u]) if (v != fa) d[v] = d[u] + 1, dfs(v, u, d);
    }
    int solve() {
        int res = -inf;
        for (int i = 1; i <= n; i++) {
            int cur = inf;
            for (int j : vec) cur = min(cur, dis[i][j]);
            if (cur > res) res = cur;
        }
        return res;
    }
    void _main() {
        for (int i = 1; i <= n; i++) dis[i][i] = 0, dfs(i, -1, dis[i]);
        vec.clear();
        int res = inf, x = -1, y = -1;
        for (int u = 1; u <= n; u++)
            for (int v = u+1; v <= n; v++) {
                vec = {u, v}; int cur = solve();
                if (cur < res) res = cur, x = u, y = v;
            }
        vec = {x, y};
        for (int i = 2; i < k; i++) {
            int res = inf, p = -1;
            for (int u = 1; u <= n; u++) {
                auto check = [&]() -> bool {
                    for (int j : vec) if (u == j) return false;
                    for (int j : vec) if (dis[u][j] <= 1) return true;
                    return false;
                };
                if (!check()) continue;
                vec.pb(u);
                int cur = solve();
                if (cur < res) res = cur, p = u;
                vec.pop_back();
            }
            // debug(res);
            vec.pb(p);
        }
        cout << solve() << '\n';
    }
}

void _main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].pb(v), e[v].pb(u); 
    }
    if (num <= 3) return BF::_main(), void();
    if (n == k) return cout << 0 << '\n', void();
    if (13 <= num && num <= 14) return SubA::_main(), void();
    if (num == 7) return K2::_main(), void();
    dale::_main();
} signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
    FILE("hub");
    // FLOCAL("hub3");
    // freopen("log.txt", "w", stderr);

	int t = 1; for (cin >> num >> t; t--; ) _main();
	return 0;
}

#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define fs first
#define sc second
using namespace std;
typedef unsigned long long u64;
typedef long long i64;
typedef unsigned u32;
typedef signed i32;
namespace INIT {
    #define dbg(...) _dbg(#__VA_ARGS__,__VA_ARGS__)
    void _dbg(const char*) {cerr << "\n";}
    template<class T, class ...U>
    void _dbg(const char* s, T x, U... y) {
        while (*s&&*s!=',') cerr << *s++;
        cerr << '=' << x;
        if (*s == ',') {
            cerr << ',';
            _dbg(s + 1, y...);
        } else {
            cerr << '\n';
        }
    }
    template<typename T>
    T mabs(T x) {return x<=0?-x:x;}
}
using namespace INIT;
bool Mbeg;
const int MAX_SIZE = 1024;
typedef pair<int, int> pii;
const int N(5e5 + 5);
int c, n, m, d, q, w[N];
vector<pii> G[N];
int dis[505][505];
void solve(int tid) {
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, t;
            cin >> a >> t;
            G[a].eb(i, t);
        }
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            for (int k = j + 1; k < G[i].size(); k++) {
                int u = G[i][j].fs, v = G[i][k].fs;
                dis[u][v] = dis[v][u] = min(dis[u][v], G[i][j].sc + G[i][k].sc);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         dbg(i, j, dis[i][j]);
    //     }
    // }
    while (q--) {
        int u, v;
        cin >> u >> v;
        int ans = 1e18;
        for (int i = 0; i < G[u].size(); i++) {
            for (int j = 0; j < G[v].size(); j++) {
                ans = min(ans, w[u] + G[u][i].sc
                             + w[v] + G[v][j].sc
                             + dis[G[u][i].fs][G[v][j].fs]);
            }
        }
        cout << ans << '\n';
    }
}
bool Med;
signed main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}
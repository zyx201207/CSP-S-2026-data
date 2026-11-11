#include <bits/stdc++.h>
#define eb emplace_back
#define int long long
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
const int N(1e6 + 5);
int n, k;
vector<int> G[N];
int d[N], deg[N];
void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++) if (G[i].size() == 1) q.push(i), d[i] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (auto &v: G[u]) {
            if (--deg[v] == 1) {
                q.push(v);
                d[v] = max(d[v], d[u] + 1);
            }
        }
    }
}
int cd[N];
void clear() {
    for (int i = 0; i <= n + 5; i++) {
        G[i].clear();
        d[i] = deg[i] = 0;
        cd[i] = 0;
    }
    n = k = 0;
}

void solve(int tid) {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].eb(v);
        G[v].eb(u);
        deg[u]++, deg[v]++;
    }
    //没救了。
    //不该冲T3的。
    //最好笑的一场。
}
bool Med;
signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin.tie(0), cout.tie(0)->sync_with_stdio(0);
    int c, T = 1;
    cin >> c >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}
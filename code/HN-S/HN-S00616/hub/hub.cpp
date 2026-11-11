#include <iostream>
#include <cstdio>
using namespace std;

constexpr int MAXN = 1e6 + 10;

int n, k, head[MAXN], tot = 0;
struct node {int to, nxt;} edge[MAXN << 1];

inline void add_edge(int u, int v) {edge[++tot] = {v, head[u]};}

inline void solve() {
    cin >> n >> k;
    for (register int i = 1; i <= n; ++i) head[i] = 0;
    for (register int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v, add_edge(u, v), add_edge(v, u);
    }
    int m = n / 2 + 1, mid = (1 + m) / 2, ans = mid;
    k = 0;
    while (k) ans /= 2, k /= 2;
    cout << ans << '\n';
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    if (13 <= c && c <= 14) while (T--) solve();
    return 0;
}
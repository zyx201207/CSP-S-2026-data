#include <bits/stdc++.h>
using namespace std ;
#define ll long long
const int N = 2e6 + 5 ;
int c, t ;
int n, k, p[N] ;
vector <int> adj[N] ;
int maxn, sum ;
void dfs (int u, int fa, int s) {
    if (p[u] == 1) {
        maxn = max (maxn, s) ;
    }
    for (auto v : adj[u]) {
        if (v == fa) continue ;
        dfs (v, u, s + 1) ;
    }
}
signed main () {
    freopen ("hub.in", "r", stdin) ;
    freopen ("hub.out", "w", stdout) ;
    cin >> c >> t ;
    while (t --) {
        cin >> n >> k ;
        for (int i = 2; i <= n; i ++) {
            int u, v ; cin >> u >> v ;
            adj[u] . push_back (v) ;
            adj[v] . push_back (u) ;
            p[u] ++ ;
            p[v] ++ ;
        }
        for (int i = 1; i <= n; i ++) {
            if (p[i] == 1) {
                dfs (i, 0, 0) ;
                break ;
            }
        }
        cout << ceil (maxn * 1.0 / k) << "\n" ;
    }
}

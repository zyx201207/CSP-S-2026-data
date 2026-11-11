#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c, t, n, k, d[1005];
vector<int> e[1005];
void dfs(int x, int pre) {
    for (auto y : e[x])
        if (y != pre) {
            d[y] = d[x] + 1;
            dfs(y, x);
        }
}
void solve() {
    scanf("%d%d", &n, &k);
    memset(d, 0, sizeof(d));
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    printf("%d\n", (n - 1) / 3);
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for (; t--; )
        solve();
}

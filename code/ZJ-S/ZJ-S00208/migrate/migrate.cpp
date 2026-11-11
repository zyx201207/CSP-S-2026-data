#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int C, n, d, a[N], t[N], dep[N], to[N];
vector<int> e[N];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    for (int v : e[u]) {
        if (v == pre) continue;
        dfs(v, u);
    }
}
void solveB() {
    int id = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] - d <= a[1] && a[i] + d >= a[n]) {
            id = i; break;
        }
    } int ans = 0; int del = lower_bound(a + 1, a + n + 1, a[id - 1] + d) - a;
    for (int i = 1;i <= n;i ++) {
        if (a[i] + d <= a[id + 1]) ans += del;
    } int dell = lower_bound(a + 1, a + n + 1, a[id + 1] - d) - a;
    for (int i = n;i >= 1;i --) {
        if (a[i] - d >= a[id - 1]) ans += dell;
    } cout << ans << "\n";
}
void solveA() {
    int d = d / (a[2] - a[1]); int ans = (n / d) * (n / d - 1) / 2;
    cout << ans << "\n";
}
void solve() {
    cin >> n >> d;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    if (C == 13 || C == 14) {
        solveB(); return ;
    }
    if (C == 11 || C == 12) {
        solveA(); return ;
    }
    for (int i = 1;i <= n;i ++) {
        t[i] = lower_bound(a + 1, a + n + 1, a[i] + d) - a;
        e[i].push_back(t[i]); e[t[i]].push_back(i);
    }
    dfs(n, 0);
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T; cin >> C >> T;
    while (T --) solve();
}
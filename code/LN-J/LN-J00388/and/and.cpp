#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, sum, a[N];
long long ans;
set<int> s;
void dfs(int dep, int i) {
    if (dep > m || i > n) return;
    if (dep == m) {
        sum &= a[i];
        s.insert(sum);
        return;
    }
    dfs(dep + 1, i + 1);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) {
        sum = a[i];
        dfs(1, i);
    }
    for (auto i : s) {
        ans = max(ans, 1LL * i);
    }
    cout << ans << "\n";
    return 0;
}

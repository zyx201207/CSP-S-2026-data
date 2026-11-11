#include <bits/stdc++.h>
using namespace std;
int a[200005], n, m, ans=0, as[200005];
void dfs(int dep, int cal, int lst) {
    if (dep==m) {
        ans=max(ans,cal);
        //for (int i = 0; i < m; i++) cout << as[i] << ' ';
        //cout << cal << '\n';
        return;
    }
    for (int i=lst + 1;i<=n;i++) {
        if ((cal&a[i]) == 0) continue;
        as[dep] = a[i];
        dfs(dep + 1, (cal & a[i]), i);
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dfs(0, a[1], 0);
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], last[N], ans[N], sz[N];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        sz[i]++;
        ans[a[i]] += sz[i];
        sz[last[a[i]] + 1] += sz[i];
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << (i == m ? '\n' : ' ');
    return 0;
}

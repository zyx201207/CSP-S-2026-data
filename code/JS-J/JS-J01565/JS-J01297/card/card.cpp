#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[500005];
int to[500005];
int lst[300005];
int cnt[300005];
signed main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], lst[a[i]] = i;
    for (int i = 1; i <= n; i++) to[i] = lst[a[i]];
    for (int i = 1; i <= n; i++) {
        bool hv[300005];
        for (int j = 1; j <= m; j++) hv[j] = 0;
        for (int j = i; j <= n; ) {
            j = to[j];
            hv[a[j]] = 1;
            j++;
        }
        for (int j = 1; j <= m; j++) cnt[j] += hv[j];
    }
    for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
}

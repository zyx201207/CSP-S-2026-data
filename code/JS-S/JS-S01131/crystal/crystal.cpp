#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 5;
ll n, m;
ll a[maxn], sum[maxn], dis[maxn], sum2[maxn];
bool check(int x) {
    for (int i = x; i <= n; i++) {
        ll anssum = (x - 1)  * sum[i - 1] - sum2[i - 2] ;
        if (i - x - 1 >= 0) anssum += sum2[i - x - 1];
        //for (int j = 1;j <= x - 1; j++) {
        //    anssum += dis[i - x + j] * j;
        //}
        if (anssum <= m) return true;
    }
    return false;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
        dis[i] = a[i + 1] - a[i];
        //cout << "dis[" << i << "] = " << dis[i] << " ";
    }
    //cout << "\n";
    sum[0] = 0;
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + dis[i];
        //cout << "sum[" << i << "] = " << sum[i] << " ";
    }
    //cout << "\n";
    sum2[0] = 0;
    for (int i = 1; i < n; i++) sum2[i] = sum2[i - 1] + sum[i];
    ll l = 1, r = n, mid, ans = 1;
    while (l <= r) {
        mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}

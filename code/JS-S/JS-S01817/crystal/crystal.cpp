#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 10;
ll n, m, a[maxn], ans, diff[maxn], tmp[maxn], sum[maxn];
ll res(ll a, ll b) {
    return sum[b] - sum[a - 1] - (tmp[b] - tmp[a - 1]) * (a - 1);
}
ll nex(ll x) {
    int temp = upper_bound(a + 1, a + n + 1, a[x + 1]) - a;
    if (a[temp - 1] == a[x]) return temp;
    else return temp - 1;
}
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = a[1] - 1;
    a[n + 1] = a[n];
    bool flag = true;
    for (ll i = 1; i <= n; i++) {
        diff[i] = a[i] - a[i - 1];
        tmp[i] = tmp[i - 1] + diff[i];
        sum[i] = sum[i - 1] + diff[i] * (i - 1);
        if (i > 1 && diff[i] != diff[i - 1]) flag = false;
    }
    if (flag) {
        for (ll i = nex(0); i <= n; i = nex(i)) {
            if (res(1, i) <= m) {
                ans = max(ans, i);
                continue;
            }
            ll j;
            for (j = i; j >= 1; j--) {
                if (res(j, i) > m) break;
            }
            ans = max(ans, i - j);
            break;
        }
        cout << ans;
        return 0;
    }
    for (ll i = nex(0); i <= n; i = nex(i)) {
        if (res(1, i) <= m) {
            ans = max(ans, i);
            continue;
        }
        ll j;
        for (j = i; j >= 1; j--) {
            if (res(j, i) > m) break;
        }
        ans = max(ans, i - j);
    }
    cout << ans;
    return 0;
}

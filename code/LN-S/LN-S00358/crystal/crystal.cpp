#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 7;
ll n, m;
ll ans;
ll a[N], d[N], s[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1;i < n;++i) {
        d[i] = a[i + 1] - a[i];
    }
    for(int i = n - 1;i >= 1;--i) {
        d[i] += d[i + 1];
    }
    for(int i = 1;i < n;++i) {
        s[i] = s[i - 1] + d[i];
    }
    for(int i = 1;i <= n;++i) {
        ll sum = s[i - 1] - (i - 1) * (a[n] - a[i]);
        if(m >= sum) ans = max(ans, 1ll * i);
        else {
            ll l = 1, r = i - 1;
            while(l <= r) {
                ll mid = (l + r) >> 1;
                ll num = (s[i - 1] - s[mid]) - (i - 1 - mid) * (a[n] - a[i]);
                if(m >= num) {
                    ans = max(ans, i - mid);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

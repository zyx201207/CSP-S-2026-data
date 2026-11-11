#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500010], s[500010];

ll n, m;
ll ans2(ll n) {
    ll l = 1, r = n;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll len = n - mid + 1;
        ll val = a[n] * len - (s[n] - s[mid - 1]);
        if (val > m) l = mid + 1;
        else r = mid;
    }
    return n - l + 1;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, ans2(i));
    cout << ans;
    return 0;
}

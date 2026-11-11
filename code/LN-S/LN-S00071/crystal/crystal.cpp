#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll m;
ll a[500010];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 2 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = 0;
    }
    if (flag) {
        ll d = a[2] - a[1];
        if (d < 0) d = -d;
        int ans;
        for (ll i = 1; i <= n; i++)
            if (i * (i - 1) / 2 * d <= m) ans = i;
        cout << ans;
    }
    else {
        sort(a + 1, a + n + 1);
        int ans;
        for (int len = 1; len <= n; len++) {
            ll mn = 0x3f3f3f3f3f3f3f3f;
            for (int i = n; i >= len; i--) {
                ll sum = 0;
                for (int j = i - len + 1; j < i; j++) sum += a[i] - a[j];
                mn = min(mn, sum);
            }
            if (mn <= m) ans = len;
        }
        cout << ans;
    }
    return 0;
}


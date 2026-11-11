#include <bits/stdc++.h>
// Chinese Can Fly !!!!!!!!
using namespace std;

typedef long long ll;
typedef long double ld;

ll n, m, a[2000010];


int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + 1 + n);
    ll ans = 1, sum = 0;
    ll l = 1;
    for (int i = 1; i <= n; i++) {
        sum = sum + a[i];
        while (l < i && (i - l + 1) * a[i] - sum > m) {
            sum -= a[l];
            l++;
        }
        if ((i - l + 1) * a[i] - sum <= m) ans = max(i - l + 1, ans);
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n; ll m;
vector<ll> a(n + 1);

ll f(ll x) {
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; i++) b[i] = x - a[i];
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= n; i++) {
        if (b[i] > 0 && m >= b[i]) m -= b[i], b[i] = 0;
        if (b[i] <= 0) continue;
        if (m < b[i]) break;
    }
    ll ans1 = 0;
    for (int i = 1; i <= n; i++) if (b[i] == 0) ans1++;
    return ans1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll x = 0;
    ll ans = 0; int y = n;
    sort(a.begin() + 1, a.end());
    while (y--) x++, ans = max(f(a[x]), ans);
    cout << ans << '\n';
    return 0;
}

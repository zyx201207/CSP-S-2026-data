#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005];
signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    ll m;cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 1;
    ll sum = 0;
    int mx = 0;
    for (int r = 1; r <= n; r++) {
        ll d = a[r] - a[r - 1];
        sum += d * (r - l);
        while (sum > m) {
            sum -= a[r] - a[l];
            l++;
        }
        mx = max(mx, r - l + 1);
    }
    cout << mx;
    return 0;
}
/*
\sum abs(x-ai)>=m



*/
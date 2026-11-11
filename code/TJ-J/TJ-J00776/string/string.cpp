#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10;
int n;
ll a[N], sa[N], b[N], sb[N];
char ca[N], cb[N];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> ca[i];
        sa[i] = sa[i - 1] + a[i];
    }
    memcpy(b, a, sizeof(a));
    reverse(b + 1, b + n + 1);
    memcpy(cb, ca, sizeof(ca));
    reverse(cb + 1, cb + n + 1);
    for (int i = 1; i <= n; i++) {
        sb[i] = sb[i - 1] + b[i];
    }
    ll len = sa[n] / 2, ans = 0;
    int i = 1, j = 1, li = 0, lj = 0;
    while (sa[i - 1] + li < len) {
        int rest = min(len - sa[i - 1] - li, (ll)min(a[i] - li, b[j] - lj));
        if (ca[i] != cb[j]) ans += rest;
        li += rest;
        lj += rest;
        if (li == a[i]) i++, li = 0;
        if (lj == b[j]) j++, lj = 0;
    }
    cout << ans << '\n';
    return 0;
}

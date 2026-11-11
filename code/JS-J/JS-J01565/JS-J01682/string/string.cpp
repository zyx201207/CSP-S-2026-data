#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
ll n, a[N], c[N], l, r, la, lc, ra, rc, ans;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1;i <= n;i++) {
        char _c;
        cin >> a[i] >> _c;
        c[i] = (ll)(_c - 'a');
    }
    l = 1; r = n;
    la = a[1]; ra = a[n];
    lc = c[1]; rc = c[n];
    while(l < r) {
        ans += (lc != rc) * min(la, ra);
        if(la < ra) ra -= la, l++, la = a[l], lc = c[l];
        else if(la == ra) {
            ra -= la, l++, la = a[l], lc = c[l];
            la -= ra, r--, ra = a[r], rc = c[r];
        }
        else la -= ra, r--, ra = a[r], rc = c[r];
    }
    cout << ans << endl;
    return 0;
}

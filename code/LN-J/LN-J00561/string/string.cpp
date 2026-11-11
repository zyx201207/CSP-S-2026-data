#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[200005];
char c[200005];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n; cin >> n;
    ll len = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        len += a[i];
    }
    ll r = n, cnt = 0;
    ll ans = 0;
    for (int l = 1; l < r; l++) {
        while ((a[l] >= a[r] - cnt) && l < r) {
            a[l] -= (a[r] - cnt);
            if (c[l] == c[r]) {
                cnt = 0;
                r--;
            }
            else {
                ans += (a[r] - cnt);
                cnt = 0;
                r--;
            }
        }
        if (l == r) break;
        if (c[l] == c[r]) {
            cnt += a[l];
        }
        else {
            ans += a[l];
            cnt += a[l];
        }
    }
    cout << ans << endl;
    return 0;
}

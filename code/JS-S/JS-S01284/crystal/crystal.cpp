#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 10;
ll n, m, a[N], sum, ans = 1;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll l = 1, add = 0;
    for (ll r = 2; r <= n; r++) {
        ll t = (r-l) * (a[r]-a[r-1]);
        add += a[r] - a[r-1];
        sum += t;
        while (sum > m) {
            sum -= add;
            add -= a[l + 1] - a[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
    return 0;
}

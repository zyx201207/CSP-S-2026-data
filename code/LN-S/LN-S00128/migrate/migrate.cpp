#include <bits/stdc++.h>
using ll = long long;
constexpr int N = 2e6 + 5;
ll a[N];
ll nex[N], pre[N];
bool check(std::vector < ll > &x, std::vector < ll > &y) {
    if (x.size() != y.size()) return 0;
    ll ans = 0;
    for (ll i = 0; i < x.size(); i++) if (x[i] != y[i]) ans++;
    return ans == 1; 
}
void solve()
{
    ll n, d; std::cin >> n >> d;
    for (ll i = 1; i <= n; i++) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    ll r = 1;
    for (ll l = 1; l <= n; l++) {
        while (r < n && a[r + 1] - a[l] <= d) r++;
        nex[l] = r;
    }
    ll l = n;
    for (ll r = n; r >= 1; r--) {
        while (l > 1 && a[r] - a[l - 1] <= d) l--;
        pre[r] = l;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 2; j <= n; j++) {
            std::vector < ll > fwd, bwd;
            bool f = 0;
            for (ll k = i; k < j; k = nex[k]) {
                fwd.push_back(k);
                if (k != j && nex[k] == k) { f = 1; break; }
            }
            fwd.push_back(j);
            for (ll k = j; k > i; k = pre[k]) {
                bwd.push_back(k);
                if (k != i && pre[k] == k) { f = 1; break; }
            }
            if (f) break;
            bwd.push_back(i);
            std::reverse(bwd.begin(), bwd.end());
            if (check(fwd, bwd)) ans++;
        }
    }
    std::cout << ans << std::endl;
    for (ll i = 1; i <= n; i++) a[i] = nex[i] = pre[i] = 0;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t; std::cin >> c >> t;
    while (t--) solve();
}
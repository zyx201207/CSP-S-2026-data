#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T>
using vec = vector<T>;

const int C = 2e6 + 5;

int n, d;
ll x[C], f[C][3];

void solve() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &x[i]);
    int ans = 0;
    ll sum = 0;
    for (int l = n, r = n; l >= 1; l--) {
        while (x[r] - x[l] > d) {
            sum -= f[r][1], r--;
        }
        
        f[l][1] = r - l;
        cout << f[l][1] << '\n';
        sum += f[l][1];
    }
    cout << ans << '\n';
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    int c, t;
    scanf("%d %d", &c, &t);
    while (t--) {
        solve();
    }

    return 0;
}
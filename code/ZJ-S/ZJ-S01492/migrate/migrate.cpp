#include<bits/stdc++.h>
#define int long long
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 2e6 + 5, M = 5005;
int c, T, n, d, a[N];
void solve1() {
    int ans = 0;
    rep(l, n) {
        vector<int> f, g, sum;
        f = g = sum = vector<int>(n + 5, 0ll);
        sum[l] = g[l] = 1;
        int i = l, j = l;
        Rep(r, l + 1, n) {
            if(a[r] - a[r - 1] > d) break;
            while(i < r && a[r] - a[i] > d) i++;
            while(j < r - 1 && f[j + 1] <= f[i]) j++;
            f[r] = f[i] + 1;
            g[r] = min(3ll, sum[j] - sum[i - 1]);
            sum[r] = sum[r - 1] + g[r];
            if(g[r] == 2) ans++;
        }
        // Rep(i, l, n) cout << i << ':' << f[i] << ' ' << g[i] << '\n';
    }
    cout << ans << '\n';
}
void solve2() {
    // cout << d << ' ' << a[2] - a[1] << '\n';
    int x = a[2] - a[1];
    if(d <= x) return  cout << "0\n", void();
    int y = (d / x) * 2 - 1;
    if(y >= n || y == 1) return cout << "0\n", void();
    cout << n - y << '\n';
}
void solve3() { // ?
    int i = 1, ans = 0;
    rep(l, n) {
        while(i < n && a[i + 1] - a[l] <= d) i++;
        if(i == n) break;
        if(i - l < 3) continue; 
        if(a[n] - a[i - 1] <= d && a[n] - a[i - 2] > d) ans++;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> T;
    while(T--) {
        cin >> n >> d;
        rep(i, n) cin >> a[i];
        if(c <= 10) solve1();
        else if(c == 11 || c == 12) solve2();
        else if(c == 13 || c == 14) solve3();
    }
    return 0;
}

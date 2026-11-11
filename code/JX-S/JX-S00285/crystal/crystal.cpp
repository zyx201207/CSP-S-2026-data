#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define File
#define FileName "crystal"

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

void solve();

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef File
    freopen(FileName ".in", "r" ,stdin);
    freopen(FileName ".out", "w", stdout);
#endif // File
    int T = 1;
    while(T--) solve();
    return 0;
}

const int MAXN = 5e5 + 10;

ll n, m;
ll a[MAXN];
ll d[MAXN];

int ans = 1;

void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i, 1, n) d[i] = a[i] - a[i - 1];
    ll used = 0;
    for(int i = 1, j = 2; j <= n; j++) {
        used += (a[j] - a[j - 1]) * (j - i);
        while (used > m && i <= j) used -= a[j] - a[i++];
        if (i == j) j ++;
        ans = max(ans, j - i + 1);
    }
    cout << ans << '\n';
}

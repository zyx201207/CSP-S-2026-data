#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

#define File
#define FileName "and"

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
#ifdef File
    freopen(FileName ".in", "r", stdin);
    freopen(FileName ".out", "w", stdout);
#endif
    int T = 1;
    while(T--) solve();
    return 0;
}

const int MAXN = 2e5 + 10;
const int BITS = 30;

int n, m;
int a[MAXN];

int res = 0;

void dfs(int i,int l ,int ans) {
    if (i == n) return ;
    if (l == m) res = max(res, ans == 0xFFFFFFFF ? 0 : ans);
    dfs(i + 1, l + 1, ans & a[i]);
    dfs(i + 1, l, ans);
}

void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    dfs(1,0, 0xFFFFFFFF);
    cout << res << "\n";

}

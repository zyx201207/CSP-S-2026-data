#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

#define File
#define FileName "card"

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

const int MAXN = 5e5 + 10;
const int MAXM = 3e5 + 10;

int n, m;
int a[MAXN];
bool v[MAXM];
int stk[MAXN], tp = 0;
int ans[MAXM];

void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i], ans[a[i]] += i;
    rrep(i, 1, n) {
        if (v[a[i]]) {
            while(tp && stk[tp + 1] != a[i])
                v[stk[tp]] = 0, ans[stk[tp--]] -= i;
        }
        stk[++tp] = a[i];
        v[a[i]] = 1;
    }

    rep(i, 1, m) cout << ans[i] << " ";
}

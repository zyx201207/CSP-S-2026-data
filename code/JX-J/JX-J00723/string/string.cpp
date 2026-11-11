#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

#define File
#define FileName "string"

void solve();

const int MAXN = 2e5 + 10;

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

int a[MAXN];
char c[MAXN];
ll ans = 0;
int n;

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i] >> c[i];
    int i = 1, j = n;
    while(i < j) {
        int del = min(a[i], a[j]);
        if (c[i] != c[j]) ans += del;
        a[i] -= del;
        a[j] -= del;

        while (!a[i]) i++;
        while (!a[j]) j--;
    }
    cout << ans << "\n";
}

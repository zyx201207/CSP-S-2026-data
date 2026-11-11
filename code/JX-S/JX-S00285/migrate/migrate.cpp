#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using vecll = vector<ll>;

#define File
#define FileName "migrate4"

#define rep(i, s, t) for(int i = s; i <= t; i++)
#define rrep(i, s, t) for(int i = t; i >= s; i--)

void solve();

int Case;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef File
    freopen(FileName ".in", "r" ,stdin);
    freopen(FileName ".out", "w", stdout);
#endif // File
    int T = 1;
    cin >> Case >> T;
    while(T--) solve();
    return 0;
}

const int MAXN = 2e6 + 10;

ll n, d;
ll x[MAXN];
ll s[MAXN];

const int MAXN_A = 3010;
ll ans[MAXN_A][MAXN_A];

void solve() {
    cin >> n >> d;
    rep(i,1 ,n) cin >> x[i];
    rep(i,1 ,n) s[i] = x[i] - x[i - 1];
    if (Case == 11 || Case == 12) {
        int dx = s[2];
        int bx = d / dx;
        if (2 > bx || n % bx == 0) {cout << "0\n";}
        else if () {cout << n - 2 << '\n';}
        else
        return;
    } else if (Case == 13 || Case == 14) {

    } else if (15 <= Case&& Case <= 18) {

    }

    // F
    cout << 0 << '\n';
}

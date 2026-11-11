#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie(0) -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= (int)(r); i++)
#define R(i, r, l) for (int i = r; i >= (int)(l); i--)
#define rep(i, l, r) for (int i = l; i < (int)(r); i++)
#define per(i, r, l) for (int i = r - 1; i >= (int)(l); i--)
#define FileIO(name) \
    freopen(name ".in", "r", stdin); \
    freopen(name ".out", "w", stdout)

const int N = 5e5 + 5;

int n;
ll m, a[N];

int main() {
    FileIO("crystal");
    qio(), cin >> n >> m;
    L(i, 1, n) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll sum = 0;
    int ans = 0;
    for (int r = 1, l = 1; r <= n; r++) {
        sum += a[r];
        for (; a[r] * (r - l + 1) - sum > m; sum -= a[l++]);
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
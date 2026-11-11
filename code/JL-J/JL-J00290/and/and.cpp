#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 1e5 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

int a[N];

bool cmp(int x, int y) {
    return x > y;
}

void solve() {
    int n, m;
    cin >> n >> m >> a[1];
    int ys = a[1], mx = a[1];
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        ys &= a[i];
    }
    if (m == 1) {
        cout << mx;
        return ;
    }
    if (m == n) {
        cout << ys;
        return ;
    }
    int ans = -1;
    sort(a + 1, a + n + 1, cmp);
    int ab = a[1];
    for (int i = 1; i <= m; ++i) {
        ab &= a[i];
    }
    cout << ab;
    return ;
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--) solve();
    return 0;
}
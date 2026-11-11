#include <bits/stdc++.h>
#define int long long
using namespace std;

using lll = __int128;
const int N = 5e5;
int n, a [N + 5], m;
inline int mina (int &x, int y) { return x = min (x, y); }
inline int mari (int &x, int y) { return x = max (x, y); }
void Turn () {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++) cin >> a [i];
    sort (a + 1, a + n + 1);
    int l = 1, sum = 0, ans = 0;
    for (int i = 1 ; i <= n ; i ++) {
        sum += a [i];
        while ((lll) (i - l + 1) * a [i] - sum > m)
            sum -= a [l], l ++;
        mari (ans, i - l + 1);
    }
    cout << ans << endl;
}

int _; void Init () {
    ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
    _ = 1;
    freopen ("crystal.in", "r", stdin);
    freopen ("crystal.out", "w", stdout);
    // cin >> _;
}

    signed main () { Init ();
    while (_ --> 0)
    Turn (); return 0; }
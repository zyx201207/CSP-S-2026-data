#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define int long long

template<class T> inline void ckmin(T& x, T y) { if(x > y) x = y; }
template<class T> inline void ckmax(T& x, T y) { if(x < y) x = y; }
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
static constexpr int N = 5e5 + 5;
int n, m;
int a[N];
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);

    // #ifdef LOCAL
    // freopen("samples/input.txt", "r", stdin);
    // freopen("samples/crystal4.in", "r", stdin);
    // freopen("samples/output.txt", "w", stdout);
    // #endif

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    
    int ans = 1;
    for(int i = 1, j = 1, s = 0; i <= n; i++) {
        if(i != 1) s += (a[i] - a[i - 1]) * (i - j);
        while(j < i && s > m) s -= a[i] - a[j], j++;
        ckmax(ans, i - j + 1);
    }
    cout << ans << '\n';

    // cerr << 1. * clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define fr(i, x, y) for (int i = (x); i <= (y); i ++)
using namespace std;

const int N = 1e6 + 5;
int n, m, a[N], s, ans;

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fr(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1;
    fr(r, 1, n){
        s += a[r];
        while ((r - l + 1) * a[r] - s > m) s -= a[l ++];
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}

// T1 has been finished at 14:52.
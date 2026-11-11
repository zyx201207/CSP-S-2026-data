#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int n, m, a[N], pre[N];

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];

    int res = 0;
    for (int i = 1; i <= n; i ++ ){
        int l = 1, r = i, ans = i + 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            int tmp = 1ll * a[i] * (i - mid + 1) - 1ll * (pre[i] - pre[mid - 1]);
            if (tmp <= m) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, i - ans + 1);
    }
    cout << res << "\n";
}
// 0h n0 my dream
// lg 693638 * 2 + 1
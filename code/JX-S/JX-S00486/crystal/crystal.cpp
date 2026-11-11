#include <bits/stdc++.h>
#define int long long
#define lc(x) ((x) << 1)
#define rc(x) (((x) << 1) ^ 1)
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int n, m, a[500005], pre[500005];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int l = 1, r = i, res = -1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (a[i] * (i - mid + 1) - (pre[i] - pre[mid - 1]) <= m) r = mid - 1, res = mid;
            else l = mid + 1;
        }
        if (res == -1) continue;
        ans = max(ans, i - res + 1);
    }
    cout << ans << "\n";
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, m, l, r, mid, res, ans = 1, a[N], pre[N];

inline int query(int l, int r) {
    return pre[r] - pre[l - 1];
}

inline bool check(int x, int pos) {
    if(a[pos] * (pos - x + 1) - query(x, pos) <= m) return true;
    else return false;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for(int i = 1 ; i <= n ; ++ i)
        pre[i] = pre[i - 1] + a[i];

    for(int i = 1 ; i <= n ; ++ i) {
        l = 1, r = i, res = 1e18;

        while(l <= r) {
            mid = (l + r) >> 1;

            if(check(mid, i)) r = mid - 1, res = mid;
            else l = mid + 1;
        }

        ans = max(ans, i - res + 1);
    }

    cout << ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a[200005], ans = -1;
bool A = 1, B = 1;

void dfs(int lstid, int res, int sx) {
    if(sx == 0) {
        ans = max(ans, res);
        return;
    }
    if(sx > n - lstid)
        return;
    if(ans > res)
        return;
    if(res == 0)
        return;
    for(int i = lstid + 1 ; i <= n ; i++) {
        dfs(i, res & a[i], sx - 1);
    }
}

signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if(n & (n - 1) != 0)
        B = 0;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if(a[i] & (a[i] + 1) != 0)
            A = 0;
        if(a[i] != i - 1)
            B = 0;
    }
    if(n <= 20) {
        // bao li
        dfs(0, (1 << 32) - 1, m);
        if(ans != -1) cout << ans << endl;
        else cout << 0 << endl;
    } else if(m == n) {
        int k = a[1];
        for(int i = 2 ; i <= n ; i++) {
            k = k & a[i];
        }
        cout << k << endl;
    } else if(m == 1) {
        int k = -1;
        for(int i = 1 ; i <= n ; i++) {
            if(a[i] > k)
                k = a[i];
        }
        cout << k << endl;
    } else if(m == 2) {
        // bao li
        dfs(0, (1 << 32) - 1, m);
        if(ans != -1) cout << ans << endl;
        else cout << 0 << endl;
    } else if(A) {
        sort(a + 1, a + n + 1, greater<int>());
        cout << a[m] << endl;
    } else if(B) {
        ans = a[n];
        for(int i = n - 1 ; i > n - m ; i--)
            ans &= a[i];
        cout << ans << endl;
    } else {
        // bao li
        dfs(0, (1 << 32) - 1, m);
        if(ans != -1) cout << ans << endl;
        else cout << 0 << endl;
    }
    return 0;
}

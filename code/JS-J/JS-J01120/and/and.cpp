#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, maxx = 0, ans = 0;
int a[200010], f[200010];
vector < int > cun;
/*
void dfs(int u, int cnt, int now) {
    cout << u << "  " << cnt << "  " << now << endl;
    if (cnt >= m) {
        ans = max(ans, now);
        return;
    }else if (u > n) {
        //ans = max(ans, now);
        return;
    }

    dfs(u + 1, cnt + 1, now & a[u]);
    dfs(u + 1, cnt, now);
}
*/
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin >> n >> m;
    int op = 1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        op &= a[i];
        maxx = max(maxx, a[i]);
    }
    if (n == m) {
        cout << op;
        return 0;
    }
    if (m == 1) {
        cout << maxx;
        return 0;
    }
    for (int i = n; n - i + 1 <= m; i --) {
        f[i] = 1;
    }
    //cout << (12 & 12) << endl;
   // dfs(1, 0, 111111111);
   ans = 0;
    do {
        int l = 0;
        bool flag = false;
        for (int i = 1; i <= n; i ++) {
           //     cout << f[i] << " ";
            if (f[i]) {
                if (!flag) l = a[i], flag = true;
                else l &= a[i];
            }
        }

     //   cout << l << endl;
      // cout << endl;
        ans = max(ans, l);
    } while (next_permutation(f + 1, f + n + 1));
    cout << ans;
    return 0;
}

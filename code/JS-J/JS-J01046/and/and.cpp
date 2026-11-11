#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 7;
int n,m,tot;
int a[MAXN];
void dfs(int now, int l, int ans) {
    if (l == 0) {
        //cout << "Final: " << ans << endl;
        tot = max(tot, ans);
        return;
    }
    if (now == n + 1) return;

    //cout << "------" << endl;
    //cout << now << ' ' << l << ' '<< ans << endl;
    //cout << a[now] << " " << ans << endl;
    dfs(now + 1, l, ans);
    if (l == 2) {
        dfs(now + 1, l - 1, a[now]);
    } else {
        dfs(now + 1, l - 1, (ans&a[now]));
    }



}
signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == 1) {
        sort(a + 1, a + 1 + n);
        cout << a[n] << endl;
        return 0;
    }
    if (m == 2) {
        int ANS = 0;
        for (int i = 1; i <=n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ANS = max(ANS, (a[i]&a[j]));
            }
        }
        cout << ANS << endl;
        return 0;
    }
    if (m == n) {
        int ANA = 0;
        for (int i = 1; i <= n; i++) {
            ANA = (ANA & a[i]);
        }
        cout << ANA << endl;
        return 0;
    }
    if (n <= 20) {
        dfs(1,m,1);
        cout << tot << endl;
        return 0;
    }

    return 0;
}
/*
*/

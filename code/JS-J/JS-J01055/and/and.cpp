#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N], ans;
void dfs(int dep, int cnt, int sum) {
    if (cnt > m) return ;
    if (dep == n + 1) {
        if (cnt == m) {
            ans = max(ans, sum);
        }
        return ;
    }
    if (cnt == m) {
        ans = max(ans, sum);
        return ;
    }
    dfs(dep + 1, cnt, sum);
    dfs(dep + 1, cnt + 1, sum & a[dep]);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int flag1 = 1, flag2 = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] & (a[i] + 1)) {
            flag1 = 0;
        }
        if (a[i] >= 4) {
            flag2 = 0;
        }
    }
    if (flag1) {
        sort(a + 1, a + n + 1);
        ans = a[n - m + 1];
    }else if (flag2) {
        sort(a + 1, a + n + 1);
        if (a[n - m + 1] > 1) {
            ans = a[n - m + 1];
        } else {
            int pos = lower_bound(a + 1, a + n + 1, 1) - a;
            if (pos <= n) {
                ans = a[pos + m - 1] == 1;
            } else {
                ans = 0;
            }
        }
    } else if (m == n - 1) {
        int pre[N], suf[N];
        pre[0] = suf[n + 1] = INT_MAX;
        for (int i = 1, j = n; i <= n; ++i, --j) {
            pre[i] = pre[i - 1] & a[i];
            suf[j] = suf[j + 1] & a[j];
        }
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, pre[i - 1] & suf[i + 1]);
        }
    } else {
        dfs(1, 0, INT_MAX);
    }
    cout << ans;
    return 0;
}

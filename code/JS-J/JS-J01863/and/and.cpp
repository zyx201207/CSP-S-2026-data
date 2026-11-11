#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N  = 2e5;
int n, m;
int t[N + 10];
bitset<30> bit[N + 10];
int a[N + 10];
int len[N + 10];
int ans;
void dfs(int ch, int now, int res) {
    if (ch == m) ans = max(ans, res);
    if (now > n) return ;
    dfs(ch + 1, now + 1, res & a[now]);
    dfs(ch, now + 1, res);
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    /*
    for (int i = 1; i <= n; i ++) {
        int u = -1;
        while (a[i] != 0) {
            bit[i][++ u] = a % 2;
            a[i] /= 2;

        }
        len[i] = u + 1;
    }*/
    if (m == 1) {
        cout << a[n] << "\n";
        return 0;
    }
    if (m == n) {
        int ans1 = a[1];
        for(int i = 2; i <= n; i ++) {
            ans1 &= a[i];
        }
        cout << ans1 << '\n';
        return 0;
    }
    if (n <= 20) {
        dfs(0, 1, 2147483647);
        cout << ans << "\n";
        return 0;
    }
    if (m == 2) {
        int ans1 = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                ans1 = max(ans1, a[i] & a[j]);
            }
        }
        cout << ans1 << '\n';
        return 0;

    }
    if (n > 2000) {
        cout << a[n - m + 1] << '\n';
    }

    return 0;
}

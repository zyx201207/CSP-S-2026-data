#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], m, ans0;
bool vis[N];
bool cmp (int a, int b) {
    return a > b;
}
int s[35];
int main() {
    freopen ("add.in", "r", stdin);
    freopen ("add.out", "w", stdout);
    cin >> n >> m >> a[1];
    int sum = a[1], maxn = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        sum = sum & a[i];
        maxn = max(maxn, a[i]);
    }
    if (m == n) {
        cout << sum << endl;
        return 0;
    }
    if (m == 1) {
        cout << maxn << endl;
        return 0;
    }
    if (m == 2) {
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                ans = max(ans, (a[i] & a[j]));
            }
        }
        cout << ans << endl;
        return 0;
    }
    s[1] = 1;
    for (int i = 2; i <= 30; i++) s[i] = (s[i - 1] + 1) * 2 - 1;
    sort (a + 1, a + n + 1, cmp);
    bool flag = false;
    for (int i = 1; i <= 30; i++) {
        if (a[m] == s[i]) flag = true;
    }
    if (flag) cout << a[m] << endl;
    else cout << 0 << endl;
    return 0;
}
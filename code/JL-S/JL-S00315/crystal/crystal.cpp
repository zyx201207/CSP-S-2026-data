#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
int a[500010];
int b[500010];
int cnt;

signed main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    while (m > 0) {
        int ans = 0;
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++) {
            b[a[i]]++;
            ans = max(ans, b[a[i]]);
        }
        if (ans != n) {
            cnt = max(cnt, ans);
        }
        a[1]++;
        sort(a + 1, a + 1 + n);
        m--;
    }
    int ans = 0;
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
        b[a[i]]++;
        ans = max(ans, b[a[i]]);
    }
    cnt = max(cnt, ans);
    cout << cnt;
    return 0;
}

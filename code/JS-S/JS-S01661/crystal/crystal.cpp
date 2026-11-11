#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], cnt1[500005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    bool f1 = 1, f2 = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int del = 0;
    for (int i = 1; i <= n; i++) {
        cnt1[i] = cnt1[i - 1] + (i - 1) * (a[i] - a[i - 1]);
        if (a[i] - a[i - 1] != 1) f1 = 0;
        if (i == 2) del = a[i] - a[i - 1];
        else if (i >= 3 && (a[i] - a[i - 1] != del)) f2 = 0;
    }
    int ans = 0;
    if (f1 || f2) {
        for (int i = n; i >= 1; i--) {
            ans += (a[n] - a[i]);
            if (ans > m) {
                cout << n - i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        int ans1 = 1;
        if (cnt1[i] <= m) {
            ans = max(ans, i);
            continue;
        }
        int cnt = cnt1[i];
        for (int j = 1; j < i; j++) {
            cnt = cnt - (a[i] - a[j]);
            if (cnt <= m) {
                ans1 = i - j;
                break;
            }
        }
        ans = max(ans, ans1);
    }
    cout << ans;
    return 0;
}

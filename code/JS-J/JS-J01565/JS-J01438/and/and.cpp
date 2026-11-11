#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int b[N];
int n, m;
int mx = 0;

void dfs(int now, int cnt, int val) {
    if (cnt == m) {
        mx = max(mx, val);
        return;
    }
    if (now > n) {
        return;
    }
    dfs(now + 1, cnt, val);
    dfs(now + 1, cnt + 1, val & a[now]);
}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == n) {
        long long ans = a[1];
        for (int i = 2; i <= n; i++) {
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    if (m == 1) {
        int ans = a[1];
        for (int i = 2; i <= n; i++) {
            ans = max(ans, a[i]);
        }
        cout << ans;
        return 0;
    }
    if (m == 2 && n <= 2000) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if (n <= 20) {
        dfs(1, 0, (1 << 21) - 1);
        cout << mx;
        return 0;
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if ((1 << __lg(a[i] + 1)) == a[i] + 1) {
            b[i] = __lg(a[i] + 1);
        } else {
            f = 1;
        }
    }
    if (f == 0) {
        sort(b + 1, b + n + 1, greater<int>());
        int ans = (1 << b[m]) - 1;
        cout << ans;
        return 0;
    }
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cnt0++;
        } else if (a[i] == 1) {
            cnt1++;
        } else if (a[i] == 2) {
            cnt2++;
        } else if (a[i] == 3) {
            cnt3++;
        }
    }
    if (m <= cnt2 + cnt3) {
        cout << 2;
        return 0;
    }
    if (m <= cnt1 + cnt3) {
        cout << 1;
        return 0;
    }
    cout << 0;

    return 0;
}

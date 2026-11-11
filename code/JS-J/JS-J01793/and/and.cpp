#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], vis[N];
int dfs(int x, int now, int cnt) {
    if (x == n + 1) {
        if (cnt == m) return now;
        else return -1;
    }
    int chosen1 = dfs(x + 1, now, cnt);
    int chosen2 = -1;
    if (vis[x] == 0) {
        vis[x] = 1;
        chosen2 = dfs(x + 1, now & a[x], cnt + 1);
        vis[x] = 0;
    }
    return max(chosen1, chosen2);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int maxn = -1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if (m == 1) {
        int maxn = -1;
        for (int i = 1; i <= n; i++) {
            maxn = max(maxn, a[i]);
        }
        cout << maxn << endl;
        return 0;
    }
    if (m == n) {
        int ans = a[1];
        for (int i = 2; i <= n; i++) {
            ans &= a[i];
        }
        cout << ans << endl;
        return 0;
    }
    if (m == 2) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    ans = max(ans, a[i] & a[j]);
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    if (m == n - 1) {
        sort(a + 1, a + n + 1);
        int ans = a[2];
        for (int i = 3; i <= n; i++) {
            ans &= a[i];
        }
        cout << ans << endl;
    }
    if (maxn <= 4) {
        int cnt4 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 4) cnt4++;
        }
        if (cnt4 >= m) {
            cout << 4 << endl;
        }
        else {
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) cnt1++;
                if (a[i] == 2) cnt2++;
                if (a[i] == 3) cnt3++;
            }
            if (cnt3 >= m) {
                cout << 3 << endl;
            }
        }
        return 0;
    }
    if (n <= 20) {
        cout << dfs(1, a[1], 0) << endl;
        return 0;
    }
    sort(a + 1, a + n + 1);
    int ans = a[n - m + 1];
    for (int i = n - m + 1; i <= n; i++) {
        ans &= a[i];
    }
    cout << ans << endl;
    return 0;
}

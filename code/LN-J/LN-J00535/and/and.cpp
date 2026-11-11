#include<bits/stdc++.h>;
using namespace std;
int n, m;
int a[200010], ans = -1;
void dfs(int cnt, int k, int sum) {
    if (cnt == m) {
        ans = max(ans, sum);
        return ;
    }
    for (int i = k; i <= n; i++) dfs(cnt + 1, i + 1, sum & a[i]);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    bool flag1 = 1, flag2 = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != i - 1) flag1 = 0;
        if (a[i] > 4) flag2 = 0;
    }
    if (n <= 20) {
        dfs(0, 1, 0x7fffffff);
        cout << ans;
    }
    else if(m == 1) {
        for (int i = 1; i <= n; i++) ans = max(ans, a[i]);
        cout << ans;
    }
    else if (m == n) {
        ans = 0x7fffffff;
        for (int i = 1; i <= n; i++) ans &= a[i];
        cout << ans;
    }
    else if(m == 2) {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
        cout << ans;
    }
    else if (flag1) cout << n - m;
    else if (flag2) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) cnt1++;
            if (a[i] == 2) cnt2++;
            if (a[i] == 3) cnt3++;
            if (a[i] == 4) cnt4++;
        }
        if (m <= cnt4) cout << 4;
        else if (m <= cnt3) cout << 3;
        else if (m <= cnt2 + cnt3) cout << 2;
        else if (m <= cnt1 + cnt3) cout << 1;
        else cout << 0;
    }
    else {
        sort(a + 1, a + n + 1);
        ans = 0x7fffffff;
        for (int i = n; i >= n - m + 1; i--) ans &= a[i];
        cout << ans;
    }
    return 0;
}

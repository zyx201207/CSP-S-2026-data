#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a[500010], ans = -0x3f3f3f3f3f3f3f3f;
void solveAB() {
    int sum = 0, cnt = 0, c = a[2] - a[1];
    for (int i = 0; ; i++) {
        sum += i * c;
        if (sum > m or cnt >= n) break;
        cnt++;
    }
    cout << cnt;
    return;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    bool AB = true;
    int c = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    stable_sort(a + 1, a + n + 1);
    c = a[2] - a[1];
    for (int i = 2; i <= n; i++) {
        if (c != (a[i] - a[i - 1])) AB = false;
    }
    if (AB) {
        solveAB();
        return 0;
    }
    if (n <= 5000) {
    for (int i = 1; i <= n; i++) {
        ll cnt = 0, s = 0;
        for (int j = i; j >= 1; j--) {
            s += (a[i] - a[j]);
            if (s > m) break;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    }
    else {
    ll sum = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        ll cnt = 1;
        sum += (a[i] - a[i - 1]) * (i - 1);
        if (sum > 2 * m) break;
        ll s = sum;
        bool flag = false;
        while (s > m and cnt <= i) {
            flag = true;
            if (i - cnt < ans) break;
            s -= (a[i] - a[cnt]);
            cnt++;
        }
        if (flag) cnt--;
        ans = max(ans, i - cnt);
    }
    cout << ans;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll n, m, ans = LONG_LONG_MAX, ansn, sum = 0;
ll a[N], d[N];
bool flag = true;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(i >= 3 && a[i - 1] * 2 != a[i - 2] + a[i]) flag = false;
        if(i >= 2) d[i] = a[i] - a[i - 1];
    }
    sort(a + 1, a + n + 1);
    ll cnt = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] == a[i - 1]) cnt++;
        else cnt = 1;
        sum = max(sum, cnt);
    }
    if(m == 0) {
        if(sum > 1) cout << sum;
        else cout << 0;
        return 0;
    }
    if(flag) {
        if(d[2] == 0 || m >= (n - 1) * n / 2 * d[2]) {
            cout << n;
            return 0;
        } else if(m < d[2]) {
            cout << 0;
            return 0;
        } else {
            ll cnt = 1, sum = 0;
            for(;;) {
                sum = ((1 + cnt) * cnt / 2) * d[2];
                if(sum > m) break;
                cnt++;
            }
            cout << cnt;
        }
    } else {
        for(int i = 1; i < n; i++) {
            d[i] = d[i + 1] - d[i];
        }
        for(int cnt = 1; cnt < n; cnt++) {
            for(int i = 1; i <= n - cnt; i++) {
                for(int j = i; j <= i + cnt - 1; j++) {
                    sum += a[j] * (j - i + 1);
                }
                ans = min(ans, sum);
                sum = 0;
            }
            if(ans <= m) {
                ansn = cnt + 1;
                ans = LONG_LONG_MAX;
            } else {
                cout << ansn;
                return 0;
            }
        }
    }
    return 0;
}

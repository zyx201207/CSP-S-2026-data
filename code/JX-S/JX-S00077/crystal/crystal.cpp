#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m;
ll a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bool flag = true;
    int v;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        v = a[2] - a[1];
        if (a[i] - a[i - 1] != v) {
            flag = false;
        }
    }
    sort(a + 1, a + n + 1);
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    else if (flag) {
        ll sum = 0;
        ll val = a[2] - a[1];
        for (int i = 1; ; i++) {
            sum += i * val;
            if (sum > m && i != n + 1) {
                cout << i - 1 << '\n';
                return 0;
            }
            else if (sum > m && i == n + 1) {
                cout << n << '\n';
                return 0;
            }
        }
    }
    else {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            ll sum = 0;
            for (int j = 1; j <= i; j++) {
                sum += a[i] - a[j];
            }
            if (sum <= m) {
                ans++;
            }
            else {
                cout << ans << '\n';
                return 0;
            }
        }
    }
    return 0;
}
//wan dan le

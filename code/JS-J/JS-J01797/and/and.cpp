#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200010];
string s[200010];
bool cmp(ll x, ll y) {
    return x > y;
}
ll dfs(ll sum, ll cnt, ll i) {
    if (cnt == 0) {
        return sum;
    }
    if (i == n + 1) {
        return -1;
    }
    return max(dfs(sum & a[i], cnt - 1, i + 1), dfs(sum, cnt, i + 1));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    bool check1 = true;
    ll mx = -1, sum = 2147483637;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum &= a[i];
        mx = max(mx, a[i]);
    }
    if (m == n) {
        cout << sum;
        return 0;
    }
    if (m == 1) {
        cout << mx;
        return 0;
    }
    if (m == n - 1) {
        mx = -1;
        for (ll i = 1; i <= n; i++) {
            mx = max(mx, sum ^ a[i]);
        }
        cout << mx;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    ll mn = 1e18;
    for (ll i = 1; i <= n; i++) {
        ll tmp = a[i];
        if (i <= m) {
            mn = min(mn, a[i]);
        }
        while (tmp) {
            if (tmp % 2 == 0 && i <= m) {
                check1 = false;
            }
            s[i] += tmp % 2 + '0';
            tmp /= 2;
        }
    }
    if (check1) {
        cout << mn;
        return 0;
    }
    cout << dfs(2147483647, m, 1);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[500005];
ll dif[500005];
ll s[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        dif[i] = a[i] - a[i - 1];
    }
    dif[1] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + dif[i];
    }
    ll sum = 0, l = 1, r = 2, ans = 1;
    sum = dif[2];
    while (r <= n) {
        if (sum <= m) {
            ans = max(ans, r - l + 1);
            r++;
            sum = sum + dif[r] * (r - l);
        }
        else {
            l++;
            sum -= s[r] - s[l - 1];
        }
    }
    cout << ans;
    return 0;
}
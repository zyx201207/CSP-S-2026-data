#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 5;
ll n, m, a[N], s[N], ans;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i, p = 0;
        while(l <= r) {
            int t = (l + r) / 2;
            if(a[i] * (i - t) - (s[i - 1] - s[t - 1]) <= m) {
                //sum(t, ... , i - 1)
                p = t;
                r = t - 1;
            }
            else l = t + 1;
        }
        ans = max(ans, i - p + 1ll);
    }
    cout << ans;
    return 0;
}

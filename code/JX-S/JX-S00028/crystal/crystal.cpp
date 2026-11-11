#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5 + 5;
ll n, m, a[MAXN], ans;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int t = 1; t <= n; t ++) {
        ll maxx = 0;
        ll cnt[MAXN];
        ll x = m;
        for(int i = 1; i <= n; i ++) {
            cnt[i] = abs(a[i] - a[t]);
        }
        sort(cnt + 1, cnt + n + 1);
        for(int i = 2; i <= n; i ++) {
            if(x > 0) {
                maxx ++;
                x -= cnt[i];
            }
        }
        if(x != 0) maxx --;
        ans = max(ans, maxx);
    }
    cout << ans + 1;
    return 0;
}
